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
    box[6][1]->state=CHARC;
    box[7][6]->state=EXIT;
    box[3][3]->state=MONSTER;
    box[4][2]->state=MONSTER;
    box[5][3]->state=MONSTER;
    box[2][5]->state=BRICK;
    box[2][6]->state=BRICK;
    box[4][6]->state=BRICK;
    box[5][5]->state=BRICK;
    box[1][4]->state=EMPTY;
    box[1][5]->state=EMPTY;
    box[1][6]->state=EMPTY;
    box[3][5]->state=EMPTY;
    box[3][6]->state=EMPTY;
    box[4][5]->state=EMPTY;
    box[5][6]->state=EMPTY;
    box[6][5]->state=EMPTY;
    box[6][6]->state=EMPTY;
    box[2][2]->state=EMPTY;
    box[2][3]->state=EMPTY;
    box[2][4]->state=EMPTY;
    box[4][3]->state=EMPTY;
    box[3][2]->state=EMPTY;
    box[5][1]->state=EMPTY;
    box[5][2]->state=EMPTY;
    box[6][2]->state=EMPTY;
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
