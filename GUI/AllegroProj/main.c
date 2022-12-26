#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "UI_struct.h"

int main()
{


    Config config;


    al_init(); /* initialize Allegro */
    al_install_keyboard(); /* install the keyboard for Allegro to use */
    al_install_mouse();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();



    configUI(&config);




return 0;
}



