#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"


void drawChara (CHARA *chara,STAGE *stage,RESOURCE *res,CONFIG *config)
{


if(chara->state==CH_MOVE)
{al_draw_scaled_bitmap(res->chara,180*chara->step,0,180,180,
    stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,stage->length,stage->length,chara->facingRight);

if(!chara->vulnerable)
    al_draw_tinted_scaled_bitmap(res->chara,al_map_rgba(100,0,0,100),180*chara->step,0,180,180,stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,
                      stage->length,stage->length,chara->facingRight);}

else if (chara->state==CH_STAY)
{al_draw_scaled_bitmap(res->chara,180*chara->step,180,180,180,stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,
                      stage->length,stage->length,chara->facingRight);

if(!chara->vulnerable)
    al_draw_tinted_scaled_bitmap(res->chara,al_map_rgba(100,0,0,100),180*chara->step,180,180,180,stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,
                      stage->length,stage->length,chara->facingRight);}

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


//for (x=0;x<stage->boxNumX;x++)
//    for(y=0;y<stage->boxNumY;y++)
//        switch(box[x][y]->state)
//        {
//            case BOUNDARY:
//               // al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgba(0,100,0,5));
//                break;
//            case BLOCK:
//                al_draw_scaled_bitmap(res->background,0,0,1000,1000,box[x][y]->x,box[x][y]->y,stage->length,stage->length,0);
//        }




}

