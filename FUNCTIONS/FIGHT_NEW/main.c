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
    res.background=al_load_bitmap("./assets/beartrap.png");
    res.belt=al_load_bitmap("./assets/belt.png");
    res.chara=al_load_bitmap("./assets/duck.png");
    res.death=al_load_bitmap("./assets/death.png");
    res.saw=al_load_bitmap("./assets/saw.png");
    res.font=al_load_font("./assets/SoukouMincho.ttf",config.unit*15,0);


    gameSetUp(&config,&res);




    al_cleanup();
    return 0;
}



