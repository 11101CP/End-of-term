#ifndef GAME_SELECT_H_
#define GAME_SELECT_H_

#include "AL_general.h"
#include "Common.h"
#include "SelectEnums.h"

int SettingDetect(RESOURCE *res, CONFIG *config);
void drawStageMenu( RESOURCE *res, CONFIG *config,unsigned short control);


void LoadSelectResource(RESOURCE *res,CONFIG *config);
void destroySelectResource (RESOURCE *res);

#endif // GAME_SELECT_H_
