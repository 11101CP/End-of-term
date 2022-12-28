#include "config_struct.h"
#include "GUI_general.h"

void loadButton(UIButton *button,float unit)
{
    button[FULLSCREEN].reg.x=unit*70;
    button[FULLSCREEN].reg.y=unit*55;
    button[FULLSCREEN].reg.width=unit*20;
    button[FULLSCREEN].reg.height=unit*3;
    button[FULLSCREEN].active=false;

    button[RESOLUTION].reg.x=unit*35;
    button[RESOLUTION].reg.y=unit*55;
    button[RESOLUTION].reg.width=unit*25;
    button[RESOLUTION].reg.height=unit*3;
    button[RESOLUTION].active=false;

    button[PLAY].reg.x=unit*68;
    button[PLAY].reg.y=unit*93;
    button[PLAY].reg.width=unit*20;
    button[PLAY].reg.height=unit*6;
    button[PLAY].active=false;

    button[QUIT].reg.x=unit*91;
    button[QUIT].reg.y=unit*93;
    button[QUIT].reg.width=unit*20;
    button[QUIT].reg.height=unit*6;
    button[QUIT].active=false;

}

void loadUIResource(UIResource *UIres)
{
UIres->font=al_load_font("./arial.ttf",UIres->unit*3,0);
UIres->thumbnail=al_load_bitmap("./thumbnail.jpg");
UIres->icon=al_load_bitmap("./icon.jpg");
}

void destroyUIResource(UIResource *UIres)
{
al_destroy_font(UIres->font);
al_destroy_bitmap(UIres->thumbnail);
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
