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
        box[x][0]->damage=DEATH;
        box[x][1]->damage=DEATH;
        box[x][7]->damage=DEATH;
        box[x][8]->damage=DEATH;

    }

    for(y=0;y<9;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[8][y]->state=BOUNDARY;

    }

}
