
#include "AL_general.h"
#include "config_struct.h"

void preGameSetup(RESOURCE *res,CONFIG *config)
{
    if(config->fullscreen)
        {
            al_set_new_display_flags(ALLEGRO_WINDOWED);
            al_set_new_display_flags(ALLEGRO_RESIZABLE);
            res->display=al_create_display(160*config->unit,90*config->unit);
            al_set_display_flag(res->display, ALLEGRO_FRAMELESS, true);
            al_set_display_flag(res->display, ALLEGRO_MAXIMIZED, true);
        }
    else res->display=al_create_display(160*config->unit,90*config->unit);

    res->queues=al_create_event_queue();


    al_register_event_source(res->queues, al_get_display_event_source(res->display));
    al_register_event_source(res->queues, al_get_keyboard_event_source());


    al_set_window_title(res->display, "What da QUACK");
    al_hide_mouse_cursor(res->display);


    ALLEGRO_BITMAP *temp;
    temp=al_load_bitmap("./assets/icon.png");
    al_set_display_icon(res->display, temp);
    al_destroy_bitmap(temp);



}
