#include "Common.h"
#include "AL_general.h"



int main()
{

    al_setup();
    CONFIG config;
    config.unit=8;
    config.stage=9;

  //  (config,);
    RESOURCE res;
    res.display=al_create_display(160*config.unit,90*config.unit);
    res.trap=al_load_bitmap("./beartrap.png");
    res.block=al_load_bitmap("./Brick.png");
    res.belt=al_load_bitmap("./belt.png");
    res.chara=al_load_bitmap("./duck.png");
    res.fonts=al_load_font("./Type,ttf",config.unit*5,0);
    res.FlexSpikeOn=al_load_bitmap("./SpikeOn.png");
    res.FlexSpikeOff=al_load_bitmap("./SpikeOff.png");


    //al_draw_text(res.fonts,al_map_rgb(255,255,255),0,0,0,"50");

    gameSetUp(&config,&res);




    al_cleanup();
    return 0;
}



