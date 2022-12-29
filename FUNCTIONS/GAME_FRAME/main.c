#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"



int main()
{

    al_setup();

    CONFIG config;
    config.unit=12;

    Game(&config);





    al_cleanup();
    return 0;
}



