#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
 #include <allegro5/allegro_primitives.h>
 #include <allegro5/allegro_font.h>
 #include "UI_struct.h"

void drawList(UIResource *UIres,UIButton *button,DropDownMenu *menu);
int configUI(Config *config);
void buildDropDownMenu(DropDownMenu *menu,int number);
void drawCheckBox (UIResource *UIres,UIButton *button, char *s);
void drawButton  (UIResource *UIres,UIButton *button, char *s);
void loadButton(UIButton *button,float unit);
void drawConfigMenu(UIResource *UIres,UIButton *button,DropDownMenu *menu);



int configUI(Config *config)
{
    int finish=0;
    float unit=25.0;

    DropDownMenu menu;
    UIButton button[4];
    UIResource UIres;

    loadButton(&button,unit);
    loadUIResource(&UIres);


    UIres.display = al_create_display(38*unit,34*unit);

    ALLEGRO_BITMAP *icon=al_load_bitmap("./icon.jpg");

    UIres.sub=al_create_bitmap(unit*36,unit*14);

    buildDropDownMenu(&menu,getScreenInfo ());

    ALLEGRO_EVENT_QUEUE* event_queue = NULL; /* create event queue */
    ALLEGRO_EVENT events;
    event_queue = al_create_event_queue();

//    al_register_event_source(event_queue, al_get_display_event_source(display));
//    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_register_event_source(event_queue , al_get_keyboard_event_source());
     al_register_event_source(event_queue , al_get_mouse_event_source());

    //al_wait_for_event(event_queue, &events);


al_set_window_title(UIres.display, "Configuration");

al_set_display_icon(UIres.display, icon);

//al_set_display_flag(display, ALLEGRO_MINIMIZED, true);
//al_set_display_flag(display, ALLEGRO_MAXIMIZED, false);
//al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, false);
//al_set_display_flag(display, ALLEGRO_NOFRAME, true);

while(!finish)
    {
    drawConfigMenu(&UIres,&button,&menu);
    al_flip_display();

al_wait_for_event(event_queue, &events);

                if (events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                {
                    switch(getButtonClick(&events.mouse,&button))
                    {
                    case FULLSCREEN:
                        if (button[FULLSCREEN].active)
                            button[FULLSCREEN].active=false;
                        else button[FULLSCREEN].active=true;
                        break;
                    case RESOLUTION:
                        if (button[RESOLUTION].active)
                            button[RESOLUTION].active=false;
                        else button[RESOLUTION].active=true;

                        break;
                    case PLAY:

                        break;

                    case QUIT:
                        al_destroy_display(UIres.display);
                        return 0;
                        break;
                    }

                }

    }//end of while(!finish)

}//end of configUI








