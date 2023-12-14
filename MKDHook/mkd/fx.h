#pragma once

typedef int fx_handle;


fx_handle fx(char* name);
fx_handle pfxhandle_spawn_at_bid_next(fx_handle fx, int obj, int boneID);
fx_handle pfxhandle_spawn_at_bid_next_render(fx_handle fx, int obj, int boneID);
fx_handle resume_effect_at_obj_bid(int obj, int boneID, fx_handle fx, int unk, int unk2);

fx_handle fx_by_owner(char* name, int who);

void	  fx_reset(fx_handle fx);
void	  fx_reset_emit(fx_handle fx);
void	  fx_pause_emit(fx_handle fx);