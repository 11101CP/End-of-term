#include"AL_general.h"

void drawSettingPage(RESOURCE *res, CONFIG *config,unsigned short control)
{
    int unit;
    unit=config->unit;
    al_clear_to_color(al_map_rgb(150,150,150));
    if(control%4==0)
         al_draw_textf (res->fonts[1],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
        else al_draw_textf (res->fonts[1],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
        if(control%4==1)
        al_draw_textf (res->fonts[1],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
        else al_draw_textf (res->fonts[1],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
        if(control%4==2)
          al_draw_textf (res->fonts[1],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
        else  al_draw_textf (res->fonts[1],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
        if(control%4==3)
       al_draw_textf (res->fonts[1],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");
        else al_draw_textf (res->fonts[1],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");
        al_flip_display();
}
int SettingDetect(RESOURCE *res, CONFIG *config)
{

    unsigned short control = 0;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    ALLEGRO_EVENT events;
    drawSettingPage(res,config,control);
    al_flip_display();


    while (1)
    {

        if(!al_is_event_queue_empty(res->queues))
        {
            while(al_get_next_event(res->queues, &events))
            {

        al_wait_for_event(event_queue, &events);
        if(events.type==ALLEGRO_EVENT_KEY_DOWN)
            {
        if (events.keyboard.keycode == ALLEGRO_KEY_DOWN)
            control += 1;
        if (events.keyboard.keycode == ALLEGRO_KEY_UP)
            control -= 1;
        if(control%4 == 0)//GameResume
        {
            if(events.keyboard.keycode==ALLEGRO_KEY_ENTER)
                return 2;
        }
        if(control%4 == 1)//GameRestart
        {
            if(events.keyboard.keycode==ALLEGRO_KEY_ENTER)
                return 1;
        }

        if(control%4==2) //Sound
        {
            if (events.keyboard.keycode == ALLEGRO_KEY_LEFT)
           {    if(config->musicGain<0)
                {
                    config->musicGain=0;
                    config->soundGain=0;
                }
               else
                {
                    config->musicGain-=0.1;
                    config->soundGain-=0.1;
                }
           }
            if (events.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
               if(config->musicGain>1)
               {
                   config->musicGain=1;
                   config->soundGain=1;
               }
               else
               {
                   config->musicGain+=0.1;
                   config->soundGain+=0.1;
               }
           }
        }
        if (events.keyboard.keycode == ALLEGRO_KEY_ENTER)
            if(control%4==3) //GameQuit
            {
                if(events.keyboard.keycode==ALLEGRO_KEY_ENTER)
                    return 3;
            }

            }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        drawSettingPage(res,config,control);
        al_flip_display();
        }
        }
        }

}

