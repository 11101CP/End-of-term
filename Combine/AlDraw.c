#include "AL_general.h"
#include "Common.h"
#include "Loading_enum.h"
void drawMenu(RESOURCE *res, CONFIG *config, unsigned short control)
{
    int unit;
    unit=config->unit;
    al_draw_scaled_bitmap(res->bitmaps[Cover], 0, 0,al_get_bitmap_width(res->bitmaps[Cover]),al_get_bitmap_height(res->bitmaps[Cover]),0 ,0,160*unit,90*unit,0);

        if(control%2==0)
        al_draw_scaled_bitmap(res->bitmaps[PressedPlay],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*3, unit*30,unit*9, 0);
        else al_draw_scaled_bitmap(res->bitmaps[PlayButton],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*3, unit*30,unit*9, 0);
        if(control%2==1)
        al_draw_scaled_bitmap(res->bitmaps[PressedExit],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*4, unit*30,unit*9, 0);
        else al_draw_scaled_bitmap(res->bitmaps[ExitButton],0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*4, unit*30,unit*9, 0);

}

void drawStageMenu( RESOURCE *res, CONFIG *config)
{
    int unit,stage=2,i=0;
    unit=config->unit;

    al_draw_scaled_bitmap(res->bitmaps[Cover], 0, 0,al_get_bitmap_width(res->bitmaps[Cover]),al_get_bitmap_height(res->bitmaps[Cover]),0 ,0,160*unit,90*unit,0);
    for(i=1;i<=stage;i++)
    {//al_draw_scaled_bitmap(res->bitmaps[BreakEgg],0,0,125,200,i*(unit*160)/5-16*unit,3*(unit*90)/5,unit*13,unit*18,0);
    al_draw_scaled_bitmap(res->bitmaps[BreakEgg],0,0,125,200,i*(unit*160)/9-16*unit,4*(unit*90)/5,unit*13,unit*18,0);}
    for(i=9;i-stage>0;i--)
    {//al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,i*(unit*160)/5-16*unit,3*(unit*90)/5,unit*13,unit*18,0);
    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,i*(unit*160)/9-16*unit,4*(unit*90)/5,unit*13,unit*18,0);
    }
    al_draw_scaled_bitmap(res->bitmaps[Skeleton],0,0,225,155,9*(unit*160)/9-15.5*unit,4.2*(unit*90)/5,unit*12,unit*9,0);

//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,1*(unit*160)/5,3*(unit*90)/5,unit*13,unit*18,0);
//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,2*(unit*160)/5,3*(unit*90)/5,unit*13,unit*18,0);
//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,3*(unit*160)/5,3*(unit*90)/5,unit*13,unit*18,0);
//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,4*(unit*160)/5,3*(unit*90)/5,unit*13,unit*18,0);
//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,1*(unit*160)/5,4*(unit*90)/5,unit*13,unit*18,0);
//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,2*(unit*160)/5,4*(unit*90)/5,unit*13,unit*18,0);
//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,3*(unit*160)/5,4*(unit*90)/5,unit*13,unit*18,0);
//    al_draw_scaled_bitmap(res->bitmaps[Egg],0,0,125,150,4*(unit*160)/5,4*(unit*90)/5,unit*13,unit*18,0);
    al_flip_display();
    system("pause");
}

void drawSettingPage(RESOURCE *res, CONFIG *config,unsigned short control)
{
    int unit;
    unit=8;
    al_clear_to_color(al_map_rgb(150,150,150));
    if(control%4==0)
         al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
        else al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
        if(control%4==1)
        al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
        else al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
        if(control%4==2)
          al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
        else  al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
        if(control%4==3)
       al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");
        else al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");
        al_flip_display();
}

bool Windows(RESOURCE *res, CONFIG *config)
{
    LoadDrawResource(res,config);
    unsigned short control = 0;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
ALLEGRO_EVENT events;

//drawMenu(res, config, control);
drawStageMenu(res, config);
al_flip_display();
system("pause");
    while (events.keyboard.keycode!=ALLEGRO_KEY_ESCAPE)
    {

        al_wait_for_event(event_queue, &events);
        if(events.type==ALLEGRO_EVENT_KEY_DOWN)
            {
        if (events.keyboard.keycode == ALLEGRO_KEY_DOWN)
            control += 1;
        if (events.keyboard.keycode == ALLEGRO_KEY_UP)
            control -= 1;
        if (events.keyboard.keycode == ALLEGRO_KEY_ENTER)
            if(control%2==0)
            return true;
        else
            return false;
            }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        drawMenu(res, config, control);
        al_flip_display();
    }
    return false;
}
bool SettingDetect(RESOURCE *res, CONFIG *config)
{

    unsigned short control = 0;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    ALLEGRO_EVENT events;
    drawSettingPage(res,config,control);
    al_flip_display();
    while (events.keyboard.keycode!=ALLEGRO_KEY_ESCAPE)
    {

        al_wait_for_event(event_queue, &events);
        if(events.type==ALLEGRO_EVENT_KEY_DOWN)
            {
        if (events.keyboard.keycode == ALLEGRO_KEY_DOWN)
            control += 1;
        if (events.keyboard.keycode == ALLEGRO_KEY_UP)
            control -= 1;
        if(control%4==2)
        {
            if (events.keyboard.keycode == ALLEGRO_KEY_LEFT)
           {
               config->musicGain-=0.1;
               config->soundGain-=0.1;
           }
            if (events.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
               config->musicGain+=0.1;
               config->soundGain+=0.1;
           }
        }
        if (events.keyboard.keycode == ALLEGRO_KEY_ENTER)
            if(control%4==MENU)
            return true;
            }

        al_clear_to_color(al_map_rgb(0, 0, 0));
        drawSettingPage(res,config,control);
        al_flip_display();
    }
    return false;
}
