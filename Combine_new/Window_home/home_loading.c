
#include"Game_home.h"

void LoadHomeResource(RESOURCE *res,CONFIG *config)
{

    res->bitmaps=calloc(HomeBmpNum,sizeof(ALLEGRO_BITMAP*));
    res->bitmaps[Cover]=al_load_bitmap("./assets/cover.png");
    res->bitmaps[PressedPlay]=al_load_bitmap("././assets/PressedPlay.png");
    res->bitmaps[PlayButton]=al_load_bitmap("././assets/PlayButton.png");
    res->bitmaps[ExitButton]=al_load_bitmap("././assets/ExitButton.png");
    res->bitmaps[PressedExit]=al_load_bitmap("././assets/PressedExit.png");

    res->fonts=calloc(2,sizeof(ALLEGRO_FONT*));
    res->fonts[0]=al_load_font("./assets/SoukouMincho.ttf",config->unit*15,0);
    res->fonts[1]=al_load_font("./assets/SoukouMincho.ttf",config->unit*6,0);

    res->samples=calloc(2,sizeof(ALLEGRO_SAMPLE*));
    res->samples[0]=al_load_sample("./assets/click.wav");
    res->samples[1]=al_load_sample("./assets/horror.wav");

}

void destroyHomeResource (RESOURCE *res)
{
    int i;
    for (i=0;i<HomeBmpNum;i++)
    {
        al_destroy_bitmap(res->bitmaps[i]);
    }
    free(res->bitmaps);
    al_stop_sample(res->samples[1]);
    al_destroy_sample(res->samples[0]);
    al_destroy_sample(res->samples[1]);
}

