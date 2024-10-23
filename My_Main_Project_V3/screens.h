#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main_screen;
    lv_obj_t *lights_control_screen;
    lv_obj_t *button_lights_screen_main_screen;
    lv_obj_t *button_main_screen_to_lights_screen;
    lv_obj_t *icon_main_screen_btcoin;
    lv_obj_t *icon_main_screen_ethereum;
    lv_obj_t *icon_main_screen_humidity;
    lv_obj_t *icon_main_screen_solana;
    lv_obj_t *icon_main_screen_temperature;
    lv_obj_t *icon_main_screen_wind;
    lv_obj_t *label_light_control_screen_slider_blue;
    lv_obj_t *label_light_control_screen_slider_green;
    lv_obj_t *label_light_control_screen_slider_red;
    lv_obj_t *label_lights_screen_for_swich1;
    lv_obj_t *label_lights_screen_for_swich2;
    lv_obj_t *label_lights_screen_for_swich3;
    lv_obj_t *label_lights_screen_for_swich4;
    lv_obj_t *label_lights_screen_to_main_screen_button;
    lv_obj_t *label_main_screen_bitcoin_value;
    lv_obj_t *label_main_screen_connection_status;
    lv_obj_t *label_main_screen_ethereum_value;
    lv_obj_t *label_main_screen_humidity_value;
    lv_obj_t *label_main_screen_main;
    lv_obj_t *label_main_screen_solana_value;
    lv_obj_t *label_main_screen_temperature_value;
    lv_obj_t *label_main_screen_time_hours;
    lv_obj_t *label_main_screen_wind_value;
    lv_obj_t *lebel_main_screen_to_lights_button;
    lv_obj_t *panel_light_control_screen_blue;
    lv_obj_t *panel_light_control_screen_green;
    lv_obj_t *panel_light_control_screen_red;
    lv_obj_t *panel_light_screen_swich1;
    lv_obj_t *panel_light_screen_swich2;
    lv_obj_t *panel_light_screen_swich3;
    lv_obj_t *panel_light_screen_swich4;
    lv_obj_t *panel_mian_screen;
    lv_obj_t *slider_light_control_screen_slider_blue;
    lv_obj_t *slider_light_control_screen_slider_green;
    lv_obj_t *slider_light_control_screen_slider_red;
    lv_obj_t *swich_1_lights_screen;
    lv_obj_t *swich_2_lights_screen;
    lv_obj_t *swich_3_lights_screen;
    lv_obj_t *swich_4_lights_screen;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN_SCREEN = 1,
    SCREEN_ID_LIGHTS_CONTROL_SCREEN = 2,
};

void create_screen_main_screen();
void tick_screen_main_screen();

void create_screen_lights_control_screen();
void tick_screen_lights_control_screen();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/