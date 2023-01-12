#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

void detectCharaDamage(CHARA *chara,STAGE *stage)
{
switch(stage->box[chara->x][chara->y]->state)
case BLOCK:
//al_draw_filled_rectangle(stage->box[chara->x][chara->y]->x,stage->box[chara->x][chara->y]->y,stage->box[chara->x][chara->y]->x+stage->length,
//                         stage->box[chara->x][chara->y]->y+stage->length,al_map_rgb(100,0,100));

break;
}

void moveChara (CHARA *chara,STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard)
{
    switch(keyboard->keycode)
    {
    case ALLEGRO_KEY_UP:
        if(stage->box[chara->x][chara->y-1]->state)
        switch(stage->box[chara->x][chara->y-1]->state)
        {
        case BOUNDARY:
        return 0;
        break;
        case MONSTER:
        switch(keyboard->keycode)
        {
            case ALLEGRO_KEY_UP:
                if(stage->box[chara->x][chara->y-2]->state==EMPTY)
                {
                 stage->box[chara->x][chara->y-1]->state=EMPTY;
                 stage->box[chara->x][chara->y-2]->state=MONSTER;
                }
                else
                 stage->box[chara->x][chara->y-1]->state=EMPTY;
                 return 0;
                break;
        }
        break;
        case BLOCK:
        switch(keyboard->keycode)
        {
            case ALLEGRO_KEY_UP:
                if(stage->box[chara->x][chara->y-2]->state==EMPTY)
                {
                 stage->box[chara->x][chara->y-1]->state=EMPTY;
                 stage->box[chara->x][chara->y-2]->state=BLOCK;
                }
                else if(stage->box[chara->x][chara->y-2]->state)
                 return 0;
                else
                 stage->box[chara->x][chara->y-1]->state=EMPTY;
                 return 0;
                break;
        }
        }
        chara->y--;
        chara->state=CH_MOVE;
        chara->step=0;
        break;/******************************/
    case ALLEGRO_KEY_DOWN:
        if(stage->box[chara->x][chara->y+1]->state)
        switch(stage->box[chara->x][chara->y+1]->state)
        {
        case BOUNDARY:
        return 0;
        break;
        case MONSTER:
                if(stage->box[chara->x][chara->y+2]->state==EMPTY)
                {
                 stage->box[chara->x][chara->y+1]->state=EMPTY;
                 stage->box[chara->x][chara->y+2]->state=MONSTER;
                }
                else
                 stage->box[chara->x][chara->y+1]->state=EMPTY;
                 return 0;
                break;
        case BLOCK:
                if(stage->box[chara->x][chara->y+2]->state==EMPTY)
                {
                 stage->box[chara->x][chara->y+1]->state=EMPTY;
                 stage->box[chara->x][chara->y+2]->state=BLOCK;
                }
                else if(stage->box[chara->x][chara->y+2]->state)
                 return 0;
                else
                 stage->box[chara->x][chara->y+1]->state=EMPTY;
                 return 0;
                break;
        }
        chara->y++;
        chara->state=CH_MOVE;
        chara->step=0;
        break;/******************************/
    case ALLEGRO_KEY_LEFT:
        if(stage->box[chara->x-1][chara->y]->state)
            switch(stage->box[chara->x-1][chara->y]->state)
            {
            case BOUNDARY:
                return 0;
                break;
            case MONSTER:
                if(stage->box[chara->x-2][chara->y]->state==EMPTY)
                {
                    stage->box[chara->x-1][chara->y]->state=EMPTY;
                    stage->box[chara->x-2][chara->y]->state=MONSTER;
                }
                else
                    stage->box[chara->x-1][chara->y]->state=EMPTY;
                return 0;
                break;
            case BLOCK:
                switch(keyboard->keycode)
                {
                case ALLEGRO_KEY_LEFT:
                    if(stage->box[chara->x-2][chara->y]->state==EMPTY)
                    {
                    stage->box[chara->x-1][chara->y]->state=EMPTY;
                    stage->box[chara->x-2][chara->y]->state=BLOCK;
                    }
                    else if(stage->box[chara->x-2][chara->y]->state)
                        return 0;
                    else
                        //stage->box[chara->x-1][chara->y]->state=EMPTY;
                    return 0;
                    break;
            }
        }
        chara->x--;
        chara->facingRight=1;
        chara->state=CH_MOVE;
        chara->step=0;
        break;/******************************/
    case ALLEGRO_KEY_RIGHT:
        if(stage->box[chara->x+1][chara->y]->state)
        switch(stage->box[chara->x+1][chara->y]->state)
        {
    case BOUNDARY:
        return 0;
        break;
    case MONSTER:
        switch(keyboard->keycode)
        {
            case ALLEGRO_KEY_RIGHT:
                if(stage->box[chara->x+2][chara->y]->state==EMPTY)
                {
                 stage->box[chara->x+1][chara->y]->state=EMPTY;
                 stage->box[chara->x+2][chara->y]->state=MONSTER;
                }
                else
                 stage->box[chara->x+1][chara->y]->state=EMPTY;
                 return 0;
                break;
        }
        break;
    case BLOCK:
        switch(keyboard->keycode)
        {
            case ALLEGRO_KEY_RIGHT:
                if(stage->box[chara->x+2][chara->y]->state==EMPTY)
                {
                 stage->box[chara->x+1][chara->y]->state=EMPTY;
                 stage->box[chara->x+2][chara->y]->state=BLOCK;
                }
                else if(stage->box[chara->x+2][chara->y]->state)
                 return 0;
                else
                 stage->box[chara->x+1][chara->y]->state=EMPTY;
                 return 0;
                break;
        }
        }
        chara->x++;
        chara->facingRight=0;
        chara->state=CH_MOVE;
        chara->step=0;
        break;
    }
}




void drawChara (CHARA *chara,STAGE *stage,RESOURCE *res,CONFIG *config)
{
al_draw_scaled_bitmap(res->chara,180*chara->step,0,180,180,stage->box[chara->x][chara->y]->x,stage->box[chara->x][chara->y]->y,
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
//al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][0]->x,box[1][0]->y,stage->length*7,stage->length*7,0);
//al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][2]->x,box[1][2]->y,stage->length*7,stage->length*7,0);
//al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][4]->x,box[1][4]->y,stage->length*7,stage->length*7,0);
//al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][6]->x,box[1][6]->y,stage->length*7,stage->length*7,0);
//al_draw_scaled_bitmap(res->belt,0,0,400,658,box[1][8]->x,box[1][8]->y,stage->length*7,stage->length*7,0);


for (x=0;x<stage->boxNumX;x++)
    for(y=0;y<stage->boxNumY;y++)
    {
        switch(box[x][y]->element)
        {
            case KEY:
                al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgb(255,215,0));
                break;
            case TRAP:
                al_draw_scaled_bitmap(res->trap,0,0,1000,1000,box[x][y]->x,box[x][y]->y,stage->length,stage->length,0);
                break;
    }
        switch(box[x][y]->state)
        {
            case BOUNDARY:
                al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgba(0,100,0,5));
                break;
            case BLOCK:
                al_draw_scaled_bitmap(res->block,0,0,250,250,box[x][y]->x,box[x][y]->y,stage->length,stage->length,0);
                break;
            case MONSTER:
                al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgba(255,0,0,5));
                break;
            case EXIT:
                al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgb(255,255,255));
                break;
            case DOOR:
                al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgba(0,105,255,5));
                break;
        }




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
