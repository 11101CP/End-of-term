#include "Common.h"
#include "AL_general.h"



int main()
{

    al_setup();
    CONFIG config;
    config.unit=12;
    config.stage=9;

  //  (config,);
    RESOURCE res;

    res.display=al_create_display(160*config.unit,90*config.unit);

    res.font=al_load_font("./assets/SoukouMincho.ttf",config.unit*15,0);

    res.bitmaps=calloc(BitmapsBoss,sizeof(ALLEGRO_BITMAP*));
    res.bitmaps[Background]=al_load_bitmap("./assets/freakinghigh.png");
    res.bitmaps[Belt]=al_load_bitmap("./assets/belt.png");
    res.bitmaps[Chara]=al_load_bitmap("./assets/duck.png");
    res.bitmaps[Death]=al_load_bitmap("./assets/death.png");
    res.bitmaps[Saw]=al_load_bitmap("./assets/saw.png");
    res.bitmaps[Layer]=al_load_bitmap("./assets/layer.png");
    res.bitmaps[Life]=al_load_bitmap("./assets/life.png");


    gameSetUp(&config,&res,10); //stage boss 1




    al_cleanup();
    return 0;
}



