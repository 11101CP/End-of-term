#ifndef ALHEADER_H_
#define ALHEADER_H_

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_font.h"
#include <allegro5/allegro_acodec.h>

// Definition of display size
#define DISPLAY_WIDTH   1280
#define DISPLAY_HEIGHT  720

//Page define
#define MENU 1
#define STAGEMENU 2
#define SETTING 3
#define STAGE1 4
#define STAGE2 5
#define STAGE3 6
#define STAGE4 7
#define PLAY 8
#define EXIT 9
#define RESUME 10
#define RESTART 11
#define SOUND 12

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

          /* pointer to Font file */
} Resource;

typedef struct
{
int unit;
float musicGain;
float soundGain;
bool fullscreen;
}CONFIG;

int mouseRegionDetect(ALLEGRO_MOUSE_STATE *msestate,int startX,int startY,int deltaX,int deltaY);
void mousedetect(Resource *res, CONFIG *config);
//AlDraw
void drawMenu( Resource *res, CONFIG *config);
void drawStageMenu( Resource *res, CONFIG *config);
void drawSettingPage(Resource *res, CONFIG *config);











#endif // ALHEADER_H_
