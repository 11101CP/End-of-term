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

    for(y=0;y<8;y++)
    {
        box[0][y]->state=BLOCK;
        box[8][y]->state=BLOCK;
    }

}

