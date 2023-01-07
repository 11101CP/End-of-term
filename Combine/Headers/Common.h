#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MENU 1
#define STAGEMENU 2
#define SETTING 3
#define STAGE1 4
#define STAGE2 5
#define STAGE3 6
#define STAGE4 7
#define PLAY 8
#define EXIT 9
#define RESUME 10
#define RESTART 11
#define SOUND 12

typedef struct
{
float x;
float y;
float width;
float height;
}REGION;

typedef struct
{
int unit;
float musicGain;
float soundGain;
bool fullscreen;
}CONFIG;


#endif // _COMMON_H_
