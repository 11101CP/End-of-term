#include "AL_general.h"
#include "config_struct.h"

int main()
{

    CONFIG config;

    al_setup();

    if( ! configUI(&config) )
        return 0;

    ALLEGRO_DISPLAY *display=al_create_display(config.unit*160,config.unit*90);

    al_clear_to_color(al_map_rgb(150,150,150));
    al_flip_display();

    system("pause");
    al_destroy_display(display);

    al_cleanup();


return 0;
}



