#include "AL_general.h"
void mousedetect(Resource *res, CONFIG *config)
{
    int unit;
    unit=config->unit;
    al_get_mouse_state(&(res->mouseState));

    switch(res->data.page)
      {
          case MENU:
         if(mouseRegionDetect(&(res->mouseState),(unit*160/2)-unit*15, (unit*90/5)*3, unit*30, unit*9))
            res->data.press=PLAY;
        else if(mouseRegionDetect(&(res->mouseState),(unit*160/2)-unit*15, (unit*90/5)*4, unit*30, unit*9))
            res->data.press=EXIT ;
        else res->data.press=NULL;
            break;

        case STAGEMENU:

        if(mouseRegionDetect(&(res->mouseState),1*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.press=STAGE1 ;
        else if(mouseRegionDetect(&(res->mouseState),2*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.press=STAGE2;
        else if(mouseRegionDetect(&(res->mouseState),3*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.press=STAGE3;
        else  if(mouseRegionDetect(&(res->mouseState),4*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.press=STAGE4;

        else res->data.press=NULL;
            break;

        case SETTING:

        if(mouseRegionDetect(&(res->mouseState), ((unit*160)/2)-unit*4*4, ((unit*90)/5)-unit*2, unit*4*4*2, unit*4))
            res->data.press=RESUME;
        else if(mouseRegionDetect(&(res->mouseState), ((unit*160)/2)-unit*4*4,((unit*90)/5)*2-(unit*2), unit*4*4*2, unit*4))
            res->data.press=RESTART;
        else if(mouseRegionDetect(&(res->mouseState),((unit*160)/2)-unit*4*3,((unit*90)/5)*3-(unit*2), unit*4*3, unit*4))
            res->data.press=SOUND;
        else if(mouseRegionDetect(&(res->mouseState),((unit*160)/2)-unit*4*2,((unit*90)/5)*4-(unit*2), unit*4*2, unit*4))
            res->data.press=MENU;

      }


    if(al_mouse_button_down(&(res->mouseState),1))
    {
        puts("click");
        al_play_sample(res->click,1.5,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
      switch(res->data.page)
      {
          case MENU:
         if(mouseRegionDetect(&(res->mouseState),(unit*160/2)-unit*30, (unit*90/5)*3, unit*60, unit*90/5))
            res->data.state=PLAY;
         else if(mouseRegionDetect(&(res->mouseState),(unit*160/2)-unit*30, (unit*90/5)*4, unit*60,unit*90/5))
            res->data.state=EXIT;

            break;

        case STAGEMENU:

        if(mouseRegionDetect(&(res->mouseState),1*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.state=STAGE1 ;
        else if(mouseRegionDetect(&(res->mouseState),2*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.state=STAGE2;
        else if(mouseRegionDetect(&(res->mouseState),3*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.state=STAGE3;
        else  if(mouseRegionDetect(&(res->mouseState),4*(unit*160)/5, unit*90-unit*16, unit*12, unit*16))
            res->data.state=STAGE4;

            break;

        case SETTING:
            if(mouseRegionDetect(&(res->mouseState), ((unit*160)/2)-unit*4*4, ((unit*90)/5)-unit*2, unit*4*4*2, unit*4))
            res->data.state=RESUME;
        else if(mouseRegionDetect(&(res->mouseState), ((unit*160)/2)-unit*4*4,((unit*90)/5)*2-(unit*2), unit*4*4*2, unit*4))
            res->data.state=RESTART;
        else if(mouseRegionDetect(&(res->mouseState),((unit*160)/2)-unit*4*3,((unit*90)/5)*3-(unit*2), unit*4*3, unit*4))
            res->data.state=SOUND;
        else if(mouseRegionDetect(&(res->mouseState),((unit*160)/2)-unit*4*2,((unit*90)/5)*4-(unit*2), unit*4*2, unit*4))
            res->data.state=MENU;
      }
    }

}

int mouseRegionDetect(ALLEGRO_MOUSE_STATE *msestate,int startX,int startY,int deltaX,int deltaY)
{
    int endX,endY;
    endX=startX+deltaX;
    endY=startY+deltaY;

    if (msestate->x >= startX && msestate->x<=endX&&msestate->y>= startY && msestate->y <= endY)
        return true;
    else
        return false;
}
