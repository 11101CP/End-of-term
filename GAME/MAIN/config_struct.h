#ifndef CONFIG_STRUCT_H_
#define CONFIG_STRUCT_H_
#include "AL_general.h"
#include "common.h"
#include "GUI_general.h"


typedef enum
{
FULLSCREEN=0,
RESOLUTION=1,
PLAY=2,
QUIT=3,
}ButtonName;

typedef struct
{
ALLEGRO_DISPLAY *display;
ALLEGRO_BITMAP *thumbnail;
ALLEGRO_BITMAP *icon;
ALLEGRO_FONT *font;
ALLEGRO_SAMPLE *quack;

int unit;
}UIResource;


/***config_window.c***/
bool configUI(CONFIG *config);
int getButtonClick(ALLEGRO_MOUSE_EVENT *mouse,UIButton *button);


/***config_build.c***/
void loadButton(UIButton *button,float unit);
void loadUIResource(UIResource *UIres);
void destroyUIResource(UIResource *UIres);
void buildDropDownMenu(DropDownMenu *menu,int number);
int getScreenInfo (void);



/***config_draw.c***/
void drawframe(int unit);
void drawConfigMenu(UIResource *UIres,UIButton *button,DropDownMenu *menu);


#endif // CONFIG_STRUCT_H_
