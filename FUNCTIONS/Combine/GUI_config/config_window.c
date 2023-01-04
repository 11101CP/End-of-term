#include "AL_general.h"
#include "config_struct.h"
#include "GUI_general.h"
#include "Common.h"


bool configUI(CONFIG *config,RESOURCE *res)
{




    UIButton button[4];
    DropDownMenu menu;

    ALLEGRO_EVENT events;


    int unit= getScreenInfo ();

    loadUIResource(res,unit);

    buildDropDownMenu(&menu,unit);
    loadButton(&button,unit);


    res->display = al_create_display(114*unit,102*unit);

    al_set_window_title(res->display, "Configuration");

    al_set_display_icon(res->display, res->bitmaps[1]);


    al_register_event_source(res->queues, al_get_display_event_source(res->display));
    al_register_event_source(res->queues , al_get_mouse_event_source());

while(1)
    {
    drawConfigMenu(res,&button,&menu,unit);
    al_flip_display();

    al_wait_for_event(res->queues, &events);
                switch(events.type)
                {
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                    al_play_sample(res->samples[0],1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
                    if(menu.drop)
                        getMenuClick(&events.mouse,&menu,&button[RESOLUTION]);
                    else
                        switch(getButtonClick(&events.mouse,&button))
                            {
                            case FULLSCREEN:
                                if (button[FULLSCREEN].active)
                                    button[FULLSCREEN].active=false;
                                else button[FULLSCREEN].active=true;
                                break;
                            case RESOLUTION:
                                menu.drop=true;
                                break;

                            case PLAY:
                                config->unit=(menu.choice+4) * 2;
                                config->fullscreen=button[FULLSCREEN].active;

                                destroyUIResource(res);
                                destroyDropDownMenu(&menu);
                                return true;

                            case QUIT:
                                destroyUIResource(res);
                                destroyDropDownMenu(&menu);
                                return false;
                        }//end of switch(getButtonClick(&events.mouse,&button))

                    break;
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        destroyUIResource(res);
                        destroyDropDownMenu(&menu);
                        return false;

                }// end of switch(events.type)
    }//end of while(1)
}//end of configUI



int getButtonClick(ALLEGRO_MOUSE_EVENT *mouse,UIButton *button)
{
if (mouseRegionDetect(mouse,button[FULLSCREEN].reg.x,button[FULLSCREEN].reg.y,button[FULLSCREEN].reg.width,button[FULLSCREEN].reg.height))
    return FULLSCREEN;
else if (mouseRegionDetect(mouse,button[RESOLUTION].reg.x,button[RESOLUTION].reg.y,button[RESOLUTION].reg.width,button[RESOLUTION].reg.height))
    return RESOLUTION;
else if (mouseRegionDetect(mouse,button[PLAY].reg.x,button[PLAY].reg.y,button[PLAY].reg.width,button[PLAY].reg.height))
    return PLAY;
else if (mouseRegionDetect(mouse,button[QUIT].reg.x,button[QUIT].reg.y,button[QUIT].reg.width,button[QUIT].reg.height))
    return QUIT;
else return -1;

}








