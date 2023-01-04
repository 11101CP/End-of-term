#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

void detectCharaDamage(CHARA *chara,STAGE *stage,CONFIG *config)
{
    if(al_get_timer_count(chara->timer))
       {chara->vulnerable=true;
        al_stop_timer(chara->timer);

       }
    if(stage->box[chara->x][chara->y]->y<22*config->unit||stage->box[chara->x][chara->y]->y>68*config->unit)
        chara->life=0;

if(stage->box[chara->x][chara->y]->damage==HURT&&chara->vulnerable)
    {chara->life--;
    al_start_timer(chara->timer);
    al_set_timer_count(chara->timer,0);
    chara->vulnerable=false;

    }

    if (chara->life==0)


}




void moveChara (CHARA *chara,STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard)
{ //if(chara->state==CH_STAY)
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
        if (--chara->x<0)
        chara->x=stage->boxNumX-1;
        else if(stage->box[chara->x][chara->y]->state==BOUNDARY)
        chara->x++;
        chara->facingRight=1;
        chara->state=CH_MOVE;
        chara->offsetX=stage->length;

        break;
    case ALLEGRO_KEY_RIGHT:
        if (++chara->x==stage->boxNumX)
        chara->x=0;
        else if(stage->box[chara->x][chara->y]->state==BOUNDARY)
        chara->x--;
        chara->facingRight=0;
        chara->state=CH_MOVE;
        chara->offsetX=-stage->length;
        break;

    }
    chara->step=0;
}
