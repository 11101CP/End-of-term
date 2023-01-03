#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"


void stageBOSS (BOX ***box);
void loadStage(STAGE *stage ,CONFIG *config,int stageChoose);
void loadBox  (BOX ***box,int x,int y,int unit);
void buildBox (BOX ****box,int x,int y);


bool gameSetUp(CONFIG *config,RESOURCE *res,int stageChoose)
{
    STAGE stage;
    stage.progess=0;

    //loadStageRes

    bool mode=true;

loadStage(&stage,config,stageChoose);

while(1)
{
    if (mode)
        if( Fight(config,&stage,res) ) //return true if end
        break;
    else
        break;
}

    //destroyStageRes
    //destroyStage
}

void loadStage(STAGE *stage ,CONFIG *config,int stageChoose)
{

    //Åª¨ú .dat ±q config->stage

    stage->boxNumX=9;
    stage->boxNumY=9;
    stage->length=config->unit*9;
    buildBox(&stage->box,stage->boxNumX,stage->boxNumY);
    loadBox (stage->box,stage->boxNumX,stage->boxNumY,config->unit);
    stage->progess=0;

    stageBOSS (stage->box);

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
