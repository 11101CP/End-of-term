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

    BOX  box[11][6];

    printf("%d\n",sizeof(BOX));
    printf("%d\n",sizeof(box));

    for(x=0;x<11;x++)
        for(y=0;y<6;y++)
    {
        box[x][y].damage=false;
        box[x][y].element=0;
        box[x][y].state=0;

    }


    for(y=0;y<6;y++)
    {
        box[0][y].state = BOUNDARY;
        box[10][y].state = BOUNDARY;
    }
    for(x=0;x<11;x++)
    {
        box[x][0].state = BOUNDARY;
        box[x][5].state = BOUNDARY;
    }

    for(y=0;y<6;y++)
    {for(x=0;x<11;x++)
        printf("%d ",box[x][y].state);
        puts ("");
        }



FILE *fptr;


if((fptr = fopen ("./stage.bigpp","ab"))==NULL)
    printf("file open failed");
else
    {
    fwrite(box,sizeof(BOX),66,fptr);
    fclose(fptr);
    }




    return 0;
}
