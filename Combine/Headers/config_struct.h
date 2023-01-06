#ifndef CONFIG_STRUCT_H_
#define CONFIG_STRUCT_H_
#include "AL_general.h"
#include "common.h"
#include "GUI_general.h"


typedef enum
{
ConfigFULLSCREEN=0,
ConfigRESOLUTION=1,
ConfigPLAY=2,
ConfigQUIT=3,
}ButtonName;



/***config_window.c***/
bool configUI(CONFIG *config,RESOURCE *res);
int getButtonClick(ALLEGRO_MOUSE_EVENT *mouse,UIButton *button);


/***config_build.c***/
void loadButton(UIButton *button,float unit);
void loadUIResource(RESOURCE *res,int unit);
void destroyUIResource(RESOURCE *res);
void buildDropDownMenu(DropDownMenu *menu,int number);
int getScreenInfo (void);



/***config_draw.c***/
void drawframe(int unit);
void drawConfigMenu(RESOURCE *res,UIButton *button,DropDownMenu *menu,int unit);


#endif // CONFIG_STRUCT_H_
