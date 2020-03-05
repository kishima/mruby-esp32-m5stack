#include "mruby.h"
#include "mruby/data.h"
#include "mruby/variable.h"
#include "mrb_m5stack.h"
#include "m5mruby.h"
#include "m5mruby_app.h"

//MRB_BEGIN_DECL
/*
extern NaryaRef gNaryaRef;

mrb_value mrb_narya_sound_load_mml(mrb_state *mrb, mrb_value self)
{
  M5MRB_DEBUG(M5MRB_LOG::DEBUG,"sound load\n");
  mrb_int ch;
  char * mml = NULL;
  mrb_get_args(mrb, "iz", &ch,&mml);
  if(ch<0 || ch>=M5MRB_AUDIO_MAX_CHANNEL) mrb_raisef(mrb,E_ARGUMENT_ERROR,"Bad sound ch(%d)\n",ch);
  if(mml) gNaryaRef.fmrb_sound_engine->load_mml(ch,mml);
  return self;
}

mrb_value mrb_narya_sound_play_mml(mrb_state *mrb, mrb_value self)
{
  M5MRB_DEBUG(M5MRB_LOG::DEBUG,"sound play mml\n");
  mrb_int ch;
  mrb_bool loop;
  mrb_get_args(mrb, "ib", &ch,&loop);
  if(ch<0 || ch>=M5MRB_AUDIO_MAX_CHANNEL) mrb_raisef(mrb,E_ARGUMENT_ERROR,"Bad sound ch(%d)\n",ch);
  gNaryaRef.fmrb_sound_engine->play_mml(ch,loop);
  return self;
}

mrb_value mrb_narya_sound_play_all(mrb_state *mrb, mrb_value self)
{
  M5MRB_DEBUG(M5MRB_LOG::DEBUG,"sound play all\n");
  mrb_bool loop;
  mrb_get_args(mrb, "b", &loop);
  gNaryaRef.fmrb_sound_engine->play_all(loop);
  return self;
}

mrb_value mrb_narya_sound_stop_all(mrb_state *mrb, mrb_value self)
{
  M5MRB_DEBUG(M5MRB_LOG::DEBUG,"sound stop\n");
  gNaryaRef.fmrb_sound_engine->stop_all();
  return self;
}
*/
//MRB_END_DECL
