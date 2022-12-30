#include "Common.h"
#include "AL_general.h"
void Setting(CONFIG *config);


int main()
{
    CONFIG config;
    al_setup();
    Setting(&config);



    al_cleanup();
    return 0;
}



