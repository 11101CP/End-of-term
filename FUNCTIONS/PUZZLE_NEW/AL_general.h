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
ALLEGRO_BITMAP  *trap;
ALLEGRO_BITMAP  *belt;
ALLEGRO_BITMAP  *chara;
ALLEGRO_BITMAP  *block;
ALLEGRO_BITMAP  *FlexSpikeOn;
ALLEGRO_BITMAP  *FlexSpikeOff;
ALLEGRO_FONT    *fonts;
ALLEGRO_SAMPLE *CharaMove;
ALLEGRO_SAMPLE *CharaHitten;
ALLEGRO_SAMPLE *ObjHitten;
ALLEGRO_SAMPLE *DoorOpen;
ALLEGRO_SAMPLE *MonsterHitten;
ALLEGRO_SAMPLE *MonsterDie;
ALLEGRO_SAMPLE *GamePause;
ALLEGRO_SAMPLE *GameRestart;


}RESOURCE;


#endif // AL_GENERAL_H_
