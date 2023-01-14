#include "Common.h"
#include "AL_general.h"



int main()
{

    al_setup();
    CONFIG config;
    config.unit=8;
    config.stage=9;

  //  (config,);
    RESOURCE res;
    res.CharaHitten=al_load_sample("./Chara_Hitten.wav");
    res.display=al_create_display(160*config.unit,90*config.unit);
    res.trap=al_load_bitmap("./beartrap.png");
    res.block=al_load_bitmap("./Brick.png");
    res.belt=al_load_bitmap("./belt.png");
    res.chara=al_load_bitmap("./duck.png");
    res.fonts=al_load_font("./Type,ttf",config.unit*5,0);
    res.FlexSpikeOn=al_load_bitmap("./SpikeOn.png");
    res.FlexSpikeOff=al_load_bitmap("./SpikeOff.png");
    res.CharaMove=al_load_sample("./Chara_Moving.wav");
    res.ObjHitten=al_load_sample("./Hit_Object_Sound.wav");
    res.DoorOpen=al_load_sample("./Door_Open.wav");
    res.MonsterHitten=al_load_sample("./Monster_Hitten.wav");
    res.MonsterDie=al_load_sample("./Monster_Die.wav");
    res.GamePause=al_load_sample("./Game_Pause.wav");
    res.GameRestart=al_load_sample("./Game_Restart.wav");
    //al_draw_text(res.fonts,al_map_rgb(255,255,255),0,0,0,"50");

    gameSetUp(&config,&res);




    al_cleanup();
    return 0;
}



