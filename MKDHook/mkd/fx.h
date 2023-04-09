#pragma once

typedef int fx_handle;


fx_handle fx(char* name);
fx_handle pfxhandle_spawn_at_bid_next(fx_handle fx, int obj, int boneID);
void	  fx_reset(fx_handle fx);
void	  fx_reset_emit(fx_handle fx);