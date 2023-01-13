#ifndef GAME_FRAME_H_
#define GAME_FRAME_H_

#include "AL_general.h"
#include "common.h"


typedef enum
{

EMPTY=0,
BLOCK,
BOUNDARY,
MONSTER,
DOOR,
EXIT

}STATE;

typedef enum
{

KEY=1,

TRAP,

FlexibleTrapOn,

FlexibleTrapOff

}ELEMENT;


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
bool facingRight;
int step;
bool vulnerable; // also used as an indicator of whether possesses the key.

}CHARA;

typedef enum
{
NO,
HURT,
DEATH

}DAMAGE;

typedef struct
{

int x;
int y;
STATE state;
ELEMENT element;
bool damage ;

}BOX;

typedef struct
{
int stage;

BOX ***box;
int length; //box edge
int boxNumX;
int boxNumY;
CHARA *chara;

}STAGE;





/** Game_playing.c **/
bool Game (CONFIG *config,STAGE *stage,RESOURCE *res);
bool Fight(CONFIG *config,STAGE *stage,RESOURCE *res);


/** Game_frame.c **/
void buildBox (BOX ****box,int x,int y);
void loadBox  (BOX ***box,int x,int y,int unit);
void freeBox (BOX ***box,int x,int y);
void buildchara (CHARA* chara,int stage);

/** Game_draw.c **/
void drawChara (CHARA *chara,STAGE *stage,RESOURCE *res,CONFIG *config);
void drawMap   (STAGE *stage,RESOURCE *res,CONFIG *config );
void drawObject(STAGE *stage,RESOURCE *res,CONFIG *config );
void boxShift(STAGE *stage,RESOURCE *res,CONFIG *config );
void moveChara (STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard);
void detectCharaDamage(CHARA *chara,STAGE *stage);









#endif // GAME_FRAME_H_
