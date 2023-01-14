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

    BOX  box[8][9];

    printf("%d\n",sizeof(BOX));
    printf("%d\n",sizeof(box));

    for(x=0;x<8;x++)
        for(y=0;y<9;y++)
    {
        box[x][y].damage=false;
        box[x][y].element=0;
        box[x][y].state=0;
    }





   for(x=0;x<8;x++)
    {
        box[x][0].state=BOUNDARY;
        box[x][8].state=BOUNDARY;
    }
    for(y=0;y<9;y++)
    {
        box[0][y].state=BOUNDARY;
        box[7][y].state=BOUNDARY;
    }
    box[1][1].state=BOUNDARY;
    box[1][2].state=BOUNDARY;
    for(y=1;y<6;y++)
    {
        box[2][y].state=BOUNDARY;
    }
    for(x=1;x<6;x++)
    {
        box[x][7].state=BOUNDARY;
    }
    box[6][7].element=KEY;
    box[3][1].state=BOUNDARY;
    box[6][1].state=BOUNDARY;
    box[1][5].state=MONSTER;
    for(x=3;x<7;x++)
    {
    box[x][5].state=BLOCK;
    }
    box[5][2].state=BLOCK;
    box[5][3].state=BLOCK;
    box[4][2].state=DOOR;
    box[1][6].element=TRAP;/**closed**/
    box[3][6].element=TRAP;/**closed**/
    box[6][6].element=TRAP;/**closed**/
    box[6][4].element=TRAP;/**closed**/
    box[4][4].element=TRAP;/**closed**/
    box[3][3].element=TRAP;/**closed**/



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
    fwrite(box,sizeof(BOX),90,fptr);
    fclose(fptr);
    }




    return 0;
}
