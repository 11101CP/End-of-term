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
    bool exit=false;


    //loadStageRes

    bool mode=true;


loadBossFightResource(res,config);




while(!exit)
{

loadStage(&stage,config,stageChoose);


Fight(config,&stage,res ); //return true if end
clearStage(&stage);

}
destroyBossFightResource(res);

}


void clearStage(STAGE *stage)
{


    freeBox(stage->box,stage->boxNumX,stage->boxNumY);
    stage->box=NULL;
    clearAttack(stage);
    stage->attack=NULL;
    printf("here");

    stage->boxNumX=0;
    stage->boxStartX=0;
    stage->boxStartY=0;
    stage->length=0;

}

void loadStage(STAGE *stage ,CONFIG *config,int stageChoose)
{

    //Åª¨ú .dat ±q config->stage

    stage->boxStartX = 40*config->unit;
    stage->boxStartY = 4*config->unit ;
    stage->boxNumX=9;
    stage->boxNumY=9;
    stage->length=config->unit*9;

    buildBox(&stage->box,stage->boxNumX,stage->boxNumY);
    loadBox (stage->box,stage->boxNumX,stage->boxNumY,config->unit);
    stage->progess=0;

    stageBOSS (stage->box);
    loadAttack(stage);
    loadChara (stage);

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

void freeBox (BOX ***box,int x,int y)
{int i,j;
    for (i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
        free(box[i][j]);
        }
        free(box[i]);
    }
    free(box);
    *box=NULL;
}

