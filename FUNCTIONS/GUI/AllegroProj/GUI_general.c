#include"AL_general.h"
#include"GUI_general.h"
#include"Common.h"


void  drawCenterdBitmap(ALLEGRO_BITMAP *bmp , REGION *reg) //several possible cases
{
    float bmpW=al_get_bitmap_width(bmp);
    float bmpH=al_get_bitmap_height(bmp);
    float zoomW ;
    float zoomH ;

    if (bmpW > reg->width)
        if(bmpH>reg->height)
            {
            zoomW = bmpW/reg->width;
            zoomH = bmpH/reg->height;
            if(zoomH>zoomW)
                al_draw_scaled_bitmap(bmp,0,0,bmpW,bmpH,(reg->x+reg->width)/2-bmpW/zoomH/2, reg->y,bmpW/zoomH,reg->height,0);

            else
                al_draw_scaled_bitmap(bmp,0,0,bmpW,bmpH,reg->x, (reg->y+reg->height)/2-bmpH/zoomW/2,reg->width,bmpH/zoomW,0);

            }
        else
            {
            zoomH = bmpH/reg->height;
            al_draw_scaled_bitmap(bmp,0,0,bmpW,bmpH,reg->x, (reg->y+reg->height)/2-bmpH*zoomH/2,reg->width,bmpH*zoomH,0);
            }
    else if(bmpH>reg->height)
        {
        zoomW = bmpW/reg->width;
        al_draw_scaled_bitmap(bmp,0,0,bmpW,bmpH,(reg->x+reg->width)/2-bmpW*zoomW/2 , reg->y,bmpW*zoomW,reg->height,0);
        }

    else
    {
        zoomW = reg->width/bmpW;
        zoomH = reg->height/bmpH;

        if(zoomW>zoomH)
            al_draw_scaled_bitmap(bmp,0,0,bmpW,bmpH,(reg->x+reg->width)/2-bmpW*zoomH/2, reg->y,bmpW*zoomH,reg->height,0);
        else
            al_draw_scaled_bitmap(bmp,0,0,bmpW,bmpH,reg->x, (reg->y+reg->height)/2-bmpH*zoomW/2,reg->width,bmpH*zoomW,0);


    }

} //end of drawCenterdBitmap




void drawButton (ALLEGRO_FONT *font,UIButton *button,int unit, char *s)
{

ALLEGRO_COLOR black=al_map_rgb(0, 0, 0);
ALLEGRO_COLOR grayer=al_map_rgb(220, 220, 220);
ALLEGRO_COLOR line=al_map_rgb(200, 200, 200);

int x=button->reg.x;
int y=button->reg.y;
int w=button->reg.width;
int h=button->reg.height;


al_draw_filled_rectangle(x,y,x+w,y+h,grayer);
al_draw_rectangle(x,y,x+w,y+h,line,2);

al_draw_text(font,black,x+w/2,y+unit,ALLEGRO_ALIGN_CENTRE,s);

} // end of drawButton


 void drawList(ALLEGRO_FONT *font,UIButton *button,DropDownMenu *menu,int unit)
{
ALLEGRO_COLOR black=al_map_rgb(0, 0, 0);
ALLEGRO_COLOR gray=al_map_rgb(250, 250, 250);
ALLEGRO_COLOR grayer=al_map_rgb(220, 220, 220);
ALLEGRO_COLOR line=al_map_rgb(200, 200, 200);


int x=button->reg.x;
int y=button->reg.y;
int w=button->reg.width;
int h=button->reg.height;



al_draw_text(font,black,x-2*unit,y,ALLEGRO_ALIGN_RIGHT,"Screen resolution");

al_draw_filled_rectangle(x,y,x+w,y+h,grayer);
al_draw_rectangle(x,y,x+w,y+h,line,1);
al_draw_text(font,black,x+w/3,y,ALLEGRO_ALIGN_CENTRE,menu->item[menu->choice]);
al_draw_text(font,black,x+w,y,ALLEGRO_ALIGN_RIGHT,"...");

if (menu->drop)
for (int i=0;i<=menu->number;i++)
{
al_draw_filled_rectangle(x,y+h*(i+1),x+w,y+h*(i+2),gray);
if(i==menu->choice)
    al_draw_filled_rectangle(x,y+h*(i+1),x+w,y+h*(i+2),grayer);
al_draw_rectangle(x,y+h*(i+1),x+w,y+h*(i+2),line,1);
al_draw_text(font,black,x+w/3,y+h*(i+1),ALLEGRO_ALIGN_CENTRE,menu->item[i]);

}

} // end of drawList

 void drawCheckBox (ALLEGRO_FONT *font,UIButton *button,int unit, char *s)
 {

ALLEGRO_COLOR line=al_map_rgb(200, 200, 200);
ALLEGRO_COLOR black=al_map_rgb(0, 0, 0);

int x=button->reg.x;
int y=button->reg.y;
int w=button->reg.width;
int h=button->reg.height;


al_draw_text(font,black,x+h+unit,y,0,s);

al_draw_rectangle(x,y,x+h,y+h,line,2);

if(button->active) // draw check
    {
    al_draw_line(x,y+2*unit,x+unit,y+3*unit,black,3);
    al_draw_line(x+unit,y+3*unit,x+3*unit,y,black,3);
    }

 } // end of drawCheckBox

