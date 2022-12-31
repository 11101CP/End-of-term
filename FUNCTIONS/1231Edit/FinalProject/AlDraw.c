#include "AlHeader.h"



void drawMenu( Resource *res, CONFIG *config)
{
    int unit;
    unit=config->unit;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* coverbitmap = NULL;
    ALLEGRO_BITMAP* playbutton = NULL;
    ALLEGRO_BITMAP* pressedplay = NULL;
    ALLEGRO_BITMAP* exitbutton = NULL;
    ALLEGRO_BITMAP* pressedexit = NULL;

    // Initialize Allegro
    al_init();
    al_init_image_addon();

    // Create allegro display
    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    // Load bitmap
    coverbitmap = al_load_bitmap("./cover.png");
    playbutton = al_load_bitmap("PlayButton.png");
    pressedplay = al_load_bitmap("PressedPlay.png");
    exitbutton = al_load_bitmap("ExitButton.png");
    pressedexit = al_load_bitmap("PressedExit.png");

    // Draw bitmap
    al_draw_bitmap(coverbitmap, 0, 0, 0);

    if(res->data.press==PLAY)
        al_draw_scaled_bitmap(pressedplay,0, 0, 210, 120, (unit*160/2)-unit*30, (unit*90/5)*3, unit*60,unit*90/5, 0);
    else al_draw_scaled_bitmap(playbutton, 0, 0, 210, 120, (unit*160/2)-unit*30, (unit*90/5)*3, unit*60,unit*90/5, 0); //create new file

    if(res->data.press==EXIT)
       al_draw_scaled_bitmap(pressedexit,0, 0, 210, 120, (unit*160/2)-unit*30, (unit*90/5)*4, unit*60,unit*90/5, 0);
    else al_draw_scaled_bitmap(exit,0, 0, 210, 120, (unit*160/2)-unit*30, (unit*90/5)*4, unit*60,unit*90/5, 0);


    al_flip_display();

    al_destroy_bitmap(coverbitmap);
    al_destroy_bitmap(playbutton);
    al_destroy_bitmap(pressedplay);
    al_destroy_bitmap(exitbutton);
    al_destroy_bitmap(pressedexit);
    al_destroy_display(display);

}

void drawStageMenu( Resource *res, CONFIG *config)
{
    int unit;
    unit=config->unit;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* coverbitmap = NULL;
    ALLEGRO_BITMAP* stage1button = NULL;
    ALLEGRO_BITMAP* stage2button = NULL;
    ALLEGRO_BITMAP* stage3button = NULL;
    ALLEGRO_BITMAP* stage4button = NULL;



    // Initialize Allegro
    al_init();
    al_init_image_addon();

    // Create allegro display
    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    // Load bitmap
    coverbitmap = al_load_bitmap("./cover.png");
    stage1button = al_load_bitmap("Stage1Button.png");
    stage2button = al_load_bitmap("Stage2Button.png");
    stage3button = al_load_bitmap("Stage3Button.png");
    stage4button = al_load_bitmap("Stage4Button.png");

    al_draw_bitmap(coverbitmap, 0, 0, 0);

    al_draw_scaled_bitmap(stage1button, 0, 0, 90, 120, 1*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);
    al_draw_scaled_bitmap(stage2button, 0, 0, 90, 120, 2*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);
    al_draw_scaled_bitmap(stage3button, 0, 0, 90, 120, 3*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);
    al_draw_scaled_bitmap(stage4button, 0, 0, 90, 120, 4*(unit*160)/5, unit*90-unit*16, unit*12, unit*16,0);

    al_flip_display();

    al_destroy_bitmap(coverbitmap);

    al_destroy_bitmap(stage1button);
    al_destroy_bitmap(stage2button);
    al_destroy_bitmap(stage3button);
    al_destroy_bitmap(stage4button);

}

void drawSettingPage(Resource *res, CONFIG *config)
{
    int unit;
   // unit=config->unit;
   unit=8;
    ALLEGRO_FONT *font=al_load_font("./arial.ttf",unit*4,0);

    if(font==NULL)
        puts("!!!!!");
    ALLEGRO_DISPLAY * display=al_create_display(160*unit,90*unit);

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
