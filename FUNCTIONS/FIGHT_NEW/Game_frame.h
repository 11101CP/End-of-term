#ifndef GAME_FRAME_H_
#define GAME_FRAME_H_

#include "AL_general.h"
#include "common.h"
#include "Game_attack.h"


typedef enum
{

STATIONARY,
MOVEABLE,
BLOCK,
BOUNDARY,
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
int point;
bool facingRight;
bool vulnerable;
int step;
int offsetY;
int offsetX;
CHARA_STATE state;
ALLEGRO_TIMER *timer;

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
DAMAGE damage ;

}BOX;

typedef struct
{
int stage;
int progess;
BOX ***box;
int length; //box edge
int boxNumX;
int boxNumY;
AttackModule *attack;
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
void moveChara (CHARA *chara,STAGE *stage,ALLEGRO_KEYBOARD_EVENT *keyboard);
void detectCharaDamage(CHARA *chara,STAGE *stage,CONFIG *config);

/** Game_death.c**/
int death(RESOURCE* res,STAGE *stage ,CONFIG *config);

/** Game_attack.c**/
void drawAttack(STAGE *stage,RESOURCE *res,CONFIG *config);
void loadAttack(STAGE *stage);









#endif // GAME_FRAME_H_
