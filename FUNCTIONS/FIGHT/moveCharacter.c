#include "Game_frame.h"
#include "Common.h"
#include "AL_general.h"
#include "GAME_frame.h"

void moveChara(BOX ***box,CHARA* chara,ALLEGRO_KEYBOARD_EVENT *keyboard)
{
    switch (keyboard->keycode)
         {
         case ALLEGRO_KEY_UP:
             chara->y --;
             if (chara->y<=0)
             chara->y= 8 ;

            break;
         case ALLEGRO_KEY_DOWN:
             chara->y++;
             if (chara->y>=8)
             chara->y=0;

            break;
         case ALLEGRO_KEY_LEFT:
             chara->x--;
             if (chara->x<=0)
             chara->x=8;

            break;
         case ALLEGRO_KEY_RIGHT:
             chara->x++;
             if (chara->x>=8)
             chara->x=0;

            break;

         }


}
