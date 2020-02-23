#include "mruby.h"
#include "mruby/data.h"
#include "mruby/variable.h"

#include "m5mruby.h"

#include "mrb_m5stack.h"

#include "M5Stack.h"

uint16_t get_16color(uint8_t red, uint8_t green, uint8_t blue){
  return ((red>>3)<<11) | ((green>>2)<<5) | (blue>>3);
}

mrb_value mrb_m5stack_lcd_text(mrb_state *mrb, mrb_value self)
{
  mrb_int x;
  mrb_int y;
  char * text = NULL;
  mrb_value col;
  mrb_get_args(mrb, "iizo", &x,&y,&text,&col);

  mrb_value v_r = mrb_iv_get(mrb,col,mrb_intern_cstr(mrb, "@r"));
  mrb_value v_g = mrb_iv_get(mrb,col,mrb_intern_cstr(mrb, "@g"));
  mrb_value v_b = mrb_iv_get(mrb,col,mrb_intern_cstr(mrb, "@b"));
  uint8_t r = (uint8_t)mrb_fixnum(v_r);
  uint8_t g = (uint8_t)mrb_fixnum(v_g);
  uint8_t b = (uint8_t)mrb_fixnum(v_b);

  M5MRB_DEBUG(M5MRB_LOG::DEBUG,"text %d,%d (%s) (%d,%d,%d)\n",x,y,text,r,g,b);
  M5.Lcd.setCursor(x, y);
  M5.Lcd.setTextColor(get_16color(r,g,b));
  M5.Lcd.print(text);
  return self;
}

