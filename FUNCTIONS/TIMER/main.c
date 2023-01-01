#include "Common.h"
#include "AL_general.h"
void Rank(CONFIG *config);


int main()
{

    CONFIG config;
    config.unit=8;
    al_setup();
    ALLEGRO_DISPLAY*display=al_create_display(160*config.unit,90*config.unit);
    Timer(&config);
    al_cleanup();
    return 0;
}



