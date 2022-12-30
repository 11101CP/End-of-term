#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"



int main()
{

    al_setup();

    CONFIG config;
    config.unit=12;

    ALLEGRO_DISPLAY *display=al_create_display(160*config.unit,90*config.unit);
    ALLEGRO_KEYBOARD_STATE KBstate;

    al_get_keyboard_state(&KBstate);
    while(!al_key_down(&KBstate, ALLEGRO_KEY_ESCAPE))
    {
    Game(&config);
    al_get_keyboard_state(&KBstate);
    }
    al_destroy_display(display);



    al_cleanup();
    return 0;
}



