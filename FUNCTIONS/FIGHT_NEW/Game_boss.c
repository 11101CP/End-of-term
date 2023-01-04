#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"
#include "Loading_enum.h"



bool Fight(CONFIG *config,STAGE *stage,RESOURCE *res)
{


    int i=0,j=0;
    int unit=config->unit;
    bool exit=false;

    loadChara (stage);
    CHARA *chara = stage->chara;




    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_TIMER* refresh = NULL;
    ALLEGRO_TIMER* attack = NULL;
    ALLEGRO_TIMER* move=NULL;
    ALLEGRO_EVENT events;


    res->queues=al_create_event_queue();
    timer = al_create_timer(1.0 /60);//CONTROL MOVEMENT
    refresh = al_create_timer(1.0/9 );//refresh
    move=al_create_timer(1.0/30);
    attack = al_create_timer(1.0 );



    al_register_event_source(res->queues, al_get_keyboard_event_source());

    //al_register_event_source(res->queues, al_get_display_event_source(res->display));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[FPS]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[Refresh]));
    al_register_event_source(res->queues, al_get_timer_event_source(res->timers[AttackTime]));
   // al_register_event_source(res->queues, al_get_timer_event_source(move));

    al_start_timer(res->timers[FPS]);
    al_start_timer(res->timers[Refresh]);
    al_start_timer(move);



    while(!exit)
    {

    if(!al_is_event_queue_empty(res->queues))
        {
            while(al_get_next_event(res->queues, &events))
            {


                if(chara->life>0)
                switch(events.type)
                {
                case ALLEGRO_EVENT_KEY_DOWN:
                    moveChara(chara,stage,&events.keyboard);

                    if (events.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                        {exit = true;//settingWindow;
                            for (int i=0;i<10;i++);
                                al_stop_timer(res->timers[i]);
                        }

                    break;

                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    puts("Oops");
                    exit=true;
                    break;

                case ALLEGRO_EVENT_TIMER:


                    if(events.timer.source==res->timers[FPS])
                    {
                    drawMap(stage,res,config);
                    al_draw_scaled_bitmap(res->bitmaps[Belt],0,0,400,748,stage->box[1][0]->x,(13-al_get_timer_count(refresh)%10)*unit,stage->length*7,stage->length*8,0);
                    al_draw_scaled_bitmap(res->bitmaps[Saw],0,600*(al_get_timer_count(refresh)%2),1688,600,config->unit*49,config->unit*13,stage->length*7,stage->length,0);
                    al_draw_scaled_bitmap(res->bitmaps[Saw],0,600*(al_get_timer_count(refresh)%2),1688,600,config->unit*49,config->unit*68,stage->length*7,stage->length,0);
                    al_draw_scaled_bitmap(res->bitmaps[Layer],0,0,960,540,0,0,160*config->unit,90*config->unit,0);
                    drawObject(stage,res,config);
                    drawChara(chara,stage,res,config);

                    detectCharaDamage(chara,stage,config);
                    printf("1");
                    drawAttack(stage,res,config);
                    drawLifaIndicate (stage,res,config );









                   // al_draw_filled_rectangle(0,0,160*config->unit,17*config->unit,al_map_rgb(0,0,0));
                    //al_draw_filled_rectangle(0,72*config->unit,160*config->unit,90*config->unit,al_map_rgb(0,0,0));
                    al_draw_filled_rectangle(stage->box[0][0]->x,stage->box[0][0]->y,stage->box[1][1]->x,stage->box[1][1]->y,al_map_rgb(255,0,0));
                    al_draw_line(0,4*config->unit,160*config->unit,4*config->unit,al_map_rgb(255,255,255),1);

                    al_flip_display();

                    }

                    if(events.timer.source==res->timers[Refresh])
                    {
                        if (events.timer.count==32)
                            al_start_timer(res->timers[AttackTime]);

                        if(al_get_timer_count(refresh)<244)
                            boxShift(stage,res,config);
                        else al_stop_timer(refresh);
                    printf("\nboing\n");


                    }//end of timer.source==refresh
                    if(events.timer.source==move)
                    {
                        if(chara->offsetX>0)
                                chara->offsetX-=config->unit;
                            else if (chara->offsetX<0)
                                chara->offsetX+=config->unit;
                            if(chara->offsetY>0)
                                chara->offsetY-=config->unit;
                            else if (chara->offsetY<0)
                                chara->offsetY+=config->unit;
                                if(++chara->step==14)
                        {chara->step=0;
                        chara->state=CH_STAY;}

                    }//end of timer.source==move


                    if(events.timer.source==res->timers[AttackTime])
                    {
                        //loadAttack;
                    //stage->
                    addAttack(stage);

                    printf("\naddAttackObject\n");
                    }//end of timer.source==attack

                    break;

                }  //end of switch
                    else
                        {
                        al_pause_event_queue(res->queues,true);
                        death(res,stage ,config);
                        //al_draw_text(res->font,al_map_rgb(255,0,0),unit*80,unit*10,ALLEGRO_ALIGN_CENTER,"YOU DEAD");

                        al_flip_display();
                        al_rest(2);
                        printf("restart");
                        al_destroy_event_queue(res->queues);
                        al_destroy_timer(timer);
                        al_destroy_timer(refresh);
                        al_destroy_timer(attack);
                        al_destroy_timer(move);
                        al_stop_timer(chara->timer);


                        return false;

                        }






            }



        }



   // al_flip_display();

    }


}
