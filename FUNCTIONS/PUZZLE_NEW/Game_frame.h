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

FlexibleTrap

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
OBJ_STAY,
OBJ_MOVE,
OBJ_HURT

}OBJECT_STATE;

typedef enum
{

OBJ_BLOCK,
OBJ_KEY,
OBJ_DOOR,
OBJ_MONSTER,
OBJ_EXIT,
OBJ_TRAP,
OBJ_FLEXIBLETRAP

}OBJECT_CLASS;

typedef struct object
{
    int x;
    int y;
    int factinRight;
    int step;
    OBJECT_CLASS objClass;
    OBJECT_STATE objState;

    struct object* next;
}OBJECT;

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
bool moveChara (STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard,RESOURCE *res);
void TrapFunc(STAGE *stage,RESOURCE *res,CONFIG *config );








#endif // GAME_FRAME_H_
