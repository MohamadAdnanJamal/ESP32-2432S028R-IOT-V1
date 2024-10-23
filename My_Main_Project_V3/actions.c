#include "actions.h"
#include "ui.h"
//loadScreen(  );
// in screens.h lock for enum ScreensEnum ex SCREEN_ID_MAIN_SCREEN1 = 1
// in ui.c     lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false); ------>   lv_scr_load(screen);

extern void action_action_button_main_screen_to_lights_screen(lv_event_t* e) {
  loadScreen(SCREEN_ID_LIGHTS_CONTROL_SCREEN);
}
extern void action_action_all_to_main_screen(lv_event_t* e) {
  loadScreen(SCREEN_ID_MAIN_SCREEN);
}
