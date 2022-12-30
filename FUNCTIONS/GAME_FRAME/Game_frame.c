#include "Common.h"
#include "AL_general.h"
#include "GAME_frame.h"


bool Game(CONFIG *config)
{
    int unit=config->unit;
    BOX ***box;
    buildBox (&box,9,8);
    loadBox  (box, 9 , 8 , unit);
    stage1 (box);

    al_clear_to_color(al_map_rgb(250,250,250));
    al_draw_filled_rectangle(40*unit,9*unit,121*unit,81*unit,al_map_rgb(50,50,50));

            al_rest(0.05);
    for (int x=0;x<9;x++)
        for(int y=0;y<8;y++)
            switch(box[x][y]->state)
            {
            case CHARC:
            al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(255,0,0));
            break;
            case BLOCK:
            al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(0,0,0));
            break;
            case EMPTY:
            al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(255,255,255));
            break;
            case MONSTER:
            al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(255,165,0));
            break;
            case BRICK:
            al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(50,150,0));
            break;
            case EXIT:
            al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(255,215,0));
            break;
            }


    al_flip_display();

    //system("pause");

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
            box[i][j]->y= (9+9*j)*unit;
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
