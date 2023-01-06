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


void drawConfigMenu(RESOURCE *res,UIButton *button,DropDownMenu *menu,int unit)
{
    ALLEGRO_COLOR gray=al_map_rgb(250, 250, 250);;

    al_clear_to_color(gray);


    REGION reg; //for thumbnail
    reg.height=42*unit;
    reg.width =108*unit;
    reg.x=3*unit;
    reg.y=3*unit;

    drawCenteredBitmap(res->bitmaps[0], &reg);
    drawframe(unit);
    drawList(res->fonts[0],&button[ConfigRESOLUTION],menu,unit);
    drawCheckBox (res->fonts[0],&button[ConfigFULLSCREEN],unit,"Full Screen");
    drawButton (res->fonts[0],&button[ConfigPLAY],unit,"Play!");
    drawButton (res->fonts[0],&button[ConfigQUIT],unit, "Quit");

}//end of drawConfigMenu

