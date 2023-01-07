#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

void stageBOSS (BOX ***box);
void loadStage(STAGE *stage ,CONFIG *config);
void loadBox  (BOX ***box,int x,int y,int unit);
void buildBox (BOX ****box,int x,int y);


bool gameSetUp(CONFIG *config,RESOURCE *res)
{
    STAGE stage;
    loadStage(&stage,config);
    //loadStageRes

    bool mode=true;
    //stageBOSS (stage.box);/**start(4,4) stage9x9**/
    //stage1(stage.box);/**start (6,1) stage 9x8**/
    //stage2(stage.box);/**start (1,5) stage 9x8**/
    //stage3(stage.box);/**start (8,3) stage 10x10**/
    //stage4(stage.box);/**start (1,1) stage 10x7**/
    //stage5(stage.box);/**start (1,3) stage 8x9**/
    //stage6(stage.box);/**start (3,1) stage 9x10**/
    stage7(stage.box);/**start (6,5) stage 8x9**/
    //stage9(stage.box);/**start (2,7) stage 11x9**/



    if (mode)
        Fight(config,&stage,res);

    else
        Game(config,&stage,res);

    //destroyStageRes
    //destroyStage
}

void loadStage(STAGE *stage ,CONFIG *config)
{

    //Åª¨ú .dat ±q config->stage

    stage->boxNumX=8;/**stage**/
    stage->boxNumY=9;
    stage->length=config->unit*9;
    buildBox(&stage->box,stage->boxNumX,stage->boxNumY);
    loadBox (stage->box,stage->boxNumX,stage->boxNumY,config->unit);

}

void loadBox  (BOX ***box,int x,int y,int unit) //stage 1
{
    int i,j;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
        {
            box[i][j]->x= (40+9*i)*unit;
            box[i][j]->y= (4+9*j)*unit;
            //box[i][j]->state=DAMAGE;
            box[i][j]->state = EMPTY;
            box[i][j]->damage = NO;
        }



}


void buildBox (BOX ****box,int x,int y)
{
    int i,j;

    BOX ***row=NULL;
    BOX **col=NULL;
    BOX *item=NULL;

    row=calloc(x,sizeof(BOX **));

    for(i=0;i<x;i++)
    {
        col=calloc (y,sizeof(BOX *));
        for(j=0;j<y;j++)
        {
            item=calloc(1,sizeof(BOX));
            col[j]=item;
        }
        row[i]=col;

    }

    *box=row;
}
