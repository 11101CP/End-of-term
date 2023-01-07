#include "Common.h"
#include "AL_general.h"



int main()
{

    al_setup();
    RESOURCE res;
    CONFIG config;

    config.fullscreen=true;
    config.unit=12;
    config.stage=9;

    //al_set_new_display_flags(ALLEGRO_WINDOWED);
    //al_set_new_display_flags(ALLEGRO_RESIZABLE);
    res.display=al_create_display(160*config.unit,90*config.unit);
    //al_set_display_flag(res.display, ALLEGRO_FRAMELESS, true);
    //al_set_display_flag(res.display, ALLEGRO_MAXIMIZED, true);

    gameSetUp(&config,&res,10); //stage boss 1




    al_cleanup();
    return 0;
}



