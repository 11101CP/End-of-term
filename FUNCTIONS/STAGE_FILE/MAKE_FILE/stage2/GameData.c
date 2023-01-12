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

    BOX  box[9][8];

    printf("%d\n",sizeof(BOX));
    printf("%d\n",sizeof(box));

    for (x=0;x<9;x++)
        for(y=0;y<8;y++)
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
        box[x][7].state=BOUNDARY;
    }
    for(y=0;y<8;y++)
    {
        box[0][y].state=BOUNDARY;
        box[8][y].state=BOUNDARY;
    }
    box[1][1].state=BOUNDARY;
    box[1][2].state=BOUNDARY;
    box[1][6].state=BOUNDARY;
    box[2][6].state=BOUNDARY;
    for(y=2;y<7;y++)
        box[3][y].state=BOUNDARY;
    for(y=3;y<7;y++)
        box[4][y].state=BOUNDARY;
    box[6][1].state=BOUNDARY;
    box[7][1].state=BOUNDARY;
    box[2][2].state=MONSTER;
    box[6][5].state=MONSTER;
    box[7][6].state=MONSTER;
    for(x=5;x<8;x++)
        box[x][3].state=BLOCK;
    box[5][6].state=EXIT;
    box[2][3].element=TRAP;
    box[4][2].element=TRAP;
    box[5][2].element=TRAP;
    box[5][3].element=TRAP;
    box[6][3].element=TRAP;
    box[6][4].element=TRAP;
    box[2][3].damage=true;
    box[4][2].damage=true;
    box[5][2].damage=true;
    box[5][3].damage=true;
    box[6][3].damage=true;
    box[6][4].damage=true;


    for(y=0;y<8;y++)
    {for(x=0;x<9;x++)
        printf("%d ",box[x][y].state);
        puts ("");
        }



FILE *fptr;


if((fptr = fopen ("./stage.bigpp","ab+"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),72,fptr);
    fclose(fptr);
    }




    return 0;
}
