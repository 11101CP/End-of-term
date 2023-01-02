#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"




bool Fight(CONFIG *config,STAGE *stage,RESOURCE *res)
{
    loadAttack(stage);
    int i=0,j=0;
    int unit=config->unit;
    bool exit=false;
    bool shift=true;
    CHARA chara;
    chara.x=4;
    chara.y=4;
    chara.facingRight=0;
    chara.step=0;
    chara.state=CH_STAY;
    chara.life=3;

    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_TIMER* refresh = NULL;
    ALLEGRO_TIMER* attack = NULL;
    ALLEGRO_EVENT events;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;

//    buildchara (&chara,*config);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 /60);//CONTROL MOVEMENT          24 frame per sec
    refresh = al_create_timer(1.0/18 );//refresh

    attack = al_create_timer(1 );


    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(res->display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(refresh));
    al_register_event_source(event_queue, al_get_timer_event_source(attack));

    al_start_timer(timer);
    al_start_timer(refresh);



    while(!exit)
    {

    if(!al_is_event_queue_empty(event_queue))
        {
            while(al_get_next_event(event_queue, &events))
            {


                if(chara.life>0)
                switch(events.type)
                {
                case ALLEGRO_EVENT_KEY_DOWN:
                    moveChara(&chara,stage,&events.keyboard);
                    if (events.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                        boxShift(stage,res,config);
                    break;//SETTING;

                    break;
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    puts("Oops");
                    exit=true;
                    break;
                case ALLEGRO_EVENT_TIMER:


                    if(events.timer.source==timer)
                    {
                    drawMap(stage,res,config);
                    drawObject(stage,res,config);
                    drawChara(&chara,stage,res,config);
                    detectCharaDamage(&chara,stage);
                    printf("1");
                    drawAttack(stage,res,config);




                    //al_draw_filled_rectangle(0,0,160*config->unit,22*config->unit,al_map_rgb(0,0,0));
                    //al_draw_filled_rectangle(0,68*config->unit,160*config->unit,90*config->unit,al_map_rgb(0,0,0));
                    al_flip_display();
                    }
                    if(events.timer.source==refresh)
                    {
                        if (events.timer.count==32)
                            al_start_timer(attack);

                    //boxShift(stage,res,config);
                    printf("\nboing\n");

                    if(++chara.step==14)
                        {chara.step=0;
                        chara.state=CH_STAY;}
                    }


                    if(events.timer.source==attack)
                    {
                        //loadAttack;
                    //stage->
                    addAttack(stage);

                    printf("\naddAttackObject\n");
                    }









                  //  if (shift)
                        //drawSheftObjext(&stage);
                    //else

                    break;

                }  //end of switch
                    else
                        {
                        al_pause_event_queue(event_queue,true);
                        death(res,stage ,config);
                        al_flip_display();
                        al_rest(2);
                        printf("restart");
                        chara.life=10;
                         al_pause_event_queue(event_queue,false);
                         if(++chara.y>8)
                            chara.y=0;
                          if(++chara.y>8)
                            chara.y=0;
                             if(++chara.y>8)
                            chara.y=0;
                         chara.x=4;
                        }






            }



        }



   // al_flip_display();

    }


}
