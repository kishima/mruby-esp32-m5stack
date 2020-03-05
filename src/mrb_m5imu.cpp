#include "mruby.h"
#include "mruby/data.h"
#include "mruby/array.h"
#include "mruby/variable.h"

#include "m5mruby.h"

#include "mrb_m5stack.h"

#include "M5Stack.h"
#include "utility/MPU6886.h"


mrb_value mrb_m5stack_imu_init(mrb_state *mrb, mrb_value self)
{
  M5.IMU.init();
  return self;
}
mrb_value mrb_m5stack_imu_calibrate(mrb_state *mrb, mrb_value self)
{
  return self;
}
mrb_value mrb_m5stack_imu_read_byte(mrb_state *mrb, mrb_value self)
{
  return self;
}
mrb_value mrb_m5stack_imu_read_gyro(mrb_state *mrb, mrb_value self)
{  
  float ax,ay,az;
  M5.IMU.getGyroData(&ax,&ay,&az);
  mrb_value v[3];
  v[0] = mrb_float_value(mrb,(mrb_float)ax);
  v[1] = mrb_float_value(mrb,(mrb_float)ay);
  v[2] = mrb_float_value(mrb,(mrb_float)az);
  return mrb_ary_new_from_values(mrb,3,v);
}
mrb_value mrb_m5stack_imu_read_accel(mrb_state *mrb, mrb_value self)
{
  mrb_float ax,ay,az;
  M5.IMU.getAccelData(&ax,&ay,&az);
  mrb_value v[3];
  v[0] = mrb_float_value(mrb,(mrb_float)ax);
  v[1] = mrb_float_value(mrb,(mrb_float)ay);
  v[2] = mrb_float_value(mrb,(mrb_float)az);
  mrb_ary_new_from_values(mrb,3,v);
  return mrb_ary_new_from_values(mrb,3,v);
}
