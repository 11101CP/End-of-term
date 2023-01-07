#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

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
