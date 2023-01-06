#ifndef GUI_GENERAL_H_
#define GUI_GENERAL_H_

#ifndef AL_GENERAL_H_
    #include "AL_general.h"
#endif // AL_GENERAL_H_

#ifndef COMMON_H_
    #include "common.h"
#endif // COMMON_H_

typedef struct
{
REGION reg;
bool active;
} UIButton;

typedef struct
{
bool drop;
int number;
int choice;
char **item;
}DropDownMenu;

/***GUI_general.h***/
void  drawCenteredBitmap(ALLEGRO_BITMAP *bmp , REGION *reg);
void drawList     (ALLEGRO_FONT *font,UIButton *button,DropDownMenu *menu,int unit);
void drawCheckBox (ALLEGRO_FONT *font,UIButton *button,int unit, char *s);
void drawButton   (ALLEGRO_FONT *font,UIButton *button,int unit, char *s);

/***GUI_mouse.h***/
void getMenuClick(ALLEGRO_MOUSE_EVENT *mouse,DropDownMenu *menu,UIButton *button);
bool mouseRegionDetect(ALLEGRO_MOUSE_EVENT *mouse,int startX,int startY,int deltaX,int deltaY);





#endif // GUI_GENERAL_H_
