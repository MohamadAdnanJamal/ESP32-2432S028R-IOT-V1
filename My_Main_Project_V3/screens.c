#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_screen_button_main_screen_to_lights_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_action_button_main_screen_to_lights_screen(e);
    }
}

static void event_handler_cb_main_screen_lebel_main_screen_to_lights_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_action_button_main_screen_to_lights_screen(e);
    }
}

static void event_handler_cb_lights_control_screen_swich_1_lights_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var__swich_light1_value(value);
        }
    }
}

static void event_handler_cb_lights_control_screen_button_lights_screen_main_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_action_all_to_main_screen(e);
    }
}

static void event_handler_cb_lights_control_screen_label_lights_screen_to_main_screen_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_action_all_to_main_screen(e);
    }
}

static void event_handler_cb_lights_control_screen_swich_2_lights_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var__swich_light2_value(value);
        }
    }
}

static void event_handler_cb_lights_control_screen_swich_3_lights_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var__swich_light3_value(value);
        }
    }
}

static void event_handler_cb_lights_control_screen_swich_4_lights_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var__swich_light4_value(value);
        }
    }
}

static void event_handler_cb_lights_control_screen_slider_light_control_screen_slider_red(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var__red_value(value);
        }
    }
}

static void event_handler_cb_lights_control_screen_slider_light_control_screen_slider_green(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var__green_value(value);
        }
    }
}

static void event_handler_cb_lights_control_screen_slider_light_control_screen_slider_blue(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var__blue_value(value);
        }
    }
}

void create_screen_main_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3e408a), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 1255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff858080), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Panel_MianScreen
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_mian_screen = obj;
            lv_obj_set_pos(obj, -6, -99);
            lv_obj_set_size(obj, 308, 24);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_grow(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffcb9e8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffcabfbf), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff880000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_MainScreen_Time_Hours
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_main_screen_time_hours = obj;
                    lv_obj_set_pos(obj, 13, 2);
                    lv_obj_set_size(obj, 77, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    //lv_label_set_text_fmt(objects.label_main_screen_time_hours, "%i" , 100); /*******************************/
                }
                {
                    // Label_MainScreen_Main
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_main_screen_main = obj;
                    lv_obj_set_pos(obj, 106, 2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    //lv_label_set_text(objects.label_main_screen_main, "Main");
                }
                {
                    // Label_MainScreen_ConnectionStatus
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_main_screen_connection_status = obj;
                    lv_obj_set_pos(obj, 210, 2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    //lv_label_set_text(objects.label_main_screen_connection_status , "Text"); /*******************************/
                }
            }
        }
        {
            // Icon_MainScreen_Btcoin
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_main_screen_btcoin = obj;
            lv_obj_set_pos(obj, 21, 55);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_btc_icon);
        }
        {
            // Label_MainScreen_Bitcoin_Value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_main_screen_bitcoin_value = obj;
            lv_obj_set_pos(obj, 53, 57);
            lv_obj_set_size(obj, 82, 28);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            //lv_label_set_text_fmt(objects.label_main_screen_bitcoin_value ,"%i" , "200"); /**************************************************************/
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff4941c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffd99999), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Icon_MainScreen_Ethereum
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_main_screen_ethereum = obj;
            lv_obj_set_pos(obj, 21, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_eth_icon);
        }
        {
            // Label_MainScreen_ethereum_Value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_main_screen_ethereum_value = obj;
            lv_obj_set_pos(obj, 53, 92);
            lv_obj_set_size(obj, 82, 28);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            //lv_label_set_text_fmt( objects.label_main_screen_ethereum_value,"%i",300);/*****************************************************************/
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff647cec), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffd2d7f6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Icon_MainScreen_Solana
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_main_screen_solana = obj;
            lv_obj_set_pos(obj, 21, 124);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_solana_icon);
        }
        {
            // Label_MainScreen_Solana_Value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_main_screen_solana_value = obj;
            lv_obj_set_pos(obj, 53, 126);
            lv_obj_set_size(obj, 82, 28);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            //lv_label_set_text(objects.label_main_screen_solana_value, "%i",400);/****************************************************/
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ddc2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff424ede), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Icon_MainScreen_Temperature
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_main_screen_temperature = obj;
            lv_obj_set_pos(obj, 188, 55);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_temperature_icon);
        }
        {
            // Label_MainScreen_Temperature_Value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_main_screen_temperature_value = obj;
            lv_obj_set_pos(obj, 220, 57);
            lv_obj_set_size(obj, 82, 28);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            //lv_label_set_text_fmt(objects.label_main_screen_temperature_value,"%i", 500);/******************************************************/
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff96a4da), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffee2b86), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Icon_MainScreen_Wind
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_main_screen_wind = obj;
            lv_obj_set_pos(obj, 188, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wind_speed_icon);
        }
        {
            // Label_MainScreen_Wind_Value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_main_screen_wind_value = obj;
            lv_obj_set_pos(obj, 220, 92);
            lv_obj_set_size(obj, 82, 28);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            //lv_label_set_text_fmt(objects.label_main_screen_wind_value,"%i", 600);/**************************************/
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffbcbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffce4fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Icon_MainScreen_Humidity
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_main_screen_humidity = obj;
            lv_obj_set_pos(obj, 188, 124);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_humidity_icon);
        }
        {
            // Label_MainScreen_Humidity_Value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_main_screen_humidity_value = obj;
            lv_obj_set_pos(obj, 220, 126);
            lv_obj_set_size(obj, 82, 28);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            //lv_label_set_text_fmt(objects.label_main_screen_humidity_value,"%i",700);/************************************/
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff78d5e0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffe2c5e2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Button_MainScreen_ToLightsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.button_main_screen_to_lights_screen = obj;
            lv_obj_set_pos(obj, 245, 202);
            lv_obj_set_size(obj, 57, 29);
            lv_obj_add_event_cb(obj, event_handler_cb_main_screen_button_main_screen_to_lights_screen, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3e53ab), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9a8d8d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Lebel_MainScreen_ToLights_Button
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lebel_main_screen_to_lights_button = obj;
                    lv_obj_set_pos(obj, 1, -1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Lights");
                    lv_obj_add_event_cb(obj, event_handler_cb_main_screen_lebel_main_screen_to_lights_button, LV_EVENT_ALL, 0);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff441616), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_main_screen() {
    {
        const char *new_val = get_var__time_hours_value();
        const char *cur_val = lv_label_get_text(objects.label_main_screen_time_hours);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_main_screen_time_hours;
            lv_label_set_text(objects.label_main_screen_time_hours, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var__btc_value();
        const char *cur_val = lv_label_get_text(objects.label_main_screen_bitcoin_value);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_main_screen_bitcoin_value;
            lv_label_set_text(objects.label_main_screen_bitcoin_value, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var__ethereum_value();
        const char *cur_val = lv_label_get_text(objects.label_main_screen_ethereum_value);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_main_screen_ethereum_value;
            lv_label_set_text(objects.label_main_screen_ethereum_value, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var__solana_value();
        const char *cur_val = lv_label_get_text(objects.label_main_screen_solana_value);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_main_screen_solana_value;
            lv_label_set_text(objects.label_main_screen_solana_value, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var__temperature_value();
        const char *cur_val = lv_label_get_text(objects.label_main_screen_temperature_value);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_main_screen_temperature_value;
            lv_label_set_text(objects.label_main_screen_temperature_value, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var__wind_speed_value();
        const char *cur_val = lv_label_get_text(objects.label_main_screen_wind_value);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_main_screen_wind_value;
            lv_label_set_text(objects.label_main_screen_wind_value, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var__humidity_value();
        const char *cur_val = lv_label_get_text(objects.label_main_screen_humidity_value);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_main_screen_humidity_value;
            lv_label_set_text(objects.label_main_screen_humidity_value, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_lights_control_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.lights_control_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3e408a), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 1255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff858080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Panel_LightScreen_Swich1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_light_screen_swich1 = obj;
            lv_obj_set_pos(obj, -7, -95);
            lv_obj_set_size(obj, 141, 34);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffebf6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff676767), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0091ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightsScreen_ForSwich1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_lights_screen_for_swich1 = obj;
                    lv_obj_set_pos(obj, 9, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "L 1");
                }
                {
                    // Swich_1_LightsScreen
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.swich_1_lights_screen = obj;
                    lv_obj_set_pos(obj, 82, 4);
                    lv_obj_set_size(obj, 45, 23);
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_swich_1_lights_screen, LV_EVENT_ALL, 0);
                }
            }
        }
        {
            // Button_LightsScreen_Main_Screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.button_lights_screen_main_screen = obj;
            lv_obj_set_pos(obj, 256, 202);
            lv_obj_set_size(obj, 57, 29);
            lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_button_lights_screen_main_screen, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3e53ab), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9a8d8d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffff0057), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightsScreen_ToMainScreen_Button
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_lights_screen_to_main_screen_button = obj;
                    lv_obj_set_pos(obj, 1, -1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Main");
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_label_lights_screen_to_main_screen_button, LV_EVENT_ALL, 0);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff441616), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Panel_LightScreen_Swich2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_light_screen_swich2 = obj;
            lv_obj_set_pos(obj, -168, -95);
            lv_obj_set_size(obj, 145, 34);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffebf6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff676767), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0091ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightsScreen_ForSwich2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_lights_screen_for_swich2 = obj;
                    lv_obj_set_pos(obj, 6, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "L 2");
                }
                {
                    // Swich_2_LightsScreen
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.swich_2_lights_screen = obj;
                    lv_obj_set_pos(obj, 86, 4);
                    lv_obj_set_size(obj, 45, 23);
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_swich_2_lights_screen, LV_EVENT_ALL, 0);
                }
            }
        }
        {
            // Panel_LightScreen_Swich3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_light_screen_swich3 = obj;
            lv_obj_set_pos(obj, -7, -54);
            lv_obj_set_size(obj, 141, 34);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffebf6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff676767), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0091ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightsScreen_ForSwich3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_lights_screen_for_swich3 = obj;
                    lv_obj_set_pos(obj, 9, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "L 3");
                }
                {
                    // Swich_3_LightsScreen
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.swich_3_lights_screen = obj;
                    lv_obj_set_pos(obj, 82, 4);
                    lv_obj_set_size(obj, 45, 23);
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_swich_3_lights_screen, LV_EVENT_ALL, 0);
                }
            }
        }
        {
            // Panel_LightScreen_Swich4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_light_screen_swich4 = obj;
            lv_obj_set_pos(obj, -168, -55);
            lv_obj_set_size(obj, 144, 34);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffebf6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff676767), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0091ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightsScreen_ForSwich4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_lights_screen_for_swich4 = obj;
                    lv_obj_set_pos(obj, 9, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "L 4");
                }
                {
                    // Swich_4_LightsScreen
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.swich_4_lights_screen = obj;
                    lv_obj_set_pos(obj, 85, 4);
                    lv_obj_set_size(obj, 45, 23);
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_swich_4_lights_screen, LV_EVENT_ALL, 0);
                }
            }
        }
        {
            // Panel_LightControlScreen_Red
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_light_control_screen_red = obj;
            lv_obj_set_pos(obj, -6, -12);
            lv_obj_set_size(obj, 305, 24);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffebf6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff676767), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0091ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightControlScreen_Slider_Red
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_light_control_screen_slider_red = obj;
                    lv_obj_set_pos(obj, 9, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Red");
                }
                {
                    // Slider_LightControlScreen_Slider_Red
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_light_control_screen_slider_red = obj;
                    lv_obj_set_pos(obj, 85, 5);
                    lv_obj_set_size(obj, 197, 10);
                    lv_slider_set_range(obj, 0, 255);
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_slider_light_control_screen_slider_red, LV_EVENT_ALL, 0);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0004), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Panel_LightControlScreen_Green
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_light_control_screen_green = obj;
            lv_obj_set_pos(obj, -7, 21);
            lv_obj_set_size(obj, 305, 26);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffebf6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff676767), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0091ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightControlScreen_Slider_Green
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_light_control_screen_slider_green = obj;
                    lv_obj_set_pos(obj, 8, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Green");
                }
                {
                    // Slider_LightControlScreen_Slider_Green
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_light_control_screen_slider_green = obj;
                    lv_obj_set_pos(obj, 85, 5);
                    lv_obj_set_size(obj, 197, 10);
                    lv_slider_set_range(obj, 0, 255);
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_slider_light_control_screen_slider_green, LV_EVENT_ALL, 0);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff09), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0fff00), LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 32767, LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Panel_LightControlScreen_Blue
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_light_control_screen_blue = obj;
            lv_obj_set_pos(obj, -7, 54);
            lv_obj_set_size(obj, 305, 25);
            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffebf6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff676767), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff7c0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0091ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_LightControlScreen_Slider_Blue
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_light_control_screen_slider_blue = obj;
                    lv_obj_set_pos(obj, 9, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Blue");
                }
                {
                    // Slider_LightControlScreen_Slider_Blue
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_light_control_screen_slider_blue = obj;
                    lv_obj_set_pos(obj, 85, 6);
                    lv_obj_set_size(obj, 197, 10);
                    lv_slider_set_range(obj, 0, 255);
                    lv_obj_add_event_cb(obj, event_handler_cb_lights_control_screen_slider_light_control_screen_slider_blue, LV_EVENT_ALL, 0);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0b00ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0028ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_lights_control_screen() {
    {
        bool new_val = get_var__swich_light1_value();
        bool cur_val = lv_obj_has_state(objects.swich_1_lights_screen, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.swich_1_lights_screen;
            if (new_val) lv_obj_add_state(objects.swich_1_lights_screen, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.swich_1_lights_screen, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var__swich_light2_value();
        bool cur_val = lv_obj_has_state(objects.swich_2_lights_screen, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.swich_2_lights_screen;
            if (new_val) lv_obj_add_state(objects.swich_2_lights_screen, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.swich_2_lights_screen, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var__swich_light3_value();
        bool cur_val = lv_obj_has_state(objects.swich_3_lights_screen, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.swich_3_lights_screen;
            if (new_val) lv_obj_add_state(objects.swich_3_lights_screen, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.swich_3_lights_screen, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var__swich_light4_value();
        bool cur_val = lv_obj_has_state(objects.swich_4_lights_screen, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.swich_4_lights_screen;
            if (new_val) lv_obj_add_state(objects.swich_4_lights_screen, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.swich_4_lights_screen, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var__red_value();
        int32_t cur_val = lv_slider_get_value(objects.slider_light_control_screen_slider_red);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_light_control_screen_slider_red;
            lv_slider_set_value(objects.slider_light_control_screen_slider_red, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var__green_value();
        int32_t cur_val = lv_slider_get_value(objects.slider_light_control_screen_slider_green);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_light_control_screen_slider_green;
            lv_slider_set_value(objects.slider_light_control_screen_slider_green, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var__blue_value();
        int32_t cur_val = lv_slider_get_value(objects.slider_light_control_screen_slider_blue);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_light_control_screen_slider_blue;
            lv_slider_set_value(objects.slider_light_control_screen_slider_blue, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main_screen();
    create_screen_lights_control_screen();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main_screen,
    tick_screen_lights_control_screen,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
