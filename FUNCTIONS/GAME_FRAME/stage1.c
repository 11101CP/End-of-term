#include "Game_frame.h"

void stage1 (BOX ***box)
{
    int x,y;
    for(x=0;x<9;x++)
    {
        box[x][0]->state=BLOCK;
        box[x][7]->state=BLOCK;
    }

    for(y=0;y<8;y++)
    {
        box[0][y]->state=BLOCK;
        box[8][y]->state=BLOCK;
    }
    box[1][0]->state=BLOCK;
    box[1][1]->state=BLOCK;
    box[1][2]->state=BLOCK;
    box[1][3]->state=BLOCK;
    box[2][1]->state=BLOCK;
    box[3][1]->state=BLOCK;
    box[4][1]->state=BLOCK;
    box[7][1]->state=BLOCK;
    box[7][2]->state=BLOCK;
    box[7][3]->state=BLOCK;
    box[6][3]->state=BLOCK;
    box[3][4]->state=BLOCK;
    box[4][4]->state=BLOCK;
    box[5][4]->state=BLOCK;
    box[6][4]->state=BLOCK;
    box[7][4]->state=BLOCK;
    box[7][5]->state=BLOCK;

}
