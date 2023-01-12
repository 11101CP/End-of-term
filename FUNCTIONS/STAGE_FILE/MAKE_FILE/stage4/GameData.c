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

    BOX  box[10][7];

    printf("%d\n",sizeof(BOX));
    printf("%d\n",sizeof(box));

    for(x=0;x<10;x++)
        for(y=0;y<7;y++)
    {
        box[x][y].damage=false;
        box[x][y].element=0;
        box[x][y].state=0;
        box[x][y].x=40+x*9;
        box[x][y].y=4+y*9;
    }






    for(x=0;x<10;x++)
    {
        box[x][0].state=BOUNDARY;
        box[x][6].state=BOUNDARY;
    }
    for(y=0;y<7;y++)
    {
        box[0][y].state=BOUNDARY;
        box[9][y].state=BOUNDARY;
    }


    box[2][1].state=BOUNDARY;
    box[6][1].state=BOUNDARY;
    box[7][1].state=BOUNDARY;
    box[8][1].state=BOUNDARY;
    box[8][2].state=BOUNDARY;
    box[1][5].state=BOUNDARY;
    box[7][5].state=BOUNDARY;
    box[8][5].state=BOUNDARY;
    box[5][1].state=BLOCK;
    box[3][3].state=BLOCK;
    box[5][5].state=BLOCK;
    box[4][4].state=BLOCK;
    box[2][4].state=BLOCK;
    box[3][5].state=BLOCK;
    box[2][2].state=BLOCK;
    box[4][2].state=BLOCK;
    box[1][3].state=BLOCK;
    box[5][3].state=BLOCK;
    box[6][3].state=BLOCK;
    box[6][4].state=BLOCK;
    box[7][4].state=BLOCK;
    box[3][2].element=TRAP;/**opened**/
    box[4][2].element=TRAP;/**opened**/

    box[3][2].damage=true;/**opened**/
    box[4][2].damage=true;/**opened**/

    box[3][1].element=KEY;
    box[6][2].state=DOOR;
    box[8][3].state=EXIT;


    for(y=0;y<9;y++)
    {for(x=0;x<10;x++)
        printf("%d ",box[x][y].state);
        puts ("");
        }



FILE *fptr;


if((fptr = fopen ("./stage.bigpp","ab"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),70,fptr);
    fclose(fptr);
    }




    return 0;
}
