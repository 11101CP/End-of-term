#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

void detectCharaDamage(CHARA *chara,STAGE *stage)
{
switch(stage->box[chara->x][chara->y]->state)
case BLOCK:
//al_draw_filled_rectangle(stage->box[chara->x][chara->y]->x,stage->box[chara->x][chara->y]->y,stage->box[chara->x][chara->y]->x+stage->length,
//                         stage->box[chara->x][chara->y]->y+stage->length,al_map_rgb(100,0,100));

chara->life--;
if(stage->box[chara->x][chara->y]->damage==HURT)
    chara->life--;
}

void moveChara (CHARA *chara,STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard)
{
    switch(keyboard->keycode)
    {
    case ALLEGRO_KEY_UP:
        if (--chara->y<0)
        chara->y=stage->boxNumY-1;
        chara->state=CH_MOVE;
        break;
    case ALLEGRO_KEY_DOWN:
        if (++chara->y==stage->boxNumY)
        chara->y=0;
        chara->state=CH_MOVE;
        break;
    case ALLEGRO_KEY_LEFT:
        if (--chara->x<0)
        chara->x=stage->boxNumX-1;
        else if(stage->box[chara->x][chara->y]->state==BOUNDARY)
        chara->x++;
        chara->facingRight=1;
        chara->state=CH_MOVE;

        break;
    case ALLEGRO_KEY_RIGHT:
        if (++chara->x==stage->boxNumX)
        chara->x=0;
        else if(stage->box[chara->x][chara->y]->state==BOUNDARY)
        chara->x--;
        chara->facingRight=0;
        chara->state=CH_MOVE;
        break;

    }
    chara->step=0;
}




void drawChara (CHARA *chara,STAGE *stage,RESOURCE *res,CONFIG *config)
{

if(chara->state==CH_MOVE)
al_draw_scaled_bitmap(res->chara,180*chara->step,0,180,180,stage->box[chara->x][chara->y]->x,stage->box[chara->x][chara->y]->y,
                      stage->length,stage->length,chara->facingRight);

else if (chara->state==CH_STAY)
al_draw_scaled_bitmap(res->chara,180*chara->step,180,180,180,stage->box[chara->x][chara->y]->x,stage->box[chara->x][chara->y]->y,
                      stage->length,stage->length,chara->facingRight);

}



void drawMap   (STAGE *stage,RESOURCE *res,CONFIG *config )
{BOX*** box=stage->box;
    int x,y;
al_clear_to_color(al_map_rgb(150,150,150));
for (x=0;x<stage->boxNumX;x++)
    for(y=0;y<stage->boxNumY;y++)
        al_draw_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgb(0,0,0),1);




}
void drawObject(STAGE *stage,RESOURCE *res,CONFIG *config )
{
    BOX*** box=stage->box;
    int x,y;
al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][0]->x,box[1][0]->y,stage->length*7,stage->length*7,0);
al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][2]->x,box[1][2]->y,stage->length*7,stage->length*7,0);
al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][4]->x,box[1][4]->y,stage->length*7,stage->length*7,0);
al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][6]->x,box[1][6]->y,stage->length*7,stage->length*7,0);
al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][8]->x,box[1][8]->y,stage->length*7,stage->length*7,0);


for (x=0;x<stage->boxNumX;x++)
    for(y=0;y<stage->boxNumY;y++)
        switch(box[x][y]->state)
        {
            case BOUNDARY:
               // al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgba(0,100,0,5));
                break;
            case BLOCK:
                al_draw_scaled_bitmap(res->background,0,0,1000,1000,box[x][y]->x,box[x][y]->y,stage->length,stage->length,0);
        }




}

void boxShift(STAGE *stage,RESOURCE *res,CONFIG *config )
{
    BOX*** box=stage->box;
    int x,y;


for (x=0;x<stage->boxNumX;x++)
    for(y=0;y<stage->boxNumY;y++)
      {stage->box[x][y]->y-=config->unit;

        if(x!=0&&x!=8)
            {    stage->box[x][y]->state=NO;
                stage->box[x][y]->damage=NO;

                if (box[x][y]->y<=config->unit*21)
                {box[x][y]->state=BLOCK;
                box[x][y]->damage=DEATH;}
                else if(box[x][y]->y>=config->unit*67)
                {box[x][y]->state=BLOCK;
                box[x][y]->damage=DEATH;}


            }



        if(box[x][y]->y<0)
            {
                stage->box[x][y]->y=stage->box[x][y]->y+config->unit*81;
            }


        }



}
