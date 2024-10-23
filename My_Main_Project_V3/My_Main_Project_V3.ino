

/**********************************************RGB + Swich Variables************************************************************/
static int32_t var__red_value = 0;
static int32_t var__green_value = 0;
static int32_t var__blue_value = 0;
bool var__swich_light1 = false;
bool var__swich_light2 = false;
bool var__swich_light3 = false;
bool var__swich_light4 = false;
/**********************************************WIFI Connection************************************************************/
#include <WiFi.h>
const char *wifiSSID = "TP-Link_BFF8";
const char *wifiPassword = "bCf33337123Ef";
unsigned long previousMillisCheckWiFi = 0;
const long intervalCheckWiFi = 5000;  // 5 seconds

/**********************************************Time Update************************************************************/
#include <WiFiUdp.h>
#include <NTPClient.h>
WiFiUDP udpInstance;
NTPClient ntpClient(udpInstance, "tr.pool.ntp.org", 10800, 60000);  // UTC timezone, 60-second update interval
unsigned long TimepreviousMillis = 0;                               // Stores the last time update
const long TimeintervalMillis = 1000;                               // Interval at which to update time (every 5 seconds)

/**********************************************Touchscreen and Screen************************************************************/
#include <lvgl.h>
#include "ui.h"
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "vars.h"

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33
SPIClass touchscreenSpi = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
uint16_t touchScreenMinimumX = 200, touchScreenMaximumX = 3700, touchScreenMinimumY = 240, touchScreenMaximumY = 3800;

/*Set to your screen resolution*/
#define TFT_HOR_RES 320
#define TFT_VER_RES 240

/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))

#if LV_USE_LOG != 0
void my_print(lv_log_level_t level, const char *buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}
#endif

/* LVGL calls it when a rendered image needs to copied to the display*/
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  /*Call it to tell LVGL you are ready*/
  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data) {
  if (touchscreen.touched()) {
    TS_Point p = touchscreen.getPoint();
    //Some very basic auto calibration so it doesn't go out of range
    if (p.x < touchScreenMinimumX) touchScreenMinimumX = p.x;
    if (p.x > touchScreenMaximumX) touchScreenMaximumX = p.x;
    if (p.y < touchScreenMinimumY) touchScreenMinimumY = p.y;
    if (p.y > touchScreenMaximumY) touchScreenMaximumY = p.y;
    //Map this to the pixel position
    data->point.x = map(p.x, touchScreenMinimumX, touchScreenMaximumX, 1, TFT_HOR_RES); /* Touchscreen X calibration */
    data->point.y = map(p.y, touchScreenMinimumY, touchScreenMaximumY, 1, TFT_VER_RES); /* Touchscreen Y calibration */
    data->state = LV_INDEV_STATE_PRESSED;
    /*
    Serial.print("Touch x ");
    Serial.print(data->point.x);
    Serial.print(" y ");
    Serial.println(data->point.y);
    */
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

lv_indev_t *indev;                     //Touchscreen input device
uint8_t *draw_buf;                     //draw_buf is allocated on heap otherwise the static area is too big on ESP32 at compile
uint32_t lastTick = 0;                 //Used to track the tick timer
unsigned long ScreeneviousMillis = 0;  // Stores the last screen update
const long ScreenintervalMillis = 50;

/**********************************************WiFi Connection Checking************************************************************/

void checkWiFiConnection() {
  unsigned long currentMillisCheckWiFi = millis();

  if (currentMillisCheckWiFi - previousMillisCheckWiFi >= intervalCheckWiFi) {
    previousMillisCheckWiFi = currentMillisCheckWiFi;

    if (WiFi.status() != WL_CONNECTED) {
      // Serial.println("Wi-Fi disconnected, attempting to reconnect...");
      WiFi.disconnect();
      WiFi.begin(wifiSSID, wifiPassword);
      lv_label_set_text(objects.label_main_screen_connection_status, "Connecting");

    } else {
      lv_label_set_text(objects.label_main_screen_connection_status, "Connected");
      // Serial.println("Wi-Fi connected");
    }
  }
}

/**********************************************Time Updating************************************************************/

void checkAndUpdateTime() {
  unsigned long TimecurrentMillis = millis();

  if (TimecurrentMillis - TimepreviousMillis >= TimeintervalMillis) {
    TimepreviousMillis = TimecurrentMillis;
    ntpClient.update();

    String formattedTime = ntpClient.getFormattedTime();

    int hours = formattedTime.substring(0, 2).toInt();
    int minutes = formattedTime.substring(3, 5).toInt();
    int seconds = formattedTime.substring(6, 8).toInt();

    // Convert to 12-hour format
    if (hours > 12) {
      hours -= 12;
    } else if (hours == 0) {
      hours = 12;  // Convert midnight hour 0 to 12
    }
    // Display the time in 12-hour format without AM/PM

    lv_label_set_text_fmt(objects.label_main_screen_time_hours, "%02d : %02d : %02d", hours, minutes, seconds);
  }
}



/*******************************************Wether info*******************************************************/
#include <HTTPClient.h>
#include <ArduinoJson.h>
String openWeatherMapApiKey = "602d57c2f646a23579b1940249e9dd5c";
String city = "Maltepe";
String countryCode = "TR";
unsigned long weatherLastTime = 0;         // Set weatherLastTime to a negative value to fetch data immediately
unsigned long weatherTimerDelay = 150000;  // 5 minutes in milliseconds
float temp_C = 0.0;
int humidity = 0;
float wind_speed_float = 0.0;
String sky_clearance = "";

// Flag to indicate initial fetch
bool initialWeatherFetchDone = false;

void updateWeather() {
  unsigned long currentMillis = millis();

  // Fetch immediately if this is the first call
  if (!initialWeatherFetchDone || (currentMillis - weatherLastTime >= weatherTimerDelay)) {
    // Construct the API URL for fetching weather data
    String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;

    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverPath);

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();

      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);

      // Parse and update weather data
      float tempKelvin = doc["main"]["temp"].as<float>();             // Get temperature in Kelvin
      temp_C = tempKelvin - 273.15;                                   // Convert to Celsius
      humidity = doc["main"]["humidity"].as<int>();                   // Get humidity
      wind_speed_float = doc["wind"]["speed"].as<float>();            // Get wind speed
      sky_clearance = doc["weather"][0]["description"].as<String>();  // Get sky condition description

      //Serial.print("Temperature: ");
      //Serial.print(temp_C);
      //Serial.println(" °C");

    } else {
      Serial.print("Error on HTTP request: ");
      Serial.println(httpResponseCode);
    }

    http.end();
    weatherLastTime = millis();      // Update the last time weather data was fetched
    initialWeatherFetchDone = true;  // Set the flag after the initial fetch
  }
}



// Using HardwareSerial (Serial1)
HardwareSerial mySerial(1);  // UART1 (Hardware Serial)

// Replace GPIOs with your actual TX and RX pins
#define TX_PIN 3
#define RX_PIN 1

unsigned long mySerial_PreviousMillis = 0;  // To store the last time data was sent
const long mySerial_Interval = 20;  // mySerial_Interval at which to send data (1 second)

int prev_red_value = -1;
int prev_green_value = -1;
int prev_blue_value = -1;


void Serial_Communication() {  
    unsigned long mySerial_CurrentMillis = millis();  // Get the current time

    // Check if 1 second has passed
    if (mySerial_CurrentMillis - mySerial_PreviousMillis >= mySerial_Interval) {
        mySerial_PreviousMillis = mySerial_CurrentMillis;

        // Generate random values for R, G, B between 0 and 255
        int current_red_value = get_var__red_value();
        int current_green_value = get_var__green_value();
        int current_blue_value = get_var__blue_value();

        // Check if any value has changed
        if (current_red_value != prev_red_value || 
            current_green_value != prev_green_value || 
            current_blue_value != prev_blue_value) {
            
            // Update previous values
            prev_red_value = current_red_value;
            prev_green_value = current_green_value;
            prev_blue_value = current_blue_value;

            // Send the RGB values via UART
            mySerial.print("R: ");
            mySerial.println(current_red_value);
            mySerial.print("G: ");
            mySerial.println(current_green_value);
            mySerial.print("B: ");
            mySerial.println(current_blue_value);
        }
    }
}

/**********************************************Cripto************************************************************/
const char* apiUrl = "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin,ethereum,solana&vs_currencies=usd&include_24hr_change=true";

unsigned long CriptopreviousMillis = 0;
const unsigned long Criptointerval = 5 * 60 * 1000;  // 5 minutes in milliseconds
bool CriptofirstRun = true;                          // Flag to check if it's the first run

float btcPrice = 0.0;
float btcChange = 0.0;
float ethPrice = 0.0;
float ethChange = 0.0;
float solPrice = 0.0;
float solChange = 0.0;

void getCryptoPrices() {
  unsigned long CriptocurrentMillis = millis();

  // Check if it's time to update prices (either first run or after Criptointerval)
  if (CriptofirstRun || CriptocurrentMillis - CriptopreviousMillis >= Criptointerval) {
    CriptopreviousMillis = CriptocurrentMillis;


    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(apiUrl);
      int httpResponseCode = http.GET();

      if (httpResponseCode > 0) {
        String payload = http.getString();
        Serial.println("Received Data: ");
        Serial.println(payload);

        // Parse JSON response
        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, payload);

        if (error) {
         // Serial.print("JSON parsing failed: ");
        //  Serial.println(error.c_str());
          return;
        }

        // Extract prices and changes
         btcPrice = doc["bitcoin"]["usd"];
         btcChange = doc["bitcoin"]["usd_24h_change"];
         ethPrice = doc["ethereum"]["usd"];
         ethChange = doc["ethereum"]["usd_24h_change"];
         solPrice = doc["solana"]["usd"];
         solChange = doc["solana"]["usd_24h_change"];

        // Print results
        //Serial.printf("Bitcoin: $%.2f (24h change: %.0f%%)\n", btcPrice, btcChange);
       // Serial.printf("Ethereum: $%.2f (24h change: %.2f%%)\n", ethPrice, ethChange);
       // Serial.printf("Solana: $%.2f (24h change: %.2f%%)\n", solPrice, solChange);
      } else {
      //  Serial.printf("HTTP GET request failed. Error code: %d\n", httpResponseCode);
      }
      http.end();
    } else {
     // Serial.println("Wi-Fi is not connected");
    }
  }
}
/**********************************************Setup************************************************************/

void setup() {
  Serial.begin(115200);
  //WiFi.mode(WIFI_STA);
  WiFi.begin(wifiSSID, wifiPassword);

    mySerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);  // Initialize HardwareSerial at 115200 baud rate
    mySerial.println("ESP32-WROOM: UART initialized");

  ntpClient.begin();

  String LVGL_Arduino = "LVGL demo ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  //Serial.println(LVGL_Arduino);

  //Initialise the touchscreen
  touchscreenSpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS); /* Start second SPI bus for touchscreen */
  touchscreen.begin(touchscreenSpi);                                         /* Touchscreen init */
  touchscreen.setRotation(3);                                                /* Inverted landscape orientation to match screen */

  //Initialise LVGL GUI
  lv_init();

  draw_buf = new uint8_t[DRAW_BUF_SIZE];
  lv_display_t *disp;
  disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, DRAW_BUF_SIZE);

  //Initialize the XPT2046 input device driver
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  //Done
  Serial.println("LVGL Setup done");

  //Integrate EEZ Studio GUI
  ui_init();
  checkAndUpdateTime();

    // Fetch cryptocurrency prices immediately after boot
  getCryptoPrices();
  CriptofirstRun = false;  // Reset the flag after the first fetch

}


/**********************************************loop************************************************************/




void loop() {


  unsigned long ScreenCurrentMillis = millis();
  if (ScreenCurrentMillis - ScreeneviousMillis >= ScreenintervalMillis) {
    ScreeneviousMillis = ScreenCurrentMillis;
    lv_tick_inc(millis() - lastTick);  //Update the tick timer. Tick is new for LVGL 9
    lastTick = millis();
    lv_timer_handler();  //Update the UI
  }

  checkWiFiConnection();
  checkAndUpdateTime();
  updateWeather();
  getCryptoPrices();
   Serial_Communication();

  lv_label_set_text_fmt(objects.label_main_screen_temperature_value, "%.1f °C", temp_C);
  lv_label_set_text_fmt(objects.label_main_screen_wind_value,"%.1f M/S", wind_speed_float);
  lv_label_set_text_fmt(objects.label_main_screen_humidity_value, "%i %%", humidity);
  
  lv_label_set_text_fmt(objects.label_main_screen_bitcoin_value, "%.0f%", btcPrice);
  lv_label_set_text_fmt(objects.label_main_screen_ethereum_value, "%.0f%" , ethPrice);
  lv_label_set_text_fmt(objects.label_main_screen_solana_value, "%.1f%" , solPrice);


  var__swich_light1 = get_var__swich_light1_value();
  var__swich_light2 = get_var__swich_light2_value();
  var__swich_light3 = get_var__swich_light3_value();
  var__swich_light4 = get_var__swich_light4_value();




  //lv_label_set_text_fmt(objects.label_main_screen_time_hours, "%i" ,100);
  lv_label_set_text(objects.label_main_screen_main, "Main");
  //lv_label_set_text(objects.label_main_screen_connection_status , "Conn");
  //lv_label_set_text_fmt(objects.label_main_screen_bitcoin_value, "%i", 200);
  //lv_label_set_text_fmt(objects.label_main_screen_ethereum_value, "%i", 300);
  //lv_label_set_text_fmt(objects.label_main_screen_solana_value, "%i", 400);
  //lv_label_set_text_fmt(objects.label_main_screen_temperature_value, "%i", 500);
  //lv_label_set_text_fmt(objects.label_main_screen_wind_value, "%i", 600);
  //lv_label_set_text_fmt(objects.label_main_screen_humidity_value, "%i", 700);

}