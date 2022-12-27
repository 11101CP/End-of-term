#include "UI_struct.h"
void loadButton(UIButton *button,float unit)
{
    button[FULLSCREEN].x=unit*25;
    button[FULLSCREEN].y=unit*18;
    button[FULLSCREEN].width=unit*7;
    button[FULLSCREEN].height=unit*1;
    button[FULLSCREEN].active=false;


    button[RESOLUTION].x=unit*13;
    button[RESOLUTION].y=unit*18;
    button[RESOLUTION].width=unit*10;
    button[RESOLUTION].height=unit*1.2;
    button[RESOLUTION].active=false;

    button[PLAY].x=unit*22;
    button[PLAY].y=unit*31;
    button[PLAY].width=unit*7;
    button[PLAY].height=unit*2;
    button[PLAY].active=false;

    button[QUIT].x=unit*30;
    button[QUIT].y=unit*31;
    button[QUIT].width=unit*7;
    button[QUIT].height=unit*2;
    button[QUIT].active=false;



}

void loadUIResource(UIResource *UIres)
{
UIres->unit=25;

UIres->white=al_map_rgb(255, 255, 255);
UIres->black=al_map_rgb(0, 0, 0);
UIres->gray=al_map_rgb(250, 250, 250);
UIres->grayer=al_map_rgb(220, 220, 220);
UIres->line=al_map_rgb(200, 200, 200);
UIres->font=al_load_font("./arial.ttf",UIres->unit,0);
UIres->thumbnail=al_load_bitmap("./thumbnail.jpg");
}

void buildDropDownMenu(DropDownMenu *menu,int number)
{
menu->drop=true;
menu->number=number;
menu->choise=number;

printf("\n%d\n",number);
puts("----------------");
menu->item[0]="960x540";
menu->item[1]="1280x720";
menu->item[2]="1600x900";
menu->item[3]="1920x1080";
menu->item[4]="2240x1260";
menu->item[5]="2560x1440";
menu->item[6]="2880x1620";
menu->item[7]="3200x1800";
menu->item[8]="3840x2160";

}
