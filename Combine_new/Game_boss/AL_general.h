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


void install_al(void);
void destroy_al(void);

typedef struct
{
ALLEGRO_DISPLAY *display;

ALLEGRO_FONT *font;


ALLEGRO_BITMAP **bitmaps;
ALLEGRO_FONT **fonts;
ALLEGRO_SAMPLE **samples;
ALLEGRO_TIMER **timers;

}RESOURCE;

typedef enum
{
Background,
Belt,
Chara,
Death,
Saw,
Layer,
Life,
BitmapsBoss
} BITMAPS;



#endif // AL_GENERAL_H_
