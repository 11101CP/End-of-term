#ifndef GAME_FRAME_H_
#define GAME_FRAME_H_
#include "common.h"


typedef enum
{

STATIONARY,
MOVEABLE,
DAMAGE,
BLOCK

}STATE;

typedef struct
{
int x;
int y;
int width;
int height;
STATE state;
}BOX;

bool Game(CONFIG *config);
void buildBox (BOX ****box,int x,int y);
void loadBox  (BOX ***box,int x,int y,int unit);
void freeBox (BOX ***box,int x,int y);






#endif // GAME_FRAME_H_
