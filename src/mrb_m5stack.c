/*
** mrb_m5stack.c - mruby interface for M5Stack
**
** Copyright (c) KAGEYAMA Katsuhiko 2020
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/value.h"
#include "mrb_m5stack.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

void mrb_mruby_esp32_m5stack_gem_init(mrb_state *mrb)
{
  struct RClass *m5_module = mrb_define_module(mrb, "M5");
  struct RClass *lcd_module = mrb_define_module_under(mrb, m5_module, "Lcd");

  mrb_define_module_function(mrb, lcd_module, "text", mrb_m5stack_lcd_text, MRB_ARGS_ARG(4,1));
  mrb_define_module_function(mrb, lcd_module, "set_text_size", mrb_m5stack_lcd_set_text_size, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, lcd_module, "draw_string", mrb_m5stack_lcd_draw_string, MRB_ARGS_ARG(3,1));
  mrb_define_module_function(mrb, lcd_module, "print", mrb_m5stack_lcd_print, MRB_ARGS_ARG(1,1));
  /*
  sleep
  wakeup
  set_brightness
  progress_bar
  qrcode
  draw_bmp
  draw_bmp_file
  draw_jpg
  draw_jpg_file
  fill_screen
  set_text_color
  set_cursor
  set_text_size
  draw_pixel
  draw_line
  draw_triangle
  fill_triangle
  draw_rect
  fill_rect
  draw_round_rect
  fill_round_rect
  draw_ellipse
  fill_ellipse
  set_rotation
  invert_display
  load_font
  unload_font
  font_loaded?
  draw_string
  print

  */
  struct RClass *btn_module = mrb_define_module_under(mrb, m5_module, "Button");
  mrb_define_module_function(mrb, btn_module, "is_pressed?", mrb_m5stack_button_is_pressed, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, btn_module, "was_pressed?", mrb_m5stack_button_was_pressed, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, btn_module, "pressed_for", mrb_m5stack_button_pressed_for, MRB_ARGS_REQ(2));
  /*
  is_pressed?
  was_pressed?
  pressed_for
  */

  struct RClass *imu_module = mrb_define_module_under(mrb, m5_module, "IMU");
  mrb_define_module_function(mrb, imu_module, "init", mrb_m5stack_imu_init, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, imu_module, "calibrate", mrb_m5stack_imu_calibrate, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, imu_module, "read_byte", mrb_m5stack_imu_read_byte, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, imu_module, "read_gyro", mrb_m5stack_imu_read_gyro, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, imu_module, "read_accel", mrb_m5stack_imu_read_accel, MRB_ARGS_NONE());
  /*
  init_MPU9250
  init_AK8963
  calibrate_MPU9250
  read_byte
  read_gyro
  read_accel
  */

  DONE;
}

void mrb_mruby_esp32_m5stack_gem_final(mrb_state *mrb)
{
  
}


