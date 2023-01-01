#include "Common.h"
#include "AL_general.h"
#include "GAME_frame.h"

void buildchara (CHARA* chara,int stage)
{
chara->x=4;
chara->y=4;
chara->life=3;
chara->point=0;
chara->state=CH_STAY;
}
