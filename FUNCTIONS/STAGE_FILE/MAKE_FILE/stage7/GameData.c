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
    for(x=1;x<4;x++)
        for(y=1;y<3;y++)
        box[x][y].state=BOUNDARY;
    box[3][3].state=BOUNDARY;
    box[6][1].state=BOUNDARY;
    box[5][7].state=BOUNDARY;
    box[5][6].state=BOUNDARY;
    box[6][7].state=BOUNDARY;
    box[6][6].state=BOUNDARY;
    box[2][5].state=BOUNDARY;
    box[2][6].state=BOUNDARY;
    box[3][6].state=BOUNDARY;
    box[4][3].state=BLOCK;
    box[2][4].state=BLOCK;
    box[5][3].state=BLOCK;
    box[5][4].state=BLOCK;
    box[6][3].state=BLOCK;
    box[4][4].state=MONSTER;
    box[1][4].state=MONSTER;
    box[3][5].state=MONSTER;
    box[2][3].element=KEY;
    box[4][1].state=EXIT;
    box[5][2].state=DOOR;
    box[1][6].element=SPIKYTRAP;/**opened**/
    box[2][7].element=SPIKYTRAP;/**opened**/
    box[4][7].element=SPIKYTRAP;/**opened**/

    box[1][6].damage=true;/**opened**/
    box[2][7].damage=true;/**opened**/
    box[4][7].damage=true;/**opened**/

    box[1][7].element=SPIKYTRAP;/**closed**/
    box[3][7].element=SPIKYTRAP;/**closed**/
    box[4][6].element=SPIKYTRAP;/**closed**/





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
    fwrite(box,sizeof(BOX),72,fptr);
    fclose(fptr);
    }




    return 0;
}
