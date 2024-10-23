#include "vars.h"

static int32_t var__red_value = 0;
static int32_t var__green_value = 0;
static int32_t var__blue_value = 0;

// vars.h
#ifndef VARS_H
#define VARS_H

extern bool var__swich_light1;
extern bool var__swich_light2;
extern bool var__swich_light3;
extern bool var__swich_light4;

#endif

extern bool get_var__swich_light1_value() {
  return var__swich_light1;
}
extern void set_var__swich_light1_value(bool value) {
  var__swich_light1 = value;
}

extern bool get_var__swich_light2_value() {
  return var__swich_light2;
}
extern void set_var__swich_light2_value(bool value) {
  var__swich_light2 = value;
}

extern bool get_var__swich_light3_value() {
  return var__swich_light3;
}
extern void set_var__swich_light3_value(bool value) {
  var__swich_light3 = value;
}

extern bool get_var__swich_light4_value() {
  return var__swich_light4;
}
extern void set_var__swich_light4_value(bool value) {
  var__swich_light4 = value;
}

extern int32_t get_var__red_value() {
  return var__red_value;
}
extern void set_var__red_value(int32_t value) {
  var__red_value = value;
}

extern int32_t get_var__green_value() {
  return var__green_value;
}
extern void set_var__green_value(int32_t value) {
  var__green_value = value;
}

extern int32_t get_var__blue_value() {
  return var__blue_value;
}
extern void set_var__blue_value(int32_t value) {
  var__blue_value = value;
}



extern int32_t get_var__time_hours_value() {}
extern void set_var__time_hours_value(int32_t value) {}
extern int32_t get_var__btc_value() {}
extern void set_var__btc_value(int32_t value) {}
extern int32_t get_var__ethereum_value() {}
extern void set_var__ethereum_value(int32_t value) {}
extern int32_t get_var__solana_value() {}
extern void set_var__solana_value(int32_t value) {}
extern int32_t get_var__temperature_value() {}
extern void set_var__temperature_value(int32_t value) {}
extern int32_t get_var__wind_speed_value() {}
extern void set_var__wind_speed_value(int32_t value) {}
extern int32_t get_var__humidity_value() {}
extern void set_var__humidity_value(int32_t value) {}
