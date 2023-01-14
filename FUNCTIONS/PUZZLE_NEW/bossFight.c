#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

bool Fight(CONFIG *config,STAGE *stage,RESOURCE *res)
{

    int i=0,j=0;
    int unit=config->unit;
    bool exit=false;
    bool shift=true;
    CHARA chara;
    chara.x=6;/**start**/
    chara.y=5;
    chara.life=33;/**Character life**/
    chara.facingRight=0;
    chara.step=0;
    chara.vulnerable=false;
    stage->chara = &chara;

    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_TIMER* refresh = NULL;
    ALLEGRO_EVENT events;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;

//    buildchara (&chara,*config);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 /60);//CONTROL MOVEMENT          24 frame per sec
    refresh = al_create_timer(1.0/18 );//refresh


    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(res->display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(refresh));
    al_start_timer(timer);
    al_start_timer(refresh);


    if(chara.life==0)
    printf("X\n");
    else
    printf("%d\n",chara.life);
    while(!exit)
    {

    if(!al_is_event_queue_empty(event_queue))
        {
            while(al_get_next_event(event_queue, &events))
            {
                drawMap(stage,res,config);

                switch(events.type)
                {
                case ALLEGRO_EVENT_KEY_DOWN:
                    if(moveChara(stage,&events.keyboard,res))
                    {
                    TrapFunc(stage,res,config);
                    if (stage->box[stage->chara->x][stage->chara->y]->damage)  //extra
                    {
                        al_play_sample(res->CharaHitten,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
                        stage->chara->life--;
                    }
                    }
                    if(chara.life==0)
                        printf("X");
                    else
                        printf("%d\n",chara.life);
                    if (events.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                    break;//SETTING;

                    break;
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    exit=true;
                    break;
                case ALLEGRO_EVENT_TIMER:


                    if(events.timer.source==timer)
                    {
                    drawMap(stage,res,config);
                    drawObject(stage,res,config);
                    drawChara(&chara,stage,res,config);



                    //al_draw_textf(res->fonts,al_map_rgb(255,255,255),0,0,0,"%d",chara.life);


                    al_flip_display();
                    }
                    if(events.timer.source==refresh)
                    //boxShift(stage,res,config);
                    if(++chara.step==14)
                        chara.step=0;
                    }



                    //if (shift)
                        //drawSheftObjext(&stage);
                    //else

                    break;

                }



            }



        }



   // al_flip_display();

    }
