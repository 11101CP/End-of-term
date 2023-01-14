
#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"


typedef struct
{

STATE state;
ELEMENT element;
bool damage;


}tempBox;

typedef struct
{

int numX;
int numY;
int boxLength;
int boxStartX;
int boxStartY;
int charaX;
int charaY;
int charaLife;
int seekFile;

}tempInfo;

void loadStageGOOD(STAGE *stage , CONFIG *config,int stageChoose)
{
    int x,y;
    tempInfo info;
    BOX*** box;
    int unit=config->unit;

    FILE *fptr;
    tempBox temp;


    if((fptr = fopen ("./stageinfo.bigpp","rb"))==NULL)  //loading info
        printf("file open failed");
    else
    {
        fseek(fptr,(stageChoose-1)*sizeof(tempInfo),SEEK_SET);
        fread(&info,sizeof(tempInfo),1,fptr);
    }

    stage->boxNumX=info.numX;
    stage->boxNumY=info.numY;
    stage->boxStartX=info.boxStartX*unit;
    stage->boxStartY=info.boxStartY*unit;
    stage->length=info.boxLength*unit;
    stage->stage=stageChoose;


    stage->chara->x = info.charaX;
    stage->chara->y = info.charaY;
    stage->chara->life = info.charaLife;

    buildBox(&stage->box,stage->boxNumX,stage->boxNumY);

    box = stage->box;



    if ((fptr = fopen ("./stage.bigpp","rb"))==NULL)  //loading boxes
        printf("file open failed");

        fseek(fptr,info.seekFile,SEEK_SET);




    for(x=0;x<info.numX;x++)
    {
        for(y=0;y<info.numY;y++)
        {
        fread(&temp,sizeof(tempBox),1,fptr);
        box[x][y]->damage=temp.damage;
        box[x][y]->element=temp.element;
        box[x][y]->state=temp.state;
        box[x][y]->x= stage->boxStartX+x*stage->length;
        box[x][y]->y= stage->boxStartY+y*stage->length;
        }
    }
    fclose(fptr);

 }
