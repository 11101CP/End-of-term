#include "Common.h"
#include "AL_general.h"

int main()
{

    al_setup();
    Resource res;
    CONFIG config;
    config.unit=8;
    ALLEGRO_DISPLAY*display=al_create_display(160*config.unit,90*config.unit);
    while(res.data.state!=EXIT)
    {
       if( KeyboardDetect(&res,&config))
          drawStageMenu(&res,&config);
        else res.data.state=EXIT;
    }
    al_cleanup();
    return 0;
}



