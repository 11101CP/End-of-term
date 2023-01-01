#ifndef GAME_FRAME_H_
#define GAME_FRAME_H_
#include "common.h"


typedef enum
{

STATIONARY,
MOVEABLE,
DAMAGE,
BLOCK,
CHARACTER

}STATE;

typedef enum
{
CH_STAY,
CH_MOVE,
CH_ATTAK,
CH_HRUT,
CH_WIN

}CHARA_STATE;

typedef struct
{

int x;
int y;
int life;
CHARA_STATE state;
int point;

}CHARA;


typedef struct
{
int x;
int y;
STATE state;
}BOX;

typedef struct
{
int stage;

BOX ***box;
int length; //box edge
int boxNumX;
int boxNumY;

}stage;

bool Game(CONFIG *config);
void buildBox (BOX ****box,int x,int y);
void loadBox  (BOX ***box,int x,int y,int unit);
void freeBox (BOX ***box,int x,int y);
void buildchara (CHARA* chara,int stage);
void drawChara(CHARA *chara,BOX ***box);






#endif // GAME_FRAME_H_
