#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"
#include "Game_playerEvent.h"


void charaOperate(STAGE *stage,CONFIG *config)
{


    if(stage->chara->offsetX>0)
    stage->chara->offsetX-=config->unit;
    else if (stage->chara->offsetX<0)
    stage->chara->offsetX+=config->unit;

    if(stage->chara->offsetY>0)
    stage->chara->offsetY-=config->unit;
    else if (stage->chara->offsetY<0)
    stage->chara->offsetY+=config->unit;

    switch(stage->chara->state)
    {
    case CH_ATTACK:
        if(++stage->chara->step==10)
        {
            stage->chara->step=0;
            stage->chara->state=CH_STAY;
        }
        break;
    case CH_STAY:
        if(++stage->chara->step==14)
            stage->chara->step=0;
        break;
    case CH_MOVE:
         if(++stage->chara->step==14)
        {
            stage->chara->step=0;
            stage->chara->state=CH_STAY;
        }
        break;

    }




}

void detectCharaDamage(STAGE *stage,RESOURCE *res)
{
    CHARA *chara=stage->chara;

    if(al_get_timer_count(chara->timer))
       {
        chara->vulnerable=true;
        al_stop_timer(chara->timer);
       }

    if(stage->box[chara->x][chara->y]->y<(stage->boxStartY+2*stage->length)||
       stage->box[chara->x][chara->y]->y>(stage->boxStartY+7*stage->length))
        chara->life=0;      //fatal saw

    if(stage->box[chara->x][chara->y]->damage==HURT&&chara->vulnerable)
        {chara->life--;
        al_start_timer(chara->timer);
        al_set_timer_count(chara->timer,0);
        chara->vulnerable=false;
        }



}


void controlChara (STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard)
{
    CHARA* chara =stage->chara;

    if(chara->state==CH_STAY||chara->step>9) //only controllable when state is stay
    switch(keyboard->keycode)
    {
    case ALLEGRO_KEY_UP:
        if (--chara->y<0)
        chara->y=stage->boxNumY-1;
        chara->state=CH_MOVE;
        chara->offsetY=stage->length;
        break;
    case ALLEGRO_KEY_DOWN:
        if (++chara->y==stage->boxNumY)
        chara->y=0;
        chara->state=CH_MOVE;
        chara->offsetY=-stage->length;
        break;
    case ALLEGRO_KEY_LEFT:

        if(stage->box[chara->x-1][chara->y]->state==BOUNDARY)
            return 0;
        chara->x--;
        chara->facingRight=1;
        chara->state=CH_MOVE;
        chara->step=0;
        chara->offsetX=stage->length;

        break;
    case ALLEGRO_KEY_RIGHT:


        if(stage->box[chara->x+1][chara->y]->state==BOUNDARY)
            return 0;
        chara->x++;
        chara->facingRight=0;
        chara->state=CH_MOVE;
        chara->offsetX=-stage->length;
        break;

    }
    chara->step=0;
}
