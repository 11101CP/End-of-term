#include "AL_general.h"
#include "Game_frame.h"
#include "Loading_enum.h"
#include "common.h"


void loadBossFightResource(RESOURCE *res,CONFIG *config)
{

    res->bitmaps=calloc(BossBitmapsNumber,sizeof(ALLEGRO_BITMAP*));
    res->bitmaps[Background]=al_load_bitmap("./assets/freakinghigh.png");
    res->bitmaps[Belt]=al_load_bitmap("./assets/belt.png");
    res->bitmaps[Chara]=al_load_bitmap("./assets/duck.png");
    res->bitmaps[Saw]=al_load_bitmap("./assets/saw.png");
    res->bitmaps[Layer]=al_load_bitmap("./assets/layer.png");
    res->bitmaps[Life]=al_load_bitmap("./assets/life.png");
    res->bitmaps[Death]=al_load_bitmap("./assets/death.png");
    res->bitmaps[Death1]=al_load_bitmap("./assets/death1.png");
    res->bitmaps[Target]=al_load_bitmap("./assets/lever.png");
    res->bitmaps[Effect]=al_load_bitmap("./assets/effect.png");


    res->fonts=calloc(2,sizeof(ALLEGRO_FONT*));
    res->fonts[0]=al_load_font("./assets/SoukouMincho.ttf",config->unit*15,0);
    res->fonts[1]=al_load_font("./assets/SoukouMincho.ttf",config->unit*8,0);


//    res->samples=calloc();

    res->timers=calloc(BossTimerNumber,sizeof(ALLEGRO_TIMER*));
    res->timers[FPS]=al_create_timer(1.0 /60);
    res->timers[AttackTime] = al_create_timer(1.0/3 );//refresh
    res->timers[Refresh]=al_create_timer(1.0/24);
    res->timers[Second]=al_create_timer(1.0);
    res->timers[BeltSheft]=al_create_timer(1.0/9);


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
