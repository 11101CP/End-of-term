#include "Common.h"
#include "AL_general.h"
void Rank(CONFIG *config);


int main()
{
    int unit=8;
    CONFIG config;

    al_setup();
    ALLEGRO_DISPLAY*display=al_create_display(160*unit,90*unit);
    Input(&config);
    al_cleanup();
    return 0;
}



