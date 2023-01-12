#include "Common.h"
#include "AL_general.h"



int main()
{

    al_setup();
    CONFIG config;
    config.unit=12;
    config.stage=9;

  //  (config,);
    RESOURCE res;
    res.display=al_create_display(160*config.unit,90*config.unit);
    res.trap=al_load_bitmap("./beartrap.png");
    res.block=al_load_bitmap("./Brick.png");
    res.belt=al_load_bitmap("./belt.png");
    res.chara=al_load_bitmap("./duck.png");


    gameSetUp(&config,&res);




    al_cleanup();
    return 0;
}



