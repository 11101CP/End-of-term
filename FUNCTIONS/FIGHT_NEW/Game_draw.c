#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"
#include "Loading_enum.h"

void drawMap   (STAGE *stage,RESOURCE *res,CONFIG *config )
{
    BOX*** box=stage->box;
    al_draw_scaled_bitmap(res->bitmaps[Background],0,0,1649,940,0,0,160*config->unit,90*config->unit,0);

    al_draw_scaled_bitmap(res->bitmaps[Belt],0,0,400,1125,stage->boxStartX+stage->length,stage->boxStartY-stage->length-config->unit*(al_get_timer_count(res->timers[BeltSheft])%9),stage->length*7,stage->length*12,0);

    al_draw_scaled_bitmap(res->bitmaps[Saw],0,600*(al_get_timer_count(res->timers[Refresh])%2),1688,600,stage->boxStartX+stage->length,stage->boxStartY+stage->length,stage->length*7,stage->length,0);
    al_draw_scaled_bitmap(res->bitmaps[Saw],0,600*(al_get_timer_count(res->timers[Refresh])%2),1688,600,stage->boxStartX+stage->length,stage->boxStartY+7*stage->length,stage->length*7,stage->length,0);
    //al_draw_scaled_bitmap(res->bitmaps[Layer],0,0,960,540,0,0,160*config->unit,90*config->unit,0);

} //end of draw map



void drawObject(STAGE *stage,RESOURCE *res,CONFIG *config )
{


     drawChara(stage,res,config);
     drawAttack(stage,res,config);
     drawLifaIndicate (stage,res,config );

    BOX*** box=stage->box;
    int x,y;



for (x=0;x<stage->boxNumX;x++)
    for(y=0;y<stage->boxNumY;y++)
    {//al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgba(0,100,0,5));
        switch(box[x][y]->state)
        {
            case MONSTER:
                al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+stage->length,box[x][y]->y+stage->length,al_map_rgba(0,100,0,5));
                break;
           // case BLOCK:
                //al_draw_scaled_bitmap(res->background,0,0,1000,1000,box[x][y]->x,box[x][y]->y,stage->length,stage->length,0);
        }
        }


}//end of draw object





void drawChara (STAGE *stage,RESOURCE *res,CONFIG *config)
{
CHARA *chara=stage->chara;
int x= stage->box[chara->x][chara->y]->x;
int y= stage->box[chara->x][chara->y]->y;


if(chara->state==CH_MOVE)
{
    al_draw_scaled_bitmap(res->bitmaps[Chara],180*chara->step,0,180,180,
    x+chara->offsetX,y+chara->offsetY,
    stage->length,stage->length,chara->facingRight);

    if(!chara->vulnerable)
        al_draw_tinted_scaled_bitmap(res->bitmaps[Chara],al_map_rgba(100,0,0,100),
        180*chara->step,0,180,180,x+chara->offsetX,y+chara->offsetY,
        stage->length,stage->length,chara->facingRight);
}//chara->state==CH_MOVE

else if (chara->state==CH_STAY)
{
    al_draw_scaled_bitmap(res->bitmaps[Chara],180*chara->step,180,180,180,
    x+chara->offsetX,y+chara->offsetY,stage->length,stage->length,chara->facingRight);

if(!chara->vulnerable)
    al_draw_tinted_scaled_bitmap(res->bitmaps[Chara],al_map_rgba(100,0,0,100),
    180*chara->step,180,180,180,x+chara->offsetX,y+chara->offsetY,
    stage->length,stage->length,chara->facingRight);
} //chara->state==CH_STAY

else if(chara->state==CH_ATTACK)
{
    al_draw_scaled_bitmap(res->bitmaps[Chara],180*chara->step,360,180,180,x+chara->offsetX,y+chara->offsetY,stage->length,stage->length,chara->facingRight);
    al_draw_tinted_scaled_bitmap(res->bitmaps[Chara],al_map_rgba(100,0,0,100),180*chara->step,360,180,180,x+chara->offsetX,y+chara->offsetY,stage->length,stage->length,chara->facingRight);

} //chara->state==CH_ATTACK


}//end of draw chara

void drawLifaIndicate (STAGE *stage,RESOURCE *res,CONFIG *config )
{
switch(stage->chara->life)
{
case 4:
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


}//end of draw life indicate



