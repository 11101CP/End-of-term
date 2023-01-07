#include "AL_general.h"
#include "GUI_general.h"


bool mouseRegionDetect(ALLEGRO_MOUSE_EVENT *mouse,int startX,int startY,int deltaX,int deltaY)
{
    int endX,endY;
    endX=startX+deltaX;
    endY=startY+deltaY;

    if (mouse->x >= startX && mouse->x<=endX&&mouse->y>= startY && mouse->y <= endY)
        return true;
    else
        return false;
}

void getMenuClick(ALLEGRO_MOUSE_EVENT *mouse,DropDownMenu *menu,UIButton *button)
{
    int offsetY=mouse->y-button->reg.y;
    int select=offsetY/button->reg.height;

    if(mouse->x>=button->reg.x&&mouse->x<=button->reg.x+button->reg.width&&select>0)
        if(select <= menu->number+1)
            menu->choice=select-1;
    menu->drop=false;

}
