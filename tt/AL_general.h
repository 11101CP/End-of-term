#ifndef AL_GENERAL_H_
#define AL_GENERAL_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include"Common.h"

typedef struct miscData
{
    int state;
    int page;
    int press;
    int fontSize;

} miscData;
typedef struct Resource
{
    ALLEGRO_DISPLAY *display;
    ALLEGRO_BITMAP *subScreen;
    ALLEGRO_BITMAP *mouse;
    ALLEGRO_BITMAP *button;
    ALLEGRO_SAMPLE* click;
    ALLEGRO_FONT* font;
    ALLEGRO_MOUSE_CURSOR *cursor;
    miscData data;
    ALLEGRO_MOUSE_STATE mouseState;
} Resource;

int mouseRegionDetect(ALLEGRO_MOUSE_STATE *msestate,int startX,int startY,int deltaX,int deltaY);
void mousedetect(Resource *res, CONFIG *config);
void drawMenu( Resource *res, CONFIG *config);
void drawStageMenu( Resource *res, CONFIG *config);
void drawSettingPage(Resource *res, CONFIG *config);




#endif // AL_GENERAL_H_
