#ifndef GAME_FRAME_H_
#define GAME_FRAME_H_

#include "AL_general.h"
#include "common.h"
#include "Game_attack.h"
#include "Game_playerEvent.h"





typedef enum
{
CH_STAY,
CH_MOVE,
CH_ATTACK,
CH_HRUT,
CH_WIN

}CHARA_STATE;

typedef struct
{

int x;
int y;
int life;
uint32_t point;
bool facingRight;
bool vulnerable;  // also used as an indicator of whether the character possesses the key
bool controllable;
int step;
int offsetY;
int offsetX;
CHARA_STATE state;
ALLEGRO_TIMER *timer;

}CHARA;

typedef struct
{
int x;
int y;
bool vulnerable;
int HP;

}AttackTarget;


typedef enum
{

NO,
HURT,
DEATH

}DAMAGE;


typedef enum
{

EMPTY=0,
BLOCK,
BOUNDARY,
MONSTER,
DOOR,
EXIT

}STATE; // barrier object

typedef enum
{

KEY = 1,
TRAP

}ELEMENT; // reactive object


typedef struct
{

int x;
int y;
STATE state;
ELEMENT element;
bool damage;

}BOX;

//typedef struct
//{
//CHARA *chara;
//AttackModule *attack;
//MONSTERS *target;
//
//
//}OBJECT;

typedef struct
{

int stage;
int progess;
BOX ***box;
int length; //box edge

int boxStartX;
int boxStartY;
int boxNumX;
int boxNumY;

AttackModule *attack;
AttackTarget *target;
CHARA *chara;
//OBJECT



}STAGE;




/** Game_load **/
void loadBossFightResource(RESOURCE *res,CONFIG *config);

/** Game_playing.c **/
bool Game (CONFIG *config,STAGE *stage,RESOURCE *res);
bool Fight(CONFIG *config,STAGE *stage,RESOURCE *res);


/** Game_frame.c **/
void buildBox (BOX ****box,int x,int y);
void freeBox  (BOX ***box,int x,int y);
void loadBox  (BOX ***box,int x,int y,int unit);
void clearStage(STAGE *stage);

void buildchara (CHARA* chara,int stage);

/** Game_draw.c **/
void drawChara (STAGE *stage,RESOURCE *res,CONFIG *config);
void drawMap   (STAGE *stage,RESOURCE *res,CONFIG *config );
void drawObject(STAGE *stage,RESOURCE *res,CONFIG *config );
void boxShift(STAGE *stage,RESOURCE *res,CONFIG *config );
void drawLifaIndicate (STAGE *stage,RESOURCE *res,CONFIG *config );

/** Game_chara.c **/
void controlChara (STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard);
void detectCharaDamage(STAGE *stage,RESOURCE *res);
void nextCharaFrame(CHARA *chara);


/** Game_death.c**/
int death(RESOURCE* res,STAGE *stage ,CONFIG *config);

/** Game_attack.c**/
void drawAttack(STAGE *stage,RESOURCE *res,CONFIG *config);
void loadAttack(STAGE *stage);









#endif // GAME_FRAME_H_
