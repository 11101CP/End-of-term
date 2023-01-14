#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

bool moveChara (STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard,RESOURCE *res)
{
BOX ***box=stage->box;
CHARA* chara =stage->chara;
int x=chara->x;
int y=chara->y;
int nextX=x;
int nextY=y;
int nextNextX=x;
int nextNextY=y;
//int offsetX=0;
//int offsetY=0;
switch(keyboard->keycode)
{
    case ALLEGRO_KEY_R:
        al_play_sample(res->GameRestart,0.5,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
        break;
    case ALLEGRO_KEY_ESCAPE:
        al_play_sample(res->GamePause,0.5,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
        break;
    case ALLEGRO_KEY_UP:
    case ALLEGRO_KEY_W:
    case ALLEGRO_KEY_PAD_8:
        nextY=y-1;
        nextNextY=y-2;
        break;
    case ALLEGRO_KEY_DOWN:
    case ALLEGRO_KEY_S:
    case ALLEGRO_KEY_PAD_5:
        nextY=y+1;
        nextNextY=y+2;
        break;
    case ALLEGRO_KEY_LEFT:
    case ALLEGRO_KEY_A:
    case ALLEGRO_KEY_PAD_4:
        chara->facingRight=1;
        nextX=x-1;
        nextNextX=x-2;
        break;
    case ALLEGRO_KEY_RIGHT:
    case ALLEGRO_KEY_D:
    case ALLEGRO_KEY_PAD_6:
        chara->facingRight=0;
        nextX=x+1;
        nextNextX=x+2;
        break;
    default:
        return 0;
        break;
}

switch (box[nextX][nextY]->state)
{
    case BOUNDARY:
        return 0;  //invalid movement
        break;

    case EMPTY:
        al_play_sample(res->CharaMove,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
        chara->state=CH_MOVE;
        x=nextX;    //move character
        y=nextY;
        break;

    case BLOCK:
        chara->state=CH_ATTAK;
        if (!box[nextNextX][nextNextY]->state) // if empty
            {
                al_play_sample(res->ObjHitten,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
                box[nextNextX][nextNextY]->state=box[nextX][nextY]->state; //move block
                box[nextX][nextY]->state=EMPTY;
            }
            al_play_sample(res->ObjHitten,0.3,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
        break;

    case MONSTER:
        chara->state=CH_ATTAK;
        if (box[nextNextX][nextNextY]->state)   //if not empty
        {
            al_play_sample(res->MonsterDie,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
            al_play_sample(res->ObjHitten,0.3,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
            box[nextX][nextY]->state=EMPTY; //kill
        }
        else
            {
            al_play_sample(res->MonsterHitten,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
            al_play_sample(res->ObjHitten,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
            box[nextNextX][nextNextY]->state=box[nextX][nextY]->state;     //move MONSTER
            box[nextX][nextY]->state=EMPTY;
            }
        break;

    case DOOR:
        if (chara->vulnerable) // with key
        {
            al_play_sample(res->DoorOpen,1.5,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
            chara->state=CH_MOVE;
            box[nextX][nextY]->state=EMPTY; // destroy door
            x=nextX;
            y=nextY;
        }

        else //without key
        {
            al_play_sample(res->ObjHitten,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
            chara->state=CH_ATTAK;
        }
        break;

    case EXIT:
        // win
        break;
}

if (box[x][y]->element==KEY)
    {
        chara->vulnerable=true; //possess key
        box[x][y]->element=EMPTY;
    }
    chara->life--;          //valid movement
    chara->x=x;
    chara->y=y;


return 1; //valid operate

}

void TrapFunc(STAGE *stage,RESOURCE *res,CONFIG *config)
{
    BOX*** box=stage->box;
    int x,y;
for (x=0;x<stage->boxNumX;x++)
    for(y=0;y<stage->boxNumY;y++)
        if(box[x][y]->element==FlexibleTrap)
        if(box[x][y]->damage)
            box[x][y]->damage=false;
        else
            box[x][y]->damage=true;

}

void drawChara (CHARA *chara,STAGE *stage,RESOURCE *res,CONFIG *config)
{

    al_draw_scaled_bitmap(res->chara,180*chara->step,0,180,180,stage->box[chara->x][chara->y]->x,stage->box[chara->x][chara->y]->y,
                      stage->length,stage->length,chara->facingRight);
}

void drawMap   (STAGE *stage,RESOURCE *res,CONFIG *config )
{
    BOX*** box=stage->box;
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
            case FlexibleTrap:
                if(box[x][y]->damage)
                    al_draw_scaled_bitmap(res->FlexSpikeOn,0,0,448,710,box[x][y]->x,box[x][y]->y,stage->length,stage->length,0);
                else
                    al_draw_scaled_bitmap(res->FlexSpikeOff,0,0,448,710,box[x][y]->x,box[x][y]->y,stage->length,stage->length,0);
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
            {
                stage->box[x][y]->state=NO;
                stage->box[x][y]->damage=NO;
                if (box[x][y]->y<=config->unit*21)
                {
                    box[x][y]->state=BLOCK;
                    box[x][y]->damage=DEATH;
                }
                else if(box[x][y]->y>=config->unit*67)
                {
                    box[x][y]->state=BLOCK;
                    box[x][y]->damage=DEATH;
                }

            }
        if(box[x][y]->y<0)
            {
                stage->box[x][y]->y=stage->box[x][y]->y+config->unit*81;
            }
        }
}
