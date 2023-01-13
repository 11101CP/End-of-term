#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"
#include "Loading_enum.h"

void boxShift(STAGE *stage,RESOURCE *res,CONFIG *config )
{
    BOX*** box=stage->box;
    int x,y;

for (x=0;x<stage->boxNumX;x++)
    for(y=0;y<stage->boxNumY;y++)
      {stage->box[x][y]->y-=config->unit;

        if(box[x][y]->y < stage->boxStartY)
            {
                stage->box[x][y]->y=stage->box[x][y]->y+config->unit*81;
            }
      }


}




