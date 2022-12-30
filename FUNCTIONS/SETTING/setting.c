#include"Common.h"
#include"AL_general.h"
#include"GUI_general.h"
void Setting(CONFIG *config)
{
    int i;
    config->unit=8;
    puts("1");
    ALLEGRO_FONT *font=al_load_font("./arial.ttf",config->unit*4,0);
    ALLEGRO_DISPLAY * display=al_create_display(160*config->unit,90*config->unit);
    ALLEGRO_BITMAP * sett=al_load_bitmap("sett.png");
    ALLEGRO_BITMAP * line=al_load_bitmap("realline.png");
    al_clear_to_color(al_map_rgb(100,100,100));
    ALLEGRO_COLOR tint=al_map_rgba_f(1,1,1,0.9);
    ALLEGRO_BITMAP*bitmap=al_create_bitmap(160*config->unit,90*config->unit);
    al_clear_to_color(al_map_rgb(27,22,42));
    int unit=config->unit;
    REGION reg[4],frame;
    frame.x=30*unit;
    frame.y=0;
    frame.width=100*unit;
    frame.height=90*unit;
    for(i=0;i<=3;i++)
    {
        reg[i].x=30*unit;
        reg[i].width=130*unit;
        reg[i].height=10*unit;
        reg[i].y=7*unit+20*i*unit;
        drawCenteredBitmap(line,&reg[i]);
    }

    al_set_target_bitmap(bitmap);


    al_draw_text(font,al_map_rgb(255, 255, 255),reg[0].x,reg[0].y,ALLEGRO_ALIGN_CENTER,"MAIN MENU");
    al_draw_text(font,al_map_rgb(255, 255, 255),reg[1].x,reg[1].y,ALLEGRO_ALIGN_CENTER,"RESUME");
    al_draw_text(font,al_map_rgb(255, 255, 255),reg[2].x,reg[2].y,ALLEGRO_ALIGN_CENTER,"MUSIC");
    al_draw_text(font,al_map_rgb(255, 255, 255),reg[3].x,reg[3].y,ALLEGRO_ALIGN_CENTER,"SOUND");



    drawCenteredBitmap(sett,&frame);


    al_set_target_backbuffer(display);


    al_draw_tinted_bitmap(bitmap,tint,0,0,0);
     al_flip_display();
    system("pause");

}
