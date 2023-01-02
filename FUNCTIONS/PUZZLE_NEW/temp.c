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

void stage1 (BOX ***box)
{
    int x,y;
    for(x=0;x<9;x++)
    {
        box[x][0]->state=BOUNDARY;
        box[x][7]->state=BOUNDARY;

    }

    for(x=1;x<5;x++)
    {
        box[x][1]->state=BOUNDARY;
    }

    for(x=3;x<7;x++)
    {
        box[x][4]->state=BOUNDARY;
    }

    box[1][2]->state=BOUNDARY;
    box[1][3]->state=BOUNDARY;
    for(y=0;y<8;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[8][y]->state=BOUNDARY;
    }
    box[6][3]->state=BOUNDARY;
    for(y=1;y<6;y++)
    {
        box[7][y]->state=BOUNDARY;
    }
    box[2][5]->state=BLOCK;
    box[2][6]->state=BLOCK;
    box[4][6]->state=BLOCK;
    box[5][5]->state=BLOCK;
    box[7][6]->state=EXIT;
    box[3][3]->state=MONSTER;
    box[4][2]->state=MONSTER;
    box[5][3]->state=MONSTER;
}

void stage2(BOX ***box)
{
    int x,y;
    for(x=0;x<9;x++)
    {
        box[x][0]->state=BOUNDARY;
        box[x][7]->state=BOUNDARY;
    }
    for(y=0;y<8;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[8][y]->state=BOUNDARY;
    }
    box[1][1]->state=BOUNDARY;
    box[1][2]->state=BOUNDARY;
    box[1][6]->state=BOUNDARY;
    box[2][6]->state=BOUNDARY;
    for(y=2;y<7;y++)
        box[3][y]->state=BOUNDARY;
    for(y=3;y<7;y++)
        box[4][y]->state=BOUNDARY;
    box[6][1]->state=BOUNDARY;
    box[7][1]->state=BOUNDARY;
    box[2][2]->state=MONSTER;
    box[6][5]->state=MONSTER;
    box[7][6]->state=MONSTER;
    for(x=5;x<8;x++)
        box[x][3]->state=BLOCK;
    box[5][6]->state=EXIT;
    box[2][3]->damage=HURT;
    box[4][2]->damage=HURT;
    box[5][2]->damage=HURT;
    box[5][3]->damage=HURT;
    box[6][3]->damage=HURT;
    box[6][4]->damage=HURT;

}
void stage3(BOX ***box)
{
    int x,y;
    for(x=0;x<9;x++)
    {
        box[x][0]->state=BOUNDARY;
        box[x][8]->state=BOUNDARY;
    }
    for(y=0;y<9;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[9][y]->state=BOUNDARY;
    }
    for(y=1;y<6;y++)
    {
        box[1][y]->state=BOUNDARY;
        box[2][y]->state=BOUNDARY;
    }
    box[2][6]->state=BOUNDARY;
    box[3][1]->state=BOUNDARY;
    for(x=0;x<7;x++)
        box[x][2]->state=BOUNDARY;
    box[8][1]->state=BOUNDARY;
    box[8][2]->state=BOUNDARY;
    box[8][5]->state=BOUNDARY;
    box[8][6]->state=BOUNDARY;
    box[8][7]->state=BOUNDARY;
    box[4][4]->state=BOUNDARY;
    box[4][6]->state=BOUNDARY;
    box[6][4]->state=BOUNDARY;
    box[6][6]->state=BOUNDARY;
    box[3][4]->damage=HURT;
    box[4][3]->damage=HURT;
    box[5][3]->damage=HURT;
    box[5][4]->damage=HURT;
    box[3][6]->damage=HURT;
    box[5][6]->damage=HURT;
    box[6][5]->damage=HURT;
    box[7][5]->damage=HURT;
    box[5][5]->state=MONSTER;
    box[6][7]->state=MONSTER;
    box[7][2]->state=DOOR;
    box[1][6]->state=KEY;
    box[4][1]->state=EXIT;

}
void stage4(BOX ***box)
{
    int x,y;
    for(x=0;x<10;x++)
    {
        box[x][0]->state=BOUNDARY;
        box[x][6]->state=BOUNDARY;
    }
    for(y=0;y<7;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[9][y]->state=BOUNDARY;
    }
    box[2][1]->state=BOUNDARY;
    box[6][1]->state=BOUNDARY;
    box[7][1]->state=BOUNDARY;
    box[8][1]->state=BOUNDARY;
    box[8][2]->state=BOUNDARY;
    box[1][5]->state=BOUNDARY;
    box[7][5]->state=BOUNDARY;
    box[8][5]->state=BOUNDARY;
    box[5][1]->state=BLOCK;
    box[3][3]->state=BLOCK;
    box[5][5]->state=BLOCK;
    box[4][4]->state=BLOCK;
    box[2][4]->state=BLOCK;
    box[3][5]->state=BLOCK;
    box[2][2]->state=BLOCK;
    box[4][2]->state=BLOCK;
    box[1][3]->state=BLOCK;
    box[5][3]->state=BLOCK;
    box[6][3]->state=BLOCK;
    box[6][4]->state=BLOCK;
    box[7][4]->state=BLOCK;
    box[3][2]->damage=HURT;
    box[4][2]->damage=HURT;
    box[3][1]->state=KEY;
    box[6][2]->state=DOOR;
    box[8][3]->state=EXIT;
}
void stage9(BOX ***box)
{
    int x,y;
    for(x=0;x<11;x++)
    {
        box[x][0]->state=BOUNDARY;
        box[x][1]->state=BOUNDARY;
        box[x][8]->state=BOUNDARY;
    }
    for(y=0;y<9;y++)
    {
        box[0][y]->state=BOUNDARY;
        box[10][y]->state=BOUNDARY;
    }
    box[1][1]->state=BOUNDARY;
    box[1][2]->state=BOUNDARY;
    box[1][3]->state=BOUNDARY;
    box[1][4]->state=BOUNDARY;
    box[2][1]->state=BOUNDARY;
    box[2][2]->state=BOUNDARY;
    box[2][3]->state=BOUNDARY;
    box[3][1]->state=BOUNDARY;
    box[3][2]->state=BOUNDARY;
    box[3][3]->state=BOUNDARY;
    box[3][4]->state=BOUNDARY;
    box[7][1]->state=BOUNDARY;
    box[7][2]->state=BOUNDARY;
    box[7][3]->state=BOUNDARY;
    box[7][4]->state=BOUNDARY;
    box[8][1]->state=BOUNDARY;
    box[8][2]->state=BOUNDARY;
    box[8][3]->state=BOUNDARY;
    box[9][1]->state=BOUNDARY;
    box[9][2]->state=BOUNDARY;
    box[9][3]->state=BOUNDARY;
    box[9][4]->state=BOUNDARY;
    box[1][7]->state=BOUNDARY;
    box[9][7]->state=BOUNDARY;
    for(y=3;y<8;y++)
        box[4][y]->state=BLOCK;
    box[1][5]->state=BLOCK;
    box[2][4]->state=BLOCK;
    box[2][6]->state=BLOCK;
    box[3][6]->state=BLOCK;
    box[4][5]->state=BLOCK;
    box[5][5]->state=BLOCK;
    box[6][5]->state=BLOCK;
    box[6][3]->state=BLOCK;
    box[7][6]->state=BLOCK;
    box[7][7]->state=BLOCK;
    box[8][6]->state=BLOCK;
    box[9][5]->state=KEY;
    box[5][3]->state=DOOR;
    box[5][1]->state=EXIT;
}
