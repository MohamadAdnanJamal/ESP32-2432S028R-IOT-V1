#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif





// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE__TIME_HOURS_VALUE = 0,
    FLOW_GLOBAL_VARIABLE__BTC_VALUE = 1,
    FLOW_GLOBAL_VARIABLE__ETHEREUM_VALUE = 2,
    FLOW_GLOBAL_VARIABLE__SOLANA_VALUE = 3,
    FLOW_GLOBAL_VARIABLE__TEMPERATURE_VALUE = 4,
    FLOW_GLOBAL_VARIABLE__WIND_SPEED_VALUE = 5,
    FLOW_GLOBAL_VARIABLE__HUMIDITY_VALUE = 6,
    FLOW_GLOBAL_VARIABLE__SWICH_LIGHT1_VALUE = 7,
    FLOW_GLOBAL_VARIABLE__SWICH_LIGHT2_VALUE = 8,
    FLOW_GLOBAL_VARIABLE__SWICH_LIGHT3_VALUE = 9,
    FLOW_GLOBAL_VARIABLE__SWICH_LIGHT4_VALUE = 10,
    FLOW_GLOBAL_VARIABLE__RED_VALUE = 11,
    FLOW_GLOBAL_VARIABLE__GREEN_VALUE = 12,
    FLOW_GLOBAL_VARIABLE__BLUE_VALUE = 13
};

// Native global variables

extern int32_t get_var__time_hours_value();
extern void set_var__time_hours_value(int32_t value);
extern int32_t get_var__btc_value();
extern void set_var__btc_value(int32_t value);
extern int32_t get_var__ethereum_value();
extern void set_var__ethereum_value(int32_t value);
extern int32_t get_var__solana_value();
extern void set_var__solana_value(int32_t value);
extern int32_t get_var__temperature_value();
extern void set_var__temperature_value(int32_t value);
extern int32_t get_var__wind_speed_value();
extern void set_var__wind_speed_value(int32_t value);
extern int32_t get_var__humidity_value();
extern void set_var__humidity_value(int32_t value);
extern bool get_var__swich_light1_value();
extern void set_var__swich_light1_value(bool value);
extern bool get_var__swich_light2_value();
extern void set_var__swich_light2_value(bool value);
extern bool get_var__swich_light3_value();
extern void set_var__swich_light3_value(bool value);
extern bool get_var__swich_light4_value();
extern void set_var__swich_light4_value(bool value);
extern int32_t get_var__red_value();
extern void set_var__red_value(int32_t value);
extern int32_t get_var__green_value();
extern void set_var__green_value(int32_t value);
extern int32_t get_var__blue_value();
extern void set_var__blue_value(int32_t value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/