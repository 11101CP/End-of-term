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
    stage->chara->life=4;
    stage->chara->timer=al_create_timer(1.5);
    stage->chara->vulnerable=true;
    stage->chara->offsetX=0;
    stage->chara->offsetY=0;
    stage->chara->controllable=true;

    stage->target=calloc(2,sizeof(AttackTarget));

    stage->target[0].HP =5;
    stage->target[0].x  =0;
    stage->target[0].y  =4;
    stage->target[0].vulnerable=false;


    stage->target[1].HP =5;
    stage->target[1].x  =8;
    stage->target[1].y  =4;
    stage->target[1].vulnerable=false;

}


void stageBOSS (BOX ***box)
{
    int x,y;
//    for(x=0;x<9;x++)
//    {
//        box[x][0]->state=EMPTY;
//        box[x][1]->state=BLOCK;
//        box[x][7]->state=BLOCK;
//        box[x][8]->state=BLOCK;
//        box[x][0]->damage=DEATH;
//        box[x][1]->damage=DEATH;
//        box[x][7]->damage=DEATH;
//        box[x][8]->damage=DEATH;
//
//    }

    for(y=0;y<9;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[8][y]->state=BOUNDARY;

    }

    box[0][4]->state=MONSTER;
}
