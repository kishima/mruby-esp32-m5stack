#ifndef MRB_M5STACK_H
#define MRB_M5STACK_H

MRB_BEGIN_DECL

//Lcd
mrb_value mrb_m5stack_lcd_text(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_lcd_set_text_size(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_lcd_draw_string(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_lcd_print(mrb_state *mrb, mrb_value self);

//Button
mrb_value mrb_m5stack_button_is_pressed(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_button_was_pressed(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_button_pressed_for(mrb_state *mrb, mrb_value self);

//IMU
mrb_value mrb_m5stack_imu_init(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_imu_calibrate(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_imu_read_byte(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_imu_read_gyro(mrb_state *mrb, mrb_value self);
mrb_value mrb_m5stack_imu_read_accel(mrb_state *mrb, mrb_value self);


MRB_END_DECL

#endif
