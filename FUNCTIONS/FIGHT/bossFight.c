#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"


//
//bool Boss(CONFIG *config,RESOURCE *res)
//{
//    int unit=config->unit;
//    bool exit=false;
//    bool shift=true;
//
//    ALLEGRO_TIMER* timer = NULL;
//    ALLEGRO_EVENT events;
//    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
//
//    STAGE stage;
//    CHARA chara;
//
//    setStage(&stage);
//    buildchara (&chara,*config);
//    event_queue = al_create_event_queue();
//    timer = al_create_timer(1.0 /24);//CONTROL MOVEMENT          24 frame per sec
//
//
//    al_register_event_source(event_queue, al_get_keyboard_event_source());
//    al_register_event_source(event_queue, al_get_display_event_source(display));
//    al_register_event_source(event_queue, al_get_timer_event_source(timer));
//
//    al_start_timer(timer);
//
//    while(!exit)
//    {
//
//    if(!al_is_event_queue_empty(event_queue))
//        {
//            while(al_get_next_event(event_queue, &events))
//            {
//                switch(events.type)
//                {
//                case ALLEGRO_EVENT_KEY_DOWN:
//                    moveChara(box,&chara,&events.keyboard);
//                    if (events.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
//                        break;//SETTING;
//
//                    break;
//                case ALLEGRO_EVENT_DISPLAY_CLOSE:
//                    exit=true;
//                    break;
//                case ALLEGRO_EVENT_TIMER:
//
//                    if (shift)
//                        drawSheftObjext(&stage);
//                    else
//
//
//
//
//                    break;
//
//
//                }
//            }
//        } //end of event queue
//
//    drawmap(&stage,res);
//
//    //drawObject(&stage,res);  //enemy
//    drawChara(&chara,&stage);
//
//
//    //drawTimer
//
//
//    al_flip_display()
//
//    }
//
//
//    end
//}
//
//
//
//


//
//
//
//    al_start_timer(timer);
//    printf("123");
//    while(1)
//    {
//        printf("%d\n",al_get_timer_count(timer));
//        al_clear_to_color(al_map_rgb(250,250,250));
//        al_draw_filled_rectangle(40*unit ,0,120*unit,unit*90,al_map_rgb(50,50,50));
//
//        al_wait_for_event(event_queue, &events);
//
//        al_rest(0.1);
//        for (int x=0;x<9;x++)
//            for(int y=0;y<9;y++)
//               {
//                 al_draw_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(0,0,0),1);
//                switch(box[x][y]->state)
//                {
//                    case BLOCK:
//                al_draw_filled_rectangle(box[x][y]->x,box[x][y]->y,box[x][y]->x+9*unit,box[x][y]->y+9*unit,al_map_rgb(150,50,50));
//                    break;
//                }
//                if(shift==true)
//                {
//                    box[x][y]->y-=unit;
//                if (box[x][y]->y<=4*unit)
//                    {//box->temp=
//                        box[x][y]->y=76*unit;
//                        int temp;
//                        int dy=y+1;
//                        if (dy==9)
//                            dy=0;
//                        temp= box[x][y]->state;
//                        box[x][y]->state=box[x][dy]->state;
//                        box[x][dy]->state=temp;
//                        dy=y-8;
//                        if (dy<0)
//                            dy=8+dy;
//                        int dy1=dy-1;
//                        if (dy1<0)
//                            dy1=8;
//                        temp= box[x][dy]->state;
//                        box[x][dy]->state=box[x][dy1]->state;
//                        box[x][dy1]->state=temp;
//
//                    }
//
//                }
//
//                }
//
//       drawChara(&chara,box);
//
//
//        if(!al_is_event_queue_empty(event_queue))
//
//            while(al_get_next_event(event_queue, &events))
//                switch(events.type)
//            {
//            case ALLEGRO_EVENT_KEY_DOWN:
//                moveChara(box,&chara,&events.keyboard);
//                break;
//            case ALLEGRO_EVENT_KEY_CHAR:
//
//
//            }
//
//
//
//
//
//
//    al_draw_filled_rectangle(0,0,160*unit,13*unit,al_map_rgb(0,0,0));
//    al_draw_filled_rectangle(0,76*unit,160*unit,90*unit,al_map_rgb(0,0,0));
//    al_flip_display();
//
//
//    }
//
//    system("pause");
//
//    freeBox (box,9,8);
//
//
//   al_draw_filled_rectangle()
//
//    al_destroy_display(display);
//
//
//
//
//}
