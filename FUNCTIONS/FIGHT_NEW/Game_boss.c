#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"
#include "Loading_enum.h"




bool Fight(CONFIG *config,STAGE *stage,RESOURCE *res)
{

    int i=0,j=0;
    int unit=config->unit;
    bool exit=false;


    ALLEGRO_EVENT events;

    al_init_user_event_source(res->user_src);



    res->queues=al_create_event_queue();

    al_register_event_source(res->queues, al_get_keyboard_event_source());


    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[FPS]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[Refresh]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[AttackTime]));
   // al_register_event_source(res->queues, al_get_display_event_source(res->display));
    al_register_event_source(res->queues, res->user_src);


    al_start_timer(res->timers[FPS]);
    al_start_timer(res->timers[Refresh]);




    while(1)
    {

    if(!al_is_event_queue_empty(res->queues))
        {
            while(al_get_next_event(res->queues, &events))
            {
                switch(events.type)
                {
                case ALLEGRO_EVENT_KEY_DOWN:
                    if (events.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                        {
                            exit = true;//settingWindow;
                        }
                    break; // end of ALLEGRO_EVENT_KEY_DOWN

                case ALLEGRO_EVENT_KEY_CHAR:
                    controlChara(stage,&events.keyboard);


                    break; // end of ALLEGRO_EVENT_KEY_CHAR

                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    puts("Oops");
                    exit=true;
                    break; // end of ALLEGRO_EVENT_DISPLAY_CLOSE

                case ALLEGRO_EVENT_TIMER:

                    if(events.timer.source==res->timers[FPS])
                    {
                    al_flip_display();

                    drawMap(stage,res,config);
                    drawObject(stage,res,config);


                    detectCharaDamage(stage,config);
                    if(stage->chara->life<=0)
                        {
                        ALLEGRO_EVENT event;
                        event.user.type=CharaDeath;
                        al_emit_user_event(res->user_src, &event, NULL);
                        }
                    charaOperate(stage,config);


                    //al_draw_filled_rectangle(stage->box[0][0]->x,stage->box[0][0]->y,stage->box[1][1]->x,stage->box[1][1]->y,al_map_rgb(255,0,0));
                    //al_draw_line(0,4*config->unit,160*config->unit,4*config->unit,al_map_rgb(255,255,255),1);

                    }

                    if(events.timer.source==res->timers[Refresh])
                    {
                        if (events.timer.count==32)
                            al_start_timer(res->timers[AttackTime]);

                        if(al_get_timer_count(res->timers[Refresh])<244)
                            boxShift(stage,res,config);
                        else al_stop_timer(res->timers[Refresh]);
                    printf("\nboing\n");


                    }


                    if(events.timer.source==res->timers[AttackTime])
                    {
                        //loadAttack;
                    //stage->
                    addAttack(stage);

                    printf("\naddAttackObject\n");
                    }//end of timer.source==attack

                    break;

                    case CharaDeath:

                        al_destroy_event_queue(res->queues);
                        al_destroy_timer(res->timers[0]);
                        al_destroy_timer(res->timers[1]);
                        al_destroy_timer(res->timers[2]);
                        al_destroy_timer(res->timers[3]);

                        death(res,stage ,config);


                        al_rest(2);

                        al_stop_timer(stage->chara->timer);

                        freeBox(stage->box,9,9);

                        printf("%x",stage->box);

                        return 0;



                }  //end of switch


            }

        }//out of event queue

    } //end of while (1)

}//end if fight()
