#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

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
int stage;
}CONFIG;


#endif // _COMMON_H_
