#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"


void drawChara (CHARA *chara,STAGE *stage,RESOURCE *res,CONFIG *config)
{


//if(chara->state==CH_MOVE)
{al_draw_scaled_bitmap(res->bitmaps[Chara],180*chara->step,0,180,180,
    stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,stage->length,stage->length,chara->facingRight);

if(!chara->vulnerable)
    al_draw_tinted_scaled_bitmap(res->bitmaps[Chara],al_map_rgba(100,0,0,100),180*chara->step,0,180,180,stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,
                      stage->length,stage->length,chara->facingRight);}

//else if (chara->state==CH_STAY)
//{al_draw_scaled_bitmap(res->chara,180*chara->step,180,180,180,stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,
//                      stage->length,stage->length,chara->facingRight);
//
//if(!chara->vulnerable)
//    al_draw_tinted_scaled_bitmap(res->chara,al_map_rgba(100,0,0,100),180*chara->step,180,180,180,stage->box[chara->x][chara->y]->x+chara->offsetX,stage->box[chara->x][chara->y]->y+chara->offsetY,
//                      stage->length,stage->length,chara->facingRight);}

}

void drawLifaIndicate (STAGE *stage,RESOURCE *res,CONFIG *config )
{
switch(stage->chara->life)
{case 4:
    al_draw_scaled_bitmap(res->bitmaps[Life],0,0,500,250,0,config->unit*70,config->unit*50,config->unit*25,0);
    break;
case 3:
    al_draw_scaled_bitmap(res->bitmaps[Life],500,0,500,250,0,config->unit*70,config->unit*50,config->unit*25,0);
    break;
case 2:
    al_draw_scaled_bitmap(res->bitmaps[Life],0,250,500,250,0,config->unit*70,config->unit*50,config->unit*25,0);

    break;
default:
    al_draw_scaled_bitmap(res->bitmaps[Life],500,250,500,250,0,config->unit*70,config->unit*50,config->unit*25,0);

    break;
}


}


void drawMap   (STAGE *stage,RESOURCE *res,CONFIG *config )
{BOX*** box=stage->box;
    int x,y;
al_draw_scaled_bitmap(res->bitmaps[Background],0,0,1649,940,0,0,160*config->unit,90*config->unit,0);
//for (x=0;x<stage->boxNumX;x++)
//    for(y=0;y<stage->boxNumY;y++)
//        al_draw_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgb(0,0,0),1);





}
void drawObject(STAGE *stage,RESOURCE *res,CONFIG *config )
{
    BOX*** box=stage->box;
    int x,y;



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

