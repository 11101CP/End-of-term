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

    FILE *fptr;
if((fptr = fopen ("./stage.dat","wb+"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),72,fptr);
    fclose(fptr);
    }




    for(x=0;x<9;x++)
    {
        box[x][0].state=BOUNDARY;
        box[x][7].state=BOUNDARY;

    }

    for(x=1;x<5;x++)
    {
        box[x][1].state=BOUNDARY;
    }

    for(x=3;x<7;x++)
    {
        box[x][4].state=BOUNDARY;
    }

    box[1][2].state=BOUNDARY;
    box[1][3].state=BOUNDARY;
    for(y=0;y<8;y++)
    {
        box[0][y].state=BOUNDARY;
        box[8][y].state=BOUNDARY;
    }
    box[6][3].state=BOUNDARY;
    for(y=1;y<6;y++)
    {
        box[7][y].state=BOUNDARY;
    }
    box[2][5].state=BLOCK;
    box[2][6].state=BLOCK;
    box[4][6].state=BLOCK;
    box[5][5].state=BLOCK;
    box[7][6].state=EXIT;
    box[3][3].state=MONSTER;
    box[4][2].state=MONSTER;
    box[5][3].state=MONSTER;


    for(y=0;y<8;y++)
    {for(x=0;x<9;x++)
        printf("%d ",box[x][y].state);
        puts ("");
        }






if((fptr = fopen ("./stage.dat","wb+"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),72,fptr);
    fclose(fptr);
    }




    return 0;
}
