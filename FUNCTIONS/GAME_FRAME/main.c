#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"



int main()
{

    al_setup();

    CONFIG config;
    config.unit=12;

    ALLEGRO_DISPLAY *display=al_create_display(160*config.unit,90*config.unit);

    Game(&config);

    al_destroy_display(display);



    al_cleanup();
    return 0;
}



