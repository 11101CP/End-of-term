#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>



typedef struct
{

int numX;
int numY;
int boxLength;
int boxStartX;
int boxStartY;
int charaX;
int charaY;
int charaLife;
int seekFile;

}STAGEINFO;

int main()
{
    int x,y;





STAGEINFO info[10];

info[0].numX=9;
info[0].numY=8;
info[0].charaX=6;
info[0].charaY=1;
info[0].charaLife=23;
info[0].seekFile=0;


info[1].numX=9;
info[1].numY=8;
info[1].charaX=1;
info[1].charaY=5;
info[1].charaLife=24;
info[1].seekFile=1440;


info[2].numX=10;
info[2].numY=9;
info[2].charaX=8;
info[2].charaY=3;
info[2].charaLife=32;
info[2].seekFile=2880;

info[3].numX=10;
info[3].numY=7;
info[3].charaX=1;
info[3].charaY=1;
info[3].charaLife=23;
info[3].seekFile=4680;

info[4].numX=8;
info[4].numY=9;
info[4].charaX=1;
info[4].charaY=3;
info[4].charaLife=23;
info[4].seekFile=6080;


info[5].numX=9;
info[5].numY=10;
info[5].charaX=3;
info[5].charaY=1;
info[5].charaLife=43;
info[5].seekFile=7520;


info[6].numX=8;
info[6].numY=9;
info[6].charaX=6;
info[6].charaY=5;
info[6].charaLife=32;
info[6].seekFile=9320;


info[7].numX=11;
info[7].numY=9;
info[7].charaX=2;
info[7].charaY=7;
info[7].charaLife=33;
info[7].seekFile=10760;

//
//info[8].numX=
//info[8].numY=
//info[8].charaX=
//info[8].charaY=
//info[8].charaLife=
//info[8].seekFile=0;

FILE *fptr;

if((fptr = fopen ("./stageInfo.bigpp","wb+"))==NULL)
    printf("file open failed");
else
    {
    fwrite(info,sizeof(STAGEINFO),7,fptr);
    fclose(fptr);
    }




    return 0;
}
