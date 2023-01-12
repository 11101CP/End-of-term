#include "Game_frame.h"

void stageBOSS (BOX ***box)
{
    int x,y;
    for(x=0;x<9;x++)
    {
        box[x][0]->state=BLOCK;
        box[x][1]->state=BLOCK;
        box[x][7]->state=BLOCK;
        box[x][8]->state=BLOCK;
    }

    for(y=0;y<9;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[8][y]->state=BOUNDARY;
    }

}


void loadstage (BOX ***box,CONFIG *config,int stage)
{    /** stage1:0 , stage2:1440 stage3: 2880 stage4:4680 stage5:6080 stage6:7520 stage7: 9320 stage8: 10760 **/
    FILE *fptr;
    int x,y;
    BOX  tempBox;


    if((fptr = fopen ("./stage.bigpp","rb"))==NULL)
        printf("file open failed");


    switch(stage)
{case 1:
    fseek(fptr,0,SEEK_SET);
    break;
case 2:
    fseek(fptr,1440,SEEK_SET);
    break;
case 3:
    fseek(fptr,2880,SEEK_SET);
    break;
case 4:
    fseek(fptr,4680,SEEK_SET);
    break;
case 5:
    fseek(fptr,6080,SEEK_SET);
    break;
case 6:
    fseek(fptr,7520,SEEK_SET);
    break;
case 7:
    fseek(fptr,9320,SEEK_SET);
    break;
case 8:
    fseek(fptr,10760,SEEK_SET);
    break;
default:
    return 0;
}


    for(x=0;x<11;x++)
    {
        for(y=0;y<9;y++)
        {
        fread(&tempBox,sizeof(BOX),1,fptr);
        box[x][y]->damage=tempBox.damage;
        box[x][y]->element=tempBox.element;
        box[x][y]->state=tempBox.state;
        box[x][y]->x= tempBox.x*config->unit;
        box[x][y]->y= tempBox.y*config->unit;
        }
    }
    fclose(fptr);



}

