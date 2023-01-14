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

STATE state;
ELEMENT element;
bool damage;

}BOX;

int main()
{
    int x,y;

    BOX  box[9][10];

    printf("%d\n",sizeof(BOX));
    printf("%d\n",sizeof(box));

    for(x=0;x<9;x++)
        for(y=0;y<10;y++)
    {
        box[x][y].damage=false;
        box[x][y].element=0;
        box[x][y].state=0;
    }





    for(x=0;x<9;x++)
    {
        box[x][0].state=BOUNDARY;
        box[x][9].state=BOUNDARY;
    }
    for(y=0;y<10;y++)
    {
        box[0][y].state=BOUNDARY;
        box[1][y].state=BOUNDARY;
        box[8][y].state=BOUNDARY;
    }
    box[1][3].state=EMPTY;
    for(x=5;x<8;x++)
        for(y=1;y<4;y++)
        box[x][y].state=BOUNDARY;
    for(x=2;x<5;x++)
        for(y=7;y<10;y++)
        box[x][y].state=BOUNDARY;
    box[6][4].state=BOUNDARY;
    box[7][4].state=BOUNDARY;
    box[7][6].state=BOUNDARY;
    box[7][8].state=BOUNDARY;
    box[3][5].state=BOUNDARY;
    for(x=2;x<5;x++)
        box[x][2].state=BLOCK;
    box[3][4].state=BLOCK;
    box[4][5].state=BLOCK;
    box[4][6].state=BLOCK;
    box[5][5].state=BLOCK;
    box[6][7].state=BLOCK;
    box[2][5].state=MONSTER;
    box[6][6].state=MONSTER;
    box[4][3].element=KEY;
    box[5][7].state=DOOR;
    box[6][8].state=EXIT;
    box[2][4].element=SPIKYTRAP;/**closed**/
    box[3][4].element=SPIKYTRAP;/**closed**/





    for(y=0;y<10;y++)
    {for(x=0;x<9;x++)
        printf("%d ",box[x][y].state);
        puts ("");
        }



FILE *fptr;


if((fptr = fopen ("./stage.bigpp","ab"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),90,fptr);
    fclose(fptr);
    }




    return 0;
}
