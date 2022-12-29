#include "Common.h"
#include "AL_general.h"
#include "GAME_frame.h"


bool Game(CONFIG *config)
{
    int unit=config->unit;
    BOX ***box;
    buildBox (&box,9,8);
    loadBox  (box, 9 , 8 , unit);

    system("pause");

    freeBox (box,9,8);


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


void loadBox  (BOX ***box,int x,int y,int unit) //stage 1
{
    int i,j;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
        {
            box[i][j]->x= (40+9*i)*unit;
            box[i][j]->y= (8+9*j)*unit;
            //box[i][j]->state=DAMAGE;
        }



}

void freeBox (BOX ***box,int x,int y)
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
            {
            free (box[i][j]);
            }
        free (box[i]);
    }
    free (box);

}
