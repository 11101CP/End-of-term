#include "AL_general.h"
#include "config_struct.h"

int main()
{
    RESOURCE res;
    CONFIG config;

    al_setup();

    if( ! configUI(&config,&res) )
        return 0;

    if(config.fullscreen)
        {
            al_set_new_display_flags(ALLEGRO_WINDOWED);
            al_set_new_display_flags(ALLEGRO_RESIZABLE);
            res.display=al_create_display(160*config.unit,90*config.unit);
            al_set_display_flag(res.display, ALLEGRO_FRAMELESS, true);
            al_set_display_flag(res.display, ALLEGRO_MAXIMIZED, true);
        }
    else res.display=al_create_display(160*config.unit,90*config.unit);

    ALLEGRO_BITMAP *bmp =al_load_bitmap("./assets/thumbnail.jpg");
while(1)
   {

    al_draw_scaled_bitmap(bmp,0,0,600,600,0,0,160*config.unit,90*config.unit,0);
    al_flip_display();
   }

    system("pause");

    //res.font=al_load_font("./assets/SoukouMincho.ttf",config.unit*15,0);



//    gameSetUp(&config,&res,10); //stage boss 1


    al_cleanup();


return 0;
}



