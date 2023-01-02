#include "AL_general.h"
void drawMenu(Resource *res, CONFIG *config, unsigned short control)
{
    int unit;
    unit=config->unit;
    ALLEGRO_BITMAP* coverbitmap = al_load_bitmap("image/cover.png");
    ALLEGRO_BITMAP* playbutton = al_load_bitmap("image/PlayButton.png");
    ALLEGRO_BITMAP* pressedplay =al_load_bitmap("./image/PressedPlay.png");
    ALLEGRO_BITMAP* exitbutton = al_load_bitmap("./image/ExitButton.png");
    ALLEGRO_BITMAP* pressedexit =al_load_bitmap("./image/PressedExit.png");
    al_draw_scaled_bitmap(coverbitmap, 0, 0,al_get_bitmap_width(coverbitmap),al_get_bitmap_height(coverbitmap),0 ,0,160*unit,90*unit,0);

        if(control%2==0)
        al_draw_scaled_bitmap(pressedplay,0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*3, unit*30,unit*9, 0);
        else al_draw_scaled_bitmap(playbutton,0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*3, unit*30,unit*9, 0);
        if(control%2==1)
        al_draw_scaled_bitmap(pressedexit,0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*4, unit*30,unit*9, 0);
        else al_draw_scaled_bitmap(exitbutton,0, 0, 210, 120, (unit*160/2)-unit*15, (unit*90/5)*4, unit*30,unit*9, 0);

//   system("pause");
    al_destroy_bitmap(coverbitmap);
    al_destroy_bitmap(playbutton);
    al_destroy_bitmap(pressedplay);
    al_destroy_bitmap(exitbutton);
    al_destroy_bitmap(pressedexit);

}

void drawStageMenu( Resource *res, CONFIG *config)
{
    int unit;
    unit=config->unit;
    al_setup();
    ALLEGRO_BITMAP* coverbitmap =al_load_bitmap("./image/cover.png");
    ALLEGRO_BITMAP* stage1button=al_load_bitmap("./image/Stage1Button.png");
    ALLEGRO_BITMAP* stage2button=al_load_bitmap("./image/Stage2Button.png");
    ALLEGRO_BITMAP* stage3button=al_load_bitmap("./image/Stage3Button.png");
    ALLEGRO_BITMAP* stage4button=al_load_bitmap("./image/Stage4Button.png");

    al_draw_scaled_bitmap(coverbitmap, 0, 0,al_get_bitmap_width(coverbitmap),al_get_bitmap_height(coverbitmap),0 ,0,160*unit,90*unit,0);
    al_draw_scaled_bitmap(stage1button, 0, 0, 90, 120, 1*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);
    al_draw_scaled_bitmap(stage2button, 0, 0, 90, 120, 2*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);
    al_draw_scaled_bitmap(stage3button, 0, 0, 90, 120, 3*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);
    al_draw_scaled_bitmap(stage4button, 0, 0, 90, 120, 4*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);

    al_flip_display();
   system("pause");
    al_destroy_bitmap(coverbitmap);
    al_destroy_bitmap(stage1button);
    al_destroy_bitmap(stage2button);
    al_destroy_bitmap(stage3button);
    al_destroy_bitmap(stage4button);

}

void drawSettingPage(Resource *res, CONFIG *config)
{
    int unit;
    unit=8;
    ALLEGRO_FONT *font=al_load_font("arial.ttf",unit*4,0);

    if(font==NULL)
        puts("!!!!!");


    al_clear_to_color(al_map_rgb(150,150,150));

    if(res->data.press==RESUME)
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
    else
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
    if(res->data.press==RESTART)
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
    else
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
    if(res->data.press==SOUND)
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
    else
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
    if(res->data.press==MENU)
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");
    else
        al_draw_textf (font,al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");

        al_flip_display();
        system("pause");
        al_destroy_font(res->font);
}

bool KeyboardDetect(Resource *res, CONFIG *config)
{

    unsigned short control = 0;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
ALLEGRO_EVENT events;
drawMenu(res, config, control);
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
        if (events.keyboard.keycode == ALLEGRO_KEY_ENTER)
            if(control%2==0)
            return true;
        else
            return false;
            }

        al_clear_to_color(al_map_rgb(0, 0, 0)); // 清除畫面
        drawMenu(res, config, control);
        printf("%d\n",control);

        al_flip_display();
       // al_rest(0.2);
    }
    return false;
}
