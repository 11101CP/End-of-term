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

   // if (stage->chara->offsetX==0&stage->chara->offsetY==0)
     //   stage->chara->controllable=true;

    if (stage->chara->step>3)
        stage->chara->controllable=true;


}

void nextCharaFrame(CHARA *chara)
{
    switch(chara->state)
    {
    case CH_ATTACK:
        if(++chara->step==10)
        {
            chara->step=0;
            chara->state=CH_STAY;
        }
        break;
    case CH_STAY:
        if(++chara->step==14)
            chara->step=0;
        break;
    case CH_MOVE:
         if(++chara->step==14)
        {
            chara->step=0;
            chara->state=CH_STAY;
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

    if( stage->box[chara->x][chara->y]->y <= (stage->boxStartY+2*stage->length)||
        stage->box[chara->x][chara->y]->y >= (stage->boxStartY+7*stage->length))
        chara->life=0;      //fatal saw

    if(stage->box[chara->x][chara->y]->damage==HURT&&chara->vulnerable)
        {chara->life--;
        al_start_timer(chara->timer);
        al_set_timer_count(chara->timer,0);
        chara->vulnerable=false;
        }

}


void controlChara_Boss (STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard)
{
    CHARA* chara =stage->chara;
    int x=chara->x;
    int y=chara->y;
    int nextX;
    int nextY;
    int nextNextX;
    int nextNextY;
    int offsetX=0;
    int offsetY=0;

    if(chara->controllable)
    {
    switch(keyboard->keycode)
    {
    case ALLEGRO_KEY_UP:
        nextX=x;
        nextY=y-1;
        offsetY=stage->length;
        break;
    case ALLEGRO_KEY_DOWN:
        nextX=x;
        nextY=y+1;
        offsetY=-stage->length;
        break;
    case ALLEGRO_KEY_LEFT:
        nextX=x-1;
        nextY=y;
        chara->facingRight=1;
        offsetX=stage->length;

        break;
    case ALLEGRO_KEY_RIGHT:
        nextX=x+1;
        nextY=y;
        chara->facingRight=0;
        offsetX=-stage->length;

        break;
    }

    if(nextY<0)     //crossing shifted box
        nextY=8;
    else if(nextY>8)
        nextY=0;

    switch ( stage->box[nextX][nextY]->state )//decide movement
    {
        case EMPTY:         //move character
            chara->x=nextX;
            chara->y=nextY;
            chara->state=CH_MOVE;
            chara->step=0;
            chara->offsetX=offsetX;
            chara->offsetY=offsetY;
            chara->controllable=false;
            break;

        case BOUNDARY:      //don't move
            //do nothing

            break;

        case MONSTER:          //attack
            chara->state=CH_ATTACK;
            chara->step=0;
            chara->controllable=false;


            break;

        }

    } //end of if(chara->controllable)

}
