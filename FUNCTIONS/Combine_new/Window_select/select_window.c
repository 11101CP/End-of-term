#include "Game_select.h"

static void drawSelectWindow( RESOURCE *res, CONFIG *config,int control);

int SelectWindow (RESOURCE *res, CONFIG *config)
{
    int unit=config->unit;
    int control = 1;

    LoadSelectResource(res,config);

    ALLEGRO_EVENT events;
    drawSelectWindow(res,config,control);
    al_flip_display();

    while (1)
    {
        al_wait_for_event(res->queues, &events);
        if(events.type==ALLEGRO_EVENT_KEY_CHAR)
            {
            switch(events.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                case ALLEGRO_KEY_W:
                case ALLEGRO_KEY_DOWN:
                case ALLEGRO_KEY_S:
                    if (control>8)
                        control=1;
                    else
                        control=9;
                    break;

                case ALLEGRO_KEY_LEFT:
                case ALLEGRO_KEY_A:
                    if(control<9)
                        {if(--control==0)
                            control=1;}
                    else
                        {if(--control==8)
                            control=9;}
                    break;

                case ALLEGRO_KEY_RIGHT:
                case ALLEGRO_KEY_D:
                    if(control<9)
                        {if(++control==9)
                            control=8;}
                    else
                        {if(++control==12)
                            control=11;}
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    destroySelectResource (res);
                    return 0;
                    break;

                case ALLEGRO_KEY_ENTER:
                    destroySelectResource (res);
                    return control;
                    break;

            }
            drawSelectWindow(res,config,control);
            al_flip_display();

        }

    } //end of while (1)

}




static void drawSelectWindow( RESOURCE *res, CONFIG *config,int control)
{
    int i;
    int stage=2;
    int unit=config->unit;

    al_draw_scaled_bitmap(res->bitmaps[Cover], 0, 0,al_get_bitmap_width(res->bitmaps[Cover]),al_get_bitmap_height(res->bitmaps[Cover]),0 ,0,160*unit,90*unit,0);

    for(i=1;i<stage;i++)
        al_draw_scaled_bitmap(res->bitmaps[BreakEgg],0,0,125,200,i*(unit*160)/9-16*unit,4*(unit*90)/5,unit*13,unit*18,0);
    al_draw_scaled_bitmap(res->bitmaps[CrackedEgg],0,0,125,150,stage*(unit*160)/9-16*unit,4*(unit*90)/5,unit*13,unit*18,0);

    for(i=9;i-stage>0;i--)
    {
    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,i*(unit*160)/9-16*unit,4*(unit*90)/5,unit*13,unit*18,0);
    }
    al_draw_scaled_bitmap(res->bitmaps[Skeleton],0,0,225,155,9*(unit*160)/9-15.5*unit,4.2*(unit*90)/5,unit*12,unit*9,0);
    al_draw_scaled_bitmap(res->bitmaps[Arrow],0, 0, 85, 150, control*(unit*160)/9-12*unit, 3.3*(unit*90)/5, unit*5,unit*10, 0);
    char *s[8]={"I","II","III","IV","V","VI","VII","VIII",};
    for(i=0;i<8;i++)
    al_draw_textf(res->fonts[1],al_map_rgb(96,78,78),(i+1)*unit*160/9-9.5*unit,4.3*unit*90/5,ALLEGRO_ALIGN_CENTER,s[i]);
    al_flip_display();
}


