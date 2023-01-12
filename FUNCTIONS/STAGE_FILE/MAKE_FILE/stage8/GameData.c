#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

typedef enum
{

EMPTY=0,
BLOCK,
BOUNDARY,
MONSTER,
DOOR,
EXIT

}STATE;

typedef enum
{

KEY=1,
TRAP,
SPIKYTRAP

}ELEMENT;

typedef struct
{

int x;
int y;
STATE state;
ELEMENT element;
bool damage;

}BOX;

int main()
{
    int x,y;

    BOX  box[11][9];

    printf("%d\n",sizeof(BOX));
    printf("%d\n",sizeof(box));

    for(x=0;x<11;x++)
        for(y=0;y<9;y++)
    {
        box[x][y].damage=false;
        box[x][y].element=0;
        box[x][y].state=0;
        box[x][y].x=40+x*9;
        box[x][y].y=4+y*9;
    }




for(x=0;x<11;x++)
    {
        box[x][0].state=BOUNDARY;
        box[x][1].state=BOUNDARY;
        box[x][8].state=BOUNDARY;
    }
    for(y=0;y<9;y++)
    {
        box[0][y].state=BOUNDARY;
        box[10][y].state=BOUNDARY;
    }
    box[1][1].state=BOUNDARY;
    box[1][2].state=BOUNDARY;
    box[1][3].state=BOUNDARY;
    box[1][4].state=BOUNDARY;
    box[2][1].state=BOUNDARY;
    box[2][2].state=BOUNDARY;
    box[2][3].state=BOUNDARY;
    box[3][1].state=BOUNDARY;
    box[3][2].state=BOUNDARY;
    box[3][3].state=BOUNDARY;
    box[3][4].state=BOUNDARY;
    box[7][1].state=BOUNDARY;
    box[7][2].state=BOUNDARY;
    box[7][3].state=BOUNDARY;
    box[7][4].state=BOUNDARY;
    box[8][1].state=BOUNDARY;
    box[8][2].state=BOUNDARY;
    box[8][3].state=BOUNDARY;
    box[9][1].state=BOUNDARY;
    box[9][2].state=BOUNDARY;
    box[9][3].state=BOUNDARY;
    box[9][4].state=BOUNDARY;
    box[1][7].state=BOUNDARY;
    box[9][7].state=BOUNDARY;
    for(y=3;y<8;y++)
        box[4][y].state=BLOCK;
    box[1][5].state=BLOCK;
    box[2][4].state=BLOCK;
    box[2][6].state=BLOCK;
    box[3][6].state=BLOCK;
    box[4][5].state=BLOCK;
    box[5][5].state=BLOCK;
    box[6][5].state=BLOCK;
    box[6][3].state=BLOCK;
    box[7][6].state=BLOCK;
    box[7][7].state=BLOCK;
    box[8][6].state=BLOCK;
    box[9][5].element=KEY;
    box[5][3].state=DOOR;
    box[5][1].state=EXIT;




    for(y=0;y<9;y++)
    {for(x=0;x<8;x++)
        printf("%d ",box[x][y].state);
        puts ("");
        }



FILE *fptr;


if((fptr = fopen ("./stage.bigpp","ab"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),99,fptr);
    fclose(fptr);
    }




    return 0;
}
