#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
 #include <allegro5/allegro_primitives.h>
 #include <allegro5/allegro_font.h>
 #include "UI_struct.h"

void drawConfigMenu(UIResource *UIres,UIButton *button,DropDownMenu *menu)
{
    ALLEGRO_COLOR *gray=&(UIres->gray);
    ALLEGRO_COLOR *line=&(UIres->line);
    ALLEGRO_COLOR *white=&(UIres->white);


    al_clear_to_color(*gray);
    float unit=UIres->unit;
    drawThumbnail(UIres);


    al_draw_rectangle(unit,16*unit,37*unit,30*unit,*line,2);
    al_draw_rectangle(unit,unit,37*unit,15*unit,*line,1);


    al_set_target_bitmap(UIres->sub);

    al_clear_to_color(*white);
    drawList(UIres,&button[RESOLUTION],menu);
    drawCheckBox (UIres,&button[FULLSCREEN],"Full Screen");


    al_set_target_backbuffer(UIres->display);
    al_draw_bitmap(UIres->sub,unit,16*unit,0);

    drawButton (UIres,&button[PLAY],"Play!");
    drawButton (UIres,&button[QUIT], "Quit");
}//end of drawConfigMenu

void  drawThumbnail(UIResource *UIres)
{   float unit=UIres->unit;
    float thumbnailW=al_get_bitmap_width(UIres->thumbnail);
    float thumbnailH=al_get_bitmap_height(UIres->thumbnail);
    float W = thumbnailW/unit;
    float H = (14*unit)/thumbnailH;


    al_draw_scaled_bitmap(UIres->thumbnail,0,0,thumbnailW,thumbnailH,19*unit-thumbnailW*H/2,unit , thumbnailW*H , thumbnailH*H ,0);


} //end of drawThumbnail


void drawButton (UIResource *UIres,UIButton *button, char *s)
{
ALLEGRO_FONT *font=UIres->font;
ALLEGRO_COLOR *black=&(UIres->black);
ALLEGRO_COLOR *grayer=&(UIres->grayer);
ALLEGRO_COLOR *line=&(UIres->line);

float x=button->x;
float y=button->y;
float unit=UIres->unit;


al_draw_filled_rectangle(x,y,x+7*unit,y+2*unit,*grayer);
al_draw_rectangle(x,y,x+7*unit,y+2*unit,*line,2);

al_draw_text(font,*black,x+2*unit,y+0.5*unit,0,s);

} // end of drawButton


 void drawList(UIResource *UIres,UIButton *button,DropDownMenu *menu)
{
ALLEGRO_COLOR black=UIres->black;
ALLEGRO_COLOR gray=UIres->gray;
ALLEGRO_COLOR grayer=UIres->grayer;
ALLEGRO_COLOR line=UIres->line;
ALLEGRO_FONT* font=UIres->font;
float unit=UIres->unit;
float x=button->x-unit;
float y=button->y-16*unit;

al_draw_text(font,black,x-unit*10,y,0,"Screen resolution");

al_draw_filled_rectangle(x,y-unit*0.1,x+unit*10,y+unit*1.1,grayer);
al_draw_rectangle(x,y-unit*0.1,x+unit*10,y+unit*1.1,line,1);
al_draw_text(font,black,x,y,0,menu->item[menu->choise]);
al_draw_text(font,black,x+unit*9,y,0,"...");

if (button->active)
for (int i=0;i<=menu->number;i++)
{
al_draw_filled_rectangle(x,unit*(3.1+i*1.2),x+unit*10,y+unit*2.3+unit*(i*1.2),gray);
al_draw_rectangle(x,unit*(3.1+i*1.2),x+unit*10,y+unit*2.3+unit*(i*1.2),line,1);
al_draw_text(font,black,x,y+unit*1.2+unit*(i*1.2),0,menu->item[i]);

}

} // end of drawList

 void drawCheckBox (UIResource *UIres,UIButton *button, char *s)
 {

ALLEGRO_COLOR *line=&(UIres->line);
ALLEGRO_COLOR *black=&(UIres->black);
ALLEGRO_FONT *font=UIres->font;
float unit=UIres->unit;
float x=button->x-unit;
float y=button->y-16*unit;

al_draw_text(font,*black,x+unit*1.5,y,0,"Full Screen");

al_draw_rectangle(x,y,x+unit,y+unit,*line,2);
if(button->active)
    {
    al_draw_line(x+0.1*unit,y+0.5*unit,x+unit*0.4,y+unit*0.8,*black,3);
    al_draw_line(x+unit*0.3,y+unit*0.8,x+unit*0.9,y+unit*0.2,*black,3);
    }
 } // end of drawCheckBox
