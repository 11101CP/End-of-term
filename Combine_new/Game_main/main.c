#include "AL_general.h"


int main()
{
    int stageChoose;
    RESOURCE res;
    CONFIG config;

    al_setup();



    if( ! configUI(&config,&res) )
        return 0;                   //end if user press quit

    preGameSetup(&res,&config);

    while(HomeWindow(&res,&config)) // true if not exit
    {
       stageChoose=SelectWindow(&res,&config); //return stage select

    //if (stageChoose)//if choose a stage



       //else break;
    }





    al_cleanup();


return 0;
}



