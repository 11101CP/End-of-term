#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

int death(RESOURCE* res,STAGE *stage ,CONFIG *config)
{
    int unit=config->unit;
    al_draw_scaled_bitmap(res->death,0,0,906,719,35*unit,10*unit,90*unit,70*unit,0);



}
