#ifndef GAME_ATTACK_H_
#define GAME_ATTACK_H_

typedef enum
{

HORIZON,
VERTIC,
POINT,
LINE,
AREA

}ATTACKTYPE;


typedef struct AttackModule
{

int x;
int y;
int dx;
int dy;
ATTACKTYPE type;
int step;  // self destruct
struct AttackModule *next;

}AttackModule;




#endif // GAME_ATTACK_H_
