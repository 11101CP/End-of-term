#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"


void loadChara (STAGE *stage)
{
    stage->chara->x=4;
    stage->chara->y=4;
    stage->chara->facingRight=0;
    stage->chara->step=0;
    stage->chara->state=CH_STAY;
    stage->chara->life=3;
    stage->chara->timer=al_create_timer(1.5);
    stage->chara->vulnerable=true;
    stage->chara->offsetX=0;
    stage->chara->offsetY=0;
}
