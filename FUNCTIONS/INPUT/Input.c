#include "Common.h"
#include "AL_general.h"
#include<stdio.h>
#include<time.h>

void Input(CONFIG *config)
{

    int finish=0,i=0;
    char s[4],c;
    ALLEGRO_FONT*font=al_load_font("SoukouMincho.ttf",config->unit*4,0);
    ALLEGRO_EVENT_QUEUE* event_queue =al_create_event_queue();
    ALLEGRO_EVENT events;
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_wait_for_event(event_queue, &events);
    while(finish == 0)
    {
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
                    if(events.keyboard.keycode == ALLEGRO_KEY_ESCAPE||events.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    {
                        finish = 1;
                    }
                    break;
                case ALLEGRO_EVENT_KEY_CHAR:
                    if((48<=events.keyboard.unichar&&events.keyboard.unichar<=57)||events.keyboard.unichar==32||(65<=events.keyboard.unichar&&events.keyboard.unichar<=122))
                    {   c=events.keyboard.unichar;
                        s[i]=c;
                        s[i+1]='\0';
                        i++;
                        printf("%s\n",s);
                        if(events.keyboard.keycode=ALLEGRO_KEY_ENTER)
                        s[i]=0;}
                    break;

                }
            }
        }
        al_draw_text(font, al_map_rgb(255,255,255), 0,0,ALLEGRO_ALIGN_CENTER,s);
        al_flip_display();
        al_clear_to_color(al_map_rgb(100, 0, 0));
    }
}








