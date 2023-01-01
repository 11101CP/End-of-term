#include "Common.h"
#include "AL_general.h"
#include<stdio.h>
#include<time.h>

void Timer(CONFIG *config)
{
    int finish=0;
    ALLEGRO_FONT*font = al_load_font("SoukouMincho.ttf", config->unit*4, 0);
    ALLEGRO_TIMER* timer=al_create_timer(1.0);
    ALLEGRO_TIMER* FPS=al_create_timer(1.0/60);
    ALLEGRO_EVENT_QUEUE* event_queue = NULL; /* create event queue */
    ALLEGRO_EVENT events;
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(FPS));
    al_start_timer(FPS);
    al_start_timer(timer);
    while(finish == 0)
    {
    if(0<=al_get_timer_count(timer)%60&&al_get_timer_count(timer)%60<=9)
    al_draw_textf(font,al_map_rgb(255,255,255),160*config->unit,0,ALLEGRO_ALIGN_RIGHT,"%2d:0%d",al_get_timer_count(timer)/60,al_get_timer_count(timer)%60);
    else
    al_draw_textf(font,al_map_rgb(255,255,255),160*config->unit,0,ALLEGRO_ALIGN_RIGHT,"%2d:%2d",al_get_timer_count(timer)/60,al_get_timer_count(timer)%60);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    }
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}









