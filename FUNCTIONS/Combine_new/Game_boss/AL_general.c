#include "AL_general.h"

void al_setup(void)
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();

    al_init_image_addon();
    al_init_primitives_addon();

    al_init_acodec_addon();
    al_reserve_samples(9);
    al_init_font_addon();
    al_init_ttf_addon();
}


void al_cleanup(void)
{
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_uninstall_audio();
}

