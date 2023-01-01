#include "Common.h"
#include "AL_general.h"
#include "GAME_frame.h"

void drawChara(CHARA *chara,BOX ***box)
{
    int x=chara->x;
    int y=chara->y;


    al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+108,box[x][y]->y+108,al_map_rgb(250,250,250));

}
