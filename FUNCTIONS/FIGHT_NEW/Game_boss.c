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
    ALLEGRO_EVENT simpleEvent;

    al_init_user_event_source(res->user_src);

    res->queues=al_create_event_queue();

    al_register_event_source(res->queues, al_get_keyboard_event_source());
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[FPS]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[Refresh]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[AttackTime]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[Second]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[BeltSheft]));
    //al_register_event_source(res->queues, al_get_display_event_source(res->display));
    al_register_event_source(res->queues, res->user_src);


    al_start_timer(res->timers[FPS]);
    al_start_timer(res->timers[Refresh]);
    //al_start_timer(res->timers[BeltSheft]);
    al_start_timer(res->timers[Second]);

  puts("here");

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
                        simpleEvent.user.type=GameSetting;
                        al_emit_user_event(res->user_src, &simpleEvent, NULL);
                        }
                    else if (events.keyboard.keycode==ALLEGRO_KEY_R)
                        {
                        simpleEvent.user.type=GameRestart;
                        al_emit_user_event(res->user_src, &simpleEvent, NULL);
                        }

                    break;  /** end of event type KEY_DOWN **/

                case ALLEGRO_EVENT_KEY_CHAR:
                    controlChara_Boss(stage,&events.keyboard);
                    break; /** end of event type KEY_CHAR **/

                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    puts("Oops");
                    exit=true;
                    break; /** end of event type DISPLAY_CLOSE **/

                case ALLEGRO_EVENT_TIMER:

                    if(events.timer.source==res->timers[FPS])
                    {
                        res->temp++;
                    al_flip_display();

                    charaOperate(stage,config);

                    drawMap(stage,res,config);
                    drawObject(stage,res,config);


                    detectCharaDamage(stage,config);

                    if(stage->chara->life<=0)
                        {
                        simpleEvent.user.type=CharaDeath;
                        al_emit_user_event(res->user_src, &simpleEvent, NULL);
                        }



                    //al_draw_filled_rectangle(stage->box[0][0]->x,stage->box[0][0]->y,stage->box[1][1]->x,stage->box[1][1]->y,al_map_rgb(255,0,0));
                    //al_draw_line(0,4*config->unit,160*config->unit,4*config->unit,al_map_rgb(255,255,255),1);

                    }   /** end of source FPS **/

                    if(events.timer.source==res->timers[Second])
                    {
                        switch(al_get_timer_count(res->timers[Second]))
                            {
                            case 5:
                                al_start_timer(res->timers[AttackTime]);
                                break;

                            case 10:
                                for(int i=0;i<2;i++)
                                    stage->target[i].vulnerable=true;

                                //////////////////////////////////////////////////////////add boss
                                break;
                            }

                    }   /** end of source Second **/

                    if(events.timer.source==res->timers[Refresh])
                    {
                        nextCharaFrame(stage->chara);

                    }   /** end of source Rrfresh **/


                    if(events.timer.source==res->timers[BeltSheft])
                    {

                        boxShift(stage,res,config);
                        if (al_get_timer_count(res->timers[Second])>10&&stage->box[0][0]->y==stage->boxStartY)
                        {
                            al_stop_timer(res->timers[BeltSheft]);
                            al_set_timer_count(res->timers[BeltSheft],0);
                        }

                    }   /** end of source BeltSheft **/


                    if(events.timer.source==res->timers[AttackTime])
                    {
                        res->temp=0;
                    //loadAttack;
                    //stage->
                    addAttack(stage);
                    }   /** end of source AttackTime **/


                    break; /** end of event type time event **/

                    case CharaDeath:


                        {
                        simpleEvent.user.type=GameRestart;
                        al_emit_user_event(res->user_src, &simpleEvent, NULL);
                        }

                        death(res,stage ,config);
                        break;  /** end of event type CharaDeath **/

                    case GameRestart:

                        al_destroy_user_event_source(res->user_src);
                        al_destroy_event_queue(res->queues);
                        for (i=0;i<3;i++)
                        {
                        al_stop_timer(res->timers[i]);
                        al_set_timer_count(res->timers[i],0);
                        }
                        al_stop_timer(stage->chara->timer);
                        return 0;
                        break;  /** end of event type GameRestart **/

                    case GameQuit:
                        al_destroy_user_event_source(res->user_src);
                        al_destroy_event_queue(res->queues);
                        for (i=0;i<3;i++)
                        {
                        al_stop_timer(res->timers[i]);
                        al_set_timer_count(res->timers[i],0);
                        }
                        al_stop_timer(stage->chara->timer);
                        return 1;
                        break;  /** end of event type GameQuit **/

                    case GameSetting:
                        death(res,stage ,config);
                        al_flush_event_queue(res->queues);
                        break;


                }  //end of switch
            }//end of while(al_get_next_event)
        }//out of event queue
    } //end of while (1)
}//end if fight()
