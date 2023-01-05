#ifndef GAME_PLAYER_EVENT_H_
#define GAME_PLAYER_EVENT_H_

#include <allegro5/allegro.h>

typedef struct MyCharaEvent
{
   int value;
} MyCharaEvent;

enum
{
CharaDeath = ALLEGRO_GET_EVENT_TYPE('D', 'E', 'A', 'D'),
DIE
};


#endif // GAME_PLAYER_EVENT_H_
