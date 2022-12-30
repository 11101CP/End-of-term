#ifndef GAME_FRAME_H_
#define GAME_FRAME_H_
#include "common.h"


typedef enum
{

STATIONARY,
MOVEABLE,
DAMAGE,
EMPTY,
BLOCK,
CHARC,
BRICK,
MONSTER,
SPIKE,
EXIT,

}STATE;

typedef struct
{
int x;
int y;
int width;
int height;
STATE state;
}BOX;

typedef struct
{
float x;
float y;
float width;
float height;
STATE state;
}Charc_State;

bool Game(CONFIG *config);
void buildBox (BOX ****box,int x,int y);
void loadBox  (BOX ***box,int x,int y,int unit);
void freeBox (BOX ***box,int x,int y);






#endif // GAME_FRAME_H_
