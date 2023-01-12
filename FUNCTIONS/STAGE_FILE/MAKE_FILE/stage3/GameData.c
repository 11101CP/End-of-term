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
TRAP

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

    BOX  box[10][9];

    printf("%d\n",sizeof(BOX));
    printf("%d\n",sizeof(box));

    for(x=0;x<10;x++)
        for(y=0;y<9;y++)
    {
        box[x][y].damage=false;
        box[x][y].element=0;
        box[x][y].state=0;
        box[x][y].x=40+x*9;
        box[x][y].y=4+y*9;
    }


    for(x=0;x<9;x++)
    {
        box[x][0].state=BOUNDARY;
        box[x][8].state=BOUNDARY;
    }
    for(y=0;y<9;y++)
    {
        box[0][y].state=BOUNDARY;
        box[9][y].state=BOUNDARY;
    }
    for(y=1;y<6;y++)
    {
        box[1][y].state=BOUNDARY;
        box[2][y].state=BOUNDARY;
    }
    box[2][6].state=BOUNDARY;
    box[3][1].state=BOUNDARY;
    for(x=0;x<7;x++)
        box[x][2].state=BOUNDARY;
    box[8][1].state=BOUNDARY;
    box[8][2].state=BOUNDARY;
    box[8][5].state=BOUNDARY;
    box[8][6].state=BOUNDARY;
    box[8][7].state=BOUNDARY;
    box[4][4].state=BOUNDARY;
    box[4][6].state=BOUNDARY;
    box[6][4].state=BOUNDARY;
    box[6][6].state=BOUNDARY;
    box[3][4].element=TRAP;/**opened**/
    box[4][3].element=TRAP;/**opened**/
    box[5][3].element=TRAP;/**opened**/
    box[5][4].element=TRAP;/**opened**/
    box[3][6].element=TRAP;/**opened**/
    box[5][6].element=TRAP;/**opened**/
    box[6][5].element=TRAP;/**opened**/
    box[7][5].element=TRAP;/**opened**/


    box[3][4].damage=true;/**opened**/
    box[4][3].damage=true;/**opened**/
    box[5][3].damage=true;/**opened**/
    box[5][4].damage=true;/**opened**/
    box[3][6].damage=true;/**opened**/
    box[5][6].damage=true;/**opened**/
    box[6][5].damage=true;/**opened**/
    box[7][5].damage=true;/**opened**/

    box[5][5].state=MONSTER;
    box[6][7].state=MONSTER;
    box[7][2].state=DOOR;
    box[1][6].element=KEY;
    box[4][1].state=EXIT;


    for(y=0;y<9;y++)
    {for(x=0;x<10;x++)
        printf("%d ",box[x][y].state);
        puts ("");
        }



FILE *fptr;


if((fptr = fopen ("./stage.bigpp","ab+"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),90,fptr);
    fclose(fptr);
    }




    return 0;
}
