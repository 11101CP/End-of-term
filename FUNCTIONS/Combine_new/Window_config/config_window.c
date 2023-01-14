#include "AL_general.h"
#include "config_struct.h"
#include "GUI.h"
#include "Common.h"


bool configUI(CONFIG *config,RESOURCE *res)
{


    UIButton button[4];
    DropDownMenu menu;

    ALLEGRO_EVENT events;
    res->queues=al_create_event_queue();



    int unit= getScreenInfo ();

    loadUIResource(res,unit);

    buildDropDownMenu(&menu,unit);
    loadButton(&button,unit);


    res->display = al_create_display(114*unit,102*unit);

    al_set_window_title(res->display, "Configuration");

    al_set_display_icon(res->display, res->bitmaps[1]);



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
                        getMenuClick(&events.mouse,&menu,&button[ConfigRESOLUTION]);
                    else
                        switch(getButtonClick(&events.mouse,&button))
                            {
                            case ConfigFULLSCREEN:
                                if (button[ConfigFULLSCREEN].active)
                                    button[ConfigFULLSCREEN].active=false;
                                else button[ConfigFULLSCREEN].active=true;
                                break;
                            case ConfigRESOLUTION:
                                menu.drop=true;
                                break;

                            case ConfigPLAY:
                                config->unit=(menu.choice+4) * 2;
                                config->fullscreen=button[ConfigFULLSCREEN].active;

                                destroyUIResource(res);
                                destroyDropDownMenu(&menu);
                                return true;

                            case ConfigQUIT:
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
if (mouseRegionDetect(mouse,button[ConfigFULLSCREEN].reg.x,button[ConfigFULLSCREEN].reg.y,button[ConfigFULLSCREEN].reg.width,button[ConfigFULLSCREEN].reg.height))
    return ConfigFULLSCREEN;
else if (mouseRegionDetect(mouse,button[ConfigRESOLUTION].reg.x,button[ConfigRESOLUTION].reg.y,button[ConfigRESOLUTION].reg.width,button[ConfigRESOLUTION].reg.height))
    return ConfigRESOLUTION;
else if (mouseRegionDetect(mouse,button[ConfigPLAY].reg.x,button[ConfigPLAY].reg.y,button[ConfigPLAY].reg.width,button[ConfigPLAY].reg.height))
    return ConfigPLAY;
else if (mouseRegionDetect(mouse,button[ConfigQUIT].reg.x,button[ConfigQUIT].reg.y,button[ConfigQUIT].reg.width,button[ConfigQUIT].reg.height))
    return ConfigQUIT;
else return -1;

}








