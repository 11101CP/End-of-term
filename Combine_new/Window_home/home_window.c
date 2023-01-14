#include"Game_home.h"

static void drawHomeWindow(RESOURCE *res, CONFIG *config, bool play);


bool HomeWindow(RESOURCE *res, CONFIG *config)
{
    ALLEGRO_EVENT events;
    bool play=true;

    LoadHomeResource(res,config);

    drawHomeWindow(res, config, play);
    al_flip_display();

    while (1)
    {
    al_wait_for_event(res->queues,&events);

        if(events.type==ALLEGRO_EVENT_KEY_CHAR)
            {
                switch(events.keyboard.keycode)
                {
                    case ALLEGRO_KEY_UP:
                    case ALLEGRO_KEY_DOWN:
                    case ALLEGRO_KEY_LEFT:
                    case ALLEGRO_KEY_RIGHT:
                    case ALLEGRO_KEY_W:
                    case ALLEGRO_KEY_A:
                    case ALLEGRO_KEY_S:
                    case ALLEGRO_KEY_D:
                        if(play)
                            play=false;
                        else
                            play=true;

                        drawHomeWindow(res, config, play);
                        al_flip_display();

                        break;
                    case ALLEGRO_KEY_ENTER:
                        destroyHomeResource(res);
                        return play;
                        break;
                }

            }
    }//end of while(1)
}


static void drawHomeWindow(RESOURCE *res, CONFIG *config, bool play)
{
    int unit;
    unit=config->unit;
    al_draw_scaled_bitmap(res->bitmaps[Cover], 0, 0,al_get_bitmap_width(res->bitmaps[Cover]),al_get_bitmap_height(res->bitmaps[Cover]),0 ,0,160*unit,90*unit,0);

    if(play)
    al_draw_scaled_bitmap(res->bitmaps[PressedPlay],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*3, unit*30,unit*9, 0);
    else al_draw_scaled_bitmap(res->bitmaps[PlayButton],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*3, unit*30,unit*9, 0);

    if(!play)
    al_draw_scaled_bitmap(res->bitmaps[PressedExit],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*4, unit*30,unit*9, 0);
    else al_draw_scaled_bitmap(res->bitmaps[ExitButton],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*4, unit*30,unit*9, 0);

}
