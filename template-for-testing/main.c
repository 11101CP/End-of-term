#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


int main()
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

/*---------------set up---------------*/



return 0;
}



