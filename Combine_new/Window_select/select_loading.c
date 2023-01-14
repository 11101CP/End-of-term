#include"Game_select.h"

void LoadSelectResource(RESOURCE *res,CONFIG *config)
{
    res->bitmaps=calloc(SelectBmpNum,sizeof(ALLEGRO_BITMAP*));
    res->bitmaps[Cover]=al_load_bitmap("./assets/cover.png");
    res->bitmaps[Egg]=al_load_bitmap("./assets/egg.png");
    res->bitmaps[BreakEgg]=al_load_bitmap("./assets/breakedegg.png");
    res->bitmaps[Arrow]=al_load_bitmap("././assets/Arrow.png");
    res->bitmaps[Skeleton]=al_load_bitmap("././assets/Skeleton.png");
    res->bitmaps[CrackedEgg]=al_load_bitmap("././assets/CrackedEgg.png");
    res->fonts=calloc(2,sizeof(ALLEGRO_FONT*));
    res->fonts[0]=al_load_font("./assets/SoukouMincho.ttf",config->unit*15,0);
    res->fonts[1]=al_load_font("./assets/SoukouMincho.ttf",config->unit*6,0);
    res->samples=calloc(2,sizeof(ALLEGRO_SAMPLE*));
    res->samples[0]=al_load_sample("./assets/click.wav");
    res->samples[1]=al_load_sample("./assets/horror.wav");


}


void destroySelectResource (RESOURCE *res)
{
    int i;
    for (i=0;i<SelectBmpNum;i++)
    {
        al_destroy_bitmap(res->bitmaps[i]);
    }
    free(res->bitmaps);

    for (i=0;i<2;i++)
    {
        al_destroy_font(res->fonts[i]);
    }
    free (res->fonts);

//    for (i=0;i<)
//    {
//        al_destroy_audio_stream
//    }


}
