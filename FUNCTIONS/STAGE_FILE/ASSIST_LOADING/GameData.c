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


STAGEINFO info[11];


info[0].numX=9;
info[0].numY=8;
info[0].charaX=6;
info[0].charaY=1;
info[0].charaLife=23;
info[0].seekFile=0;
info[0].boxStartX=40;
info[0].boxStartY=4;
info[0].boxLength=9;


info[1].numX=9;
info[1].numY=8;
info[1].charaX=1;
info[1].charaY=5;
info[1].charaLife=24;
info[1].seekFile=864;
info[1].boxStartX=40;
info[1].boxStartY=4;
info[1].boxLength=9;


info[2].numX=10;
info[2].numY=9;
info[2].charaX=8;
info[2].charaY=3;
info[2].charaLife=34;
info[2].seekFile=1728;
info[2].boxStartX=35;
info[2].boxStartY=4;
info[2].boxLength=9;

info[3].numX=10;
info[3].numY=7;
info[3].charaX=1;
info[3].charaY=1;
info[3].charaLife=23;
info[3].seekFile=2808;
info[3].boxStartX=35;
info[3].boxStartY=4;
info[3].boxLength=9;

info[4].numX=8;
info[4].numY=9;
info[4].charaX=1;
info[4].charaY=3;
info[4].charaLife=23;
info[4].seekFile=3648;
info[4].boxStartX=45;
info[4].boxStartY=4;
info[4].boxLength=9;


info[5].numX=9;
info[5].numY=10;
info[5].charaX=3;
info[5].charaY=1;
info[5].charaLife=43;
info[5].seekFile=4728;
info[5].boxStartX=40;
info[5].boxStartY=0;
info[5].boxLength=9;


info[6].numX=8;
info[6].numY=9;
info[6].charaX=6;
info[6].charaY=5;
info[6].charaLife=32;
info[6].seekFile=5808;
info[6].boxStartX=45;
info[6].boxStartY=4;
info[6].boxLength=9;


info[7].numX=11;
info[7].numY=9;
info[7].charaX=2;
info[7].charaY=7;
info[7].charaLife=33;
info[7].seekFile=6672;
info[7].boxStartX=30;
info[7].boxStartY=4;
info[7].boxLength=9;

info[8].numX=9;
info[8].numY=9;
info[8].charaX=2;
info[8].charaY=7;
info[8].charaLife=33;
info[8].seekFile=7860;
info[8].boxStartX=40;
info[8].boxStartY=4;
info[8].boxLength=9;

info[9].numX=11;
info[9].numY=6;
info[9].charaX=2;
info[9].charaY=7;
info[9].charaLife=33;
info[9].seekFile=8832;
info[9].boxStartX=40;
info[9].boxStartY=30;
info[9].boxLength=9;

//info[10].numX=11;
//info[10].numY=9;
//info[10].charaX=2;
//info[10].charaY=7;
//info[10].charaLife=33;
//info[10].seekFile=9624;
//info[10].boxStartX=40;
//info[10].boxStartY=0;
//info[10].boxLength=9;


FILE *fptr;

printf("%d",sizeof(STAGEINFO));




if((fptr = fopen ("./stageinfo.bigpp","wb+"))==NULL)
    printf("file open failed");
else
    {
   // for(int i=0;i<10;i++)
        //{
            fwrite( info , sizeof(STAGEINFO) , 10 , fptr);
            //printf("\n%x",&info[i]);}
    }
fclose(fptr);



    return 0;
}
