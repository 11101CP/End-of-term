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
        al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
        res.display=al_create_display(160*config.unit,90*config.unit);

    //res.font=al_load_font("./assets/SoukouMincho.ttf",config.unit*15,0);

    Windows(&res,&config);


//    gameSetUp(&config,&res,10); //stage boss 1


    al_cleanup();


return 0;
}



