#include "AL_general.h"
#include "config_struct.h"
#include "GUI_general.h"
#include "Common.h"


bool configUI(CONFIG *config)
{

    UIButton button[4];
    UIResource UIres;
    DropDownMenu menu;

    ALLEGRO_EVENT events;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;

    UIres.unit= getScreenInfo ();
    loadUIResource(&UIres);

    buildDropDownMenu(&menu,UIres.unit);
    loadButton(&button,UIres.unit);

    UIres.display = al_create_display(114*UIres.unit,102*UIres.unit);
    al_set_window_title(UIres.display, "Configuration");
    al_set_display_icon(UIres.display, UIres.icon);


    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(UIres.display));
    al_register_event_source(event_queue , al_get_mouse_event_source());

while(1)
    {
    drawConfigMenu(&UIres,&button,&menu);
    al_flip_display();

    al_wait_for_event(event_queue, &events);
                switch(events.type)
                {
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

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
                                al_destroy_display(UIres.display);
                                destroyUIResource(&UIres);
                                destroyDropDownMenu(&menu);
                                return true;

                            case QUIT:
                                al_destroy_display(UIres.display);
                                destroyUIResource(&UIres);
                                destroyDropDownMenu(&menu);
                                return false;
                        }//end of switch(getButtonClick(&events.mouse,&button))

                    break;
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        al_destroy_display(UIres.display);
                        destroyUIResource(&UIres);
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








