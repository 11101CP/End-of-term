#include"AL_general.h"
#include "config_struct.h"
#include "GUI_general.h"
#include "Common.h"



void drawframe(int unit)
{
    al_draw_filled_rectangle(3*unit,48*unit,111*unit,90*unit,al_map_rgb(255,255,255));

    al_draw_rectangle(3*unit,3*unit,111*unit,45*unit ,al_map_rgb(200, 200, 200) ,2);
    al_draw_rectangle(3*unit,48*unit,111*unit,90*unit,al_map_rgb(200, 200, 200) ,2);

}


void drawConfigMenu(UIResource *UIres,UIButton *button,DropDownMenu *menu)
{
    ALLEGRO_COLOR gray=al_map_rgb(250, 250, 250);;

    al_clear_to_color(gray);
    int unit=UIres->unit;

    REGION reg; //for thumbnail
    reg.height=42*unit;
    reg.width =108*unit;
    reg.x=3*unit;
    reg.y=3*unit;

    drawCenteredBitmap(UIres->thumbnail , &reg);
    drawframe(unit);
    drawList(UIres->font,&button[RESOLUTION],menu,unit);
    drawCheckBox (UIres->font,&button[FULLSCREEN],unit,"Full Screen");
    drawButton (UIres->font,&button[PLAY],unit,"Play!");
    drawButton (UIres->font,&button[QUIT],unit, "Quit");

}//end of drawConfigMenu

