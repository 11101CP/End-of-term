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

void install_al(void);
void destroy_al(void);

typedef struct
{

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queues;

ALLEGRO_BITMAP **bitmaps;
ALLEGRO_FONT   **fonts;
ALLEGRO_SAMPLE **samples;
ALLEGRO_TIMER  **timers;
ALLEGRO_EVENT_SOURCE *user_src;

}RESOURCE;

typedef struct
{
int progress;

}GAMEDATA;






void drawMenu( RESOURCE *res, CONFIG *config,unsigned short control);
void drawStageMenu( RESOURCE *res, CONFIG *config,unsigned short control);
void drawSettingPage(RESOURCE *res, CONFIG *config,unsigned short control);
bool Windows(RESOURCE *res,CONFIG *config);
void Input(RESOURCE *res,CONFIG *config);
void Rank(CONFIG *config);
int SettingDetect(RESOURCE *res, CONFIG *config);




#endif //AL_GENERAL_H_


