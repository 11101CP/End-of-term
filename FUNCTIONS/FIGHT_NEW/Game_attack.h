#ifndef GAME_ATTACK_H_
#define GAME_ATTACK_H_

typedef enum
{
HORIZON,
VERTIC,
POINT,
AREA



}ATTACKTYPE;


typedef struct AttackModule1
{

int x;
int y;
int dx;
int dy;
ATTACKTYPE;
int step;  // self destruct
struct *AttackModule1;

}AttackModule;




#endif // GAME_ATTACK_H_
