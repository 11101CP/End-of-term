#include "Common.h"
#include "AL_general.h"



int main()
{

    al_setup();
    RESOURCE res;
    CONFIG config;

    config.unit=12;
    config.stage=9;


    res.display=al_create_display(160*config.unit,90*config.unit);

    gameSetUp(&config,&res,10); //stage boss 1




    al_cleanup();
    return 0;
}



