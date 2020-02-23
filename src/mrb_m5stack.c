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


  DONE;
}

void mrb_mruby_esp32_m5stack_gem_final(mrb_state *mrb)
{
  
}


