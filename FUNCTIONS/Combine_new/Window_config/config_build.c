#include "config_struct.h"
#include "GUI.h"
#include "AL_general.h"




void loadButton(UIButton *button,float unit)
{
    button[ConfigFULLSCREEN].reg.x=unit*70;
    button[ConfigFULLSCREEN].reg.y=unit*55;
    button[ConfigFULLSCREEN].reg.width=unit*20;
    button[ConfigFULLSCREEN].reg.height=unit*3;
    button[ConfigFULLSCREEN].active=false;

    button[ConfigRESOLUTION].reg.x=unit*35;
    button[ConfigRESOLUTION].reg.y=unit*55;
    button[ConfigRESOLUTION].reg.width=unit*25;
    button[ConfigRESOLUTION].reg.height=unit*3;
    button[ConfigRESOLUTION].active=false;

    button[ConfigPLAY].reg.x=unit*68;
    button[ConfigPLAY].reg.y=unit*93;
    button[ConfigPLAY].reg.width=unit*20;
    button[ConfigPLAY].reg.height=unit*6;
    button[ConfigPLAY].active=false;

    button[ConfigQUIT].reg.x=unit*91;
    button[ConfigQUIT].reg.y=unit*93;
    button[ConfigQUIT].reg.width=unit*20;
    button[ConfigQUIT].reg.height=unit*6;
    button[ConfigQUIT].active=false;

}

void loadUIResource(RESOURCE *res,int unit)
{
res->fonts  =calloc(1,sizeof(ALLEGRO_FONT*));
res->bitmaps=calloc(2,sizeof(ALLEGRO_BITMAP*));
res->samples=calloc(1,sizeof(ALLEGRO_SAMPLE*));


res->fonts  [0]=al_load_font("./assets/arial.ttf",unit*3,0);
res->bitmaps[0]=al_load_bitmap("./assets/thumbnail.jpg");
res->bitmaps[1]=al_load_bitmap("./assets/icon.png");
res->samples[0]=al_load_sample("./assets/Quack.wav");




  //  al_register_event_source(res->queues, al_get_display_event_source(res->display));
}

void destroyUIResource(RESOURCE *res)
{
al_destroy_font(res->fonts[0]);
al_destroy_bitmap(res->bitmaps[0]);
al_destroy_bitmap(res->bitmaps[1]);
al_destroy_sample(res->samples[0]);
al_destroy_display(res->display);
al_destroy_event_queue(res->queues);

free(res->bitmaps);
free(res->fonts);
free(res->samples);


}

void buildDropDownMenu(DropDownMenu *menu,int number)
{
    menu->drop=false;
    menu->number=number-4;
    menu->choice=number-4;

    menu->item = calloc((menu->number+1),sizeof(char*));

    switch(menu->number)
    {
    case 8:
        menu->item[8]="3840x2160";
    case 7:
        menu->item[7]="3520x1980";
    case 6:
        menu->item[6]="3200x1800";
    case 5:
        menu->item[5]="2880x1620";
    case 4:
        menu->item[4]="2560x1440";
    case 3:
        menu->item[3]="2240x1260";
    case 2:
        menu->item[2]="1920x1080";
    case 1:
        menu->item[1]="1600x900";
    case 0:
        menu->item[0]="1280x720";
    break;
    default:
    }
}

void destroyDropDownMenu(DropDownMenu *menu)
{
        free(menu->item);
}



int getScreenInfo (void)
{
    ALLEGRO_MONITOR_INFO info;

    al_get_monitor_info(0,&info);

    printf("your monitor :%dx%d\n",info.x2,info.y2);

    int x = info.x2/16;
    int y = info.y2/9;
    int min;

    if (x<y)
        min=x;
    else
        min=y;

    if (min>=240)
        return 12;
    if (min>=220)
        return 11;
    if (min>=200)
        return 10;
    if (min>=180)
        return 9;
    if (min>=160)
        return 8;
    if (min>=140)
        return 7;
    if (min>=120)
        return 6;
    if (min>=100)
        return 5;
    if (min>=80)
        return 4;
    else
        return 0;

}

