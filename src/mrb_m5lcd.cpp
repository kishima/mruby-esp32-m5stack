#include "mruby.h"
#include "mruby/data.h"
#include "mruby/variable.h"

#include "m5mruby.h"

#include "mrb_m5stack.h"

#include "M5Stack.h"

static uint16_t get_16color(uint8_t red, uint8_t green, uint8_t blue){
  return ((red>>3)<<11) | ((green>>2)<<5) | (blue>>3);
}

static uint16_t color_obj_to_16bit(mrb_state *mrb,mrb_value col){
  mrb_value v_r = mrb_iv_get(mrb,col,mrb_intern_cstr(mrb, "@r"));
  mrb_value v_g = mrb_iv_get(mrb,col,mrb_intern_cstr(mrb, "@g"));
  mrb_value v_b = mrb_iv_get(mrb,col,mrb_intern_cstr(mrb, "@b"));
  uint8_t r = mrb_fixnum(v_r);
  uint8_t g = mrb_fixnum(v_g);
  uint8_t b = mrb_fixnum(v_b);
  return(get_16color(r,g,b));
}

mrb_value mrb_m5stack_lcd_text(mrb_state *mrb, mrb_value self)
{
  mrb_int x;
  mrb_int y;
  char * text = NULL;
  mrb_value col;
  mrb_bool opt;
  mrb_get_args(mrb, "iiz|o?", &x,&y,&text,&col,&opt);

  if(opt){
    M5.Lcd.setTextColor(color_obj_to_16bit(mrb,col));
  }
  M5.Lcd.setCursor(x, y);
  M5.Lcd.print(text);
  return self;
}


mrb_value mrb_m5stack_lcd_sleep(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_wakeup(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_set_brightness(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_progress_bar(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_qrcode(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_bmp(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_bmp_file(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_jpg(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_jpg_file(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_fill_screen(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_set_text_color(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_set_cursor(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_set_text_size(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_pixel(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_line(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_triangle(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_fill_triangle(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_rect(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_fill_rect(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_round_rect(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_fill_round_rect(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_ellipse(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_fill_ellipse(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_set_rotation(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_invert_display(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_load_font(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_unload_font(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_font_loaded(mrb_state *mrb, mrb_value self)
{
  return self;
}

mrb_value mrb_m5stack_lcd_draw_string(mrb_state *mrb, mrb_value self)
{
  mrb_int x;
  mrb_int y;
  char * text = NULL;
  mrb_value col;
  mrb_bool opt;
  mrb_get_args(mrb, "iiz|o?", &x,&y,&text,&col,&opt);

  if(opt){
    M5.Lcd.setTextColor(color_obj_to_16bit(mrb,col));
  }
  M5.Lcd.setCursor(x, y);
  M5.Lcd.print(text);
  return self;
}

mrb_value mrb_m5stack_lcd_print(mrb_state *mrb, mrb_value self)
{
  char * text = NULL;
  mrb_value col;
  mrb_bool opt;
  mrb_get_args(mrb, "z|o?", &text,&col,&opt);
  if(opt){
    M5.Lcd.setTextColor(color_obj_to_16bit(mrb,col));
  }

  return self;
}
