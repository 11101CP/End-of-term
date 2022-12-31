#include "Common.h"
#include "AL_general.h"
//#include<allegro.h>
void Rank(CONFIG *config)
{
    int unit,finish=0;
    config->unit=unit;
    unit=8;
    ALLEGRO_FONT*font=al_load_font("./arial.ttf",config->unit*4,0);
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue =al_create_event_queue();
    ALLEGRO_EVENT events;
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_wait_for_event(event_queue, &events);
    ALLEGRO_KEYBOARD_EVENT keyboard1;
    char c;
    char *key_name;
    while(finish == 0)
    {
        char *key;
        char c;
        if(!al_is_event_queue_empty(event_queue))
        {
            while(al_get_next_event(event_queue, &events))
            {
                switch(events.type)
                {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    finish = 1;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    if(events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    {
                        finish = 1;
                    }
                    key= al_keycode_to_name(events.keyboard.keycode);
                    c=key[0];
                    printf("%c",c);

                    break;
                }
            }
        }
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }
}








