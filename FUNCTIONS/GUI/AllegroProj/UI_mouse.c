#include <allegro5/allegro.h>
 #include "UI_struct.h"

 bool mouseRegionDetect(ALLEGRO_MOUSE_EVENT *mouse,int startX,int startY,int deltaX,int deltaY);

int getButtonClick(ALLEGRO_MOUSE_EVENT *mouse,UIButton *button)
{
if (mouseRegionDetect(mouse,button[FULLSCREEN].x,button[FULLSCREEN].y,button[FULLSCREEN].width,button[FULLSCREEN].height))
    return FULLSCREEN;
else if (mouseRegionDetect(mouse,button[RESOLUTION].x,button[RESOLUTION].y,button[RESOLUTION].width,button[RESOLUTION].height))
    return RESOLUTION;
else if (mouseRegionDetect(mouse,button[PLAY].x,button[PLAY].y,button[PLAY].width,button[PLAY].height))
    return PLAY;
else if (mouseRegionDetect(mouse,button[QUIT].x,button[QUIT].y,button[QUIT].width,button[QUIT].height))
    return QUIT;
else return -1;

}


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
