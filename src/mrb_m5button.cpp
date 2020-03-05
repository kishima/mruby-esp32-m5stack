
#include "mruby.h"
#include "mruby/data.h"
#include "mruby/variable.h"

#include "m5mruby.h"

#include "mrb_m5stack.h"

#include "M5Stack.h"


mrb_value mrb_m5stack_button_is_pressed(mrb_state *mrb, mrb_value self)
{
  mrb_int index;
  mrb_get_args(mrb, "i", &index);
  if(index<0 || index>2){
    mrb_raise(mrb,E_ARGUMENT_ERROR,"invalid button index");
  }
  mrb_bool result=0;
  switch(index){
    case 0:
      result = (mrb_bool)M5.BtnA.isPressed();
      break;
    case 1:
      result = (mrb_bool)M5.BtnB.isPressed();
      break;
    case 2:
      result = (mrb_bool)M5.BtnC.isPressed();
      break;
    default:
      break;
  }
  return mrb_bool_value(result);
}


mrb_value mrb_m5stack_button_was_pressed(mrb_state *mrb, mrb_value self)
{
  mrb_int index;
  mrb_get_args(mrb, "i", &index);
  if(index<0 || index>2){
    mrb_raise(mrb,E_ARGUMENT_ERROR,"invalid button index");
  }
  mrb_bool result=0;
  switch(index){
    case 0:
      result = (mrb_bool)M5.BtnA.wasPressed();
      break;
    case 1:
      result = (mrb_bool)M5.BtnB.wasPressed();
      break;
    case 2:
      result = (mrb_bool)M5.BtnC.wasPressed();
      break;
    default:
      break;
  }
  return mrb_bool_value(result);
}

mrb_value mrb_m5stack_button_pressed_for(mrb_state *mrb, mrb_value self)
{
  mrb_int index;
  mrb_int time;
  mrb_get_args(mrb, "ii", &index,&time);
  if(index<0 || index>2){
    mrb_raise(mrb,E_ARGUMENT_ERROR,"invalid button index");
  }
  if(time<0){
    mrb_raise(mrb,E_ARGUMENT_ERROR,"invalid time");
  }
  mrb_bool result=0;
  switch(index){
    case 0:
      result = (mrb_bool)M5.BtnA.pressedFor((uint32_t)time);
      break;
    case 1:
      result = (mrb_bool)M5.BtnB.pressedFor((uint32_t)time);
      break;
    case 2:
      result = (mrb_bool)M5.BtnC.pressedFor((uint32_t)time);
      break;
    default:
      break;
  }
  return mrb_bool_value(result);

}