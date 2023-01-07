#include "AL_general.h"
//#include "Game_frame.h"
#include "Loading_enum.h"
#include "Common.h"

void loadBossFightResource(RESOURCE *res,CONFIG *config)
{

    res->bitmaps=calloc(BossBitmapsNumber,sizeof(ALLEGRO_BITMAP*));
    res->bitmaps[Background]=al_load_bitmap("./assets/freakinghigh.png");
    res->bitmaps[Belt]=al_load_bitmap("./assets/belt.png");
    res->bitmaps[Chara]=al_load_bitmap("./assets/duck.png");
    res->bitmaps[Death]=al_load_bitmap("./assets/death.png");
    res->bitmaps[Saw]=al_load_bitmap("./assets/saw.png");
    res->bitmaps[Layer]=al_load_bitmap("./assets/layer.png");
    res->bitmaps[Life]=al_load_bitmap("./assets/life.png");

    res->fonts=calloc(1,sizeof(ALLEGRO_FONT*));
    res->fonts[0]=al_load_font("./assets/SoukouMincho.ttf",config->unit*15,0);



//    res->samples=calloc();

    res->timers=calloc(BossTimerNumber,sizeof(ALLEGRO_TIMER*));
    res->timers[FPS]=al_create_timer(1.0 /60);
    res->timers[AttackTime] = al_create_timer(1.0 );//refresh
    res->timers[Refresh]=al_create_timer(1.0/9);

    res->user_src=calloc(1,sizeof(ALLEGRO_EVENT_SOURCE));


}

void destroyBossFightResource(RESOURCE *res)
{

    int i;
    for(i=0;res->bitmaps[i]!=NULL;i++)
    {
        al_destroy_bitmap(res->bitmaps[i]);
    }

    free (res->bitmaps);

     for(i=0;res->fonts[i]!=NULL;i++)
    {
        al_destroy_font(res->fonts[i]);
    }
    free (res->fonts);

    for (i=0;res->samples[i]!=NULL;i++)
    {
        al_destroy_sample(res->samples[i]);
    }
    free (res->samples);

     for (i=0;res->timers[i]!=NULL;i++)
    {
        al_destroy_timer(res->timers[i]);
    }
    free (res->timers);


}
void LoadDrawResource(RESOURCE *res,CONFIG *config)
{
    res->bitmaps=calloc(InterfaceNumber,sizeof(ALLEGRO_BITMAP*));
    res->fonts=calloc(1,sizeof(ALLEGRO_FONT*));
    res->fonts[0]=al_load_font("./assets/SoukouMincho.ttf",config->unit*15,0);
    res->bitmaps[Cover]=al_load_bitmap("./assets/cover.png");
    res->bitmaps[Egg]=al_load_bitmap("./assets/egg.png");
    res->bitmaps[BreakEgg]=al_load_bitmap("./assets/breakedegg.png");
    res->bitmaps[PressedPlay]=al_load_bitmap("././assets/PressedPlay.png");
    res->bitmaps[PlayButton]=al_load_bitmap("././assets/PlayButton.png");
    res->bitmaps[ExitButton]=al_load_bitmap("././assets/ExitButton.png");
    res->bitmaps[PressedExit]=al_load_bitmap("././assets/PressedExit.png");
    res->bitmaps[Arrow]=al_load_bitmap("././assets/Arrow.png");
    res->bitmaps[Skeleton]=al_load_bitmap("././assets/Skeleton.png");
    res->bitmaps[CrackedEgg]=al_load_bitmap("././assets/CrackedEgg.png");
}
