#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"
#include "Loading_enum.h"

void loa7Attack(STAGE *stage)
{

stage->attack=calloc(1,sizeof(AttackModule));
AttackModule *now=stage->attack;

now->next=calloc(1,sizeof(AttackModule));
now->y=1;
now->x=2;
now->dx=6;
now->step=8;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=2;
now->x=2;
now->dx=6;
now->step=10;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=3;
now->x=2;
now->dx=6;
now->step=12;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=1;
now->x=1;
now->dx=4;
now->step=12;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=4;
now->x=2;
now->dx=6;
now->step=14;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=2;
now->x=1;
now->dx=4;
now->step=14;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=3;
now->x=1;
now->dx=4;
now->step=16;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=1;
now->x=5;
now->dx=4;
now->step=18;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=4;
now->x=1;
now->dx=4;
now->step=18;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=2;
now->x=5;
now->dx=4;
now->step=20;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=3;
now->x=5;
now->dx=4;
now->step=22;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=1;
now->x=2;
now->dx=6;
now->step=24;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=4;
now->x=5;
now->dx=4;
now->step=24;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=1;
now->y=1;
now->dx=1;
now->dy=1;
now->step=24;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=4;
now->y=1;
now->dx=1;
now->dy=1;
now->step=24;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=7;
now->y=1;
now->dx=1;
now->dy=1;
now->step=24;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=2;
now->y=3;
now->dx=1;
now->dy=1;
now->step=24;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=5;
now->y=3;
now->dx=1;
now->dy=1;
now->step=24;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=8;
now->y=3;
now->dx=1;
now->dy=1;
now->step=24;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=1;
now->y=1;
now->dx=1;
now->dy=3;
now->step=26;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=8;
now->y=1;
now->dx=1;
now->dy=3;
now->step=26;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=1;
now->y=1;
now->dx=3;
now->dy=3;
now->step=28;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=6;
now->y=1;
now->dx=3;
now->dy=3;
now->step=28;
now->type=AREA;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=1;
now->x=0;
now->step=26;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=3;
now->x=0;
now->step=27;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=2;
now->x=0;
now->step=28;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=4;
now->x=0;
now->step=29;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=1;
now->x=0;
now->step=30;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=3;
now->x=0;
now->step=30;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=2;
now->x=0;
now->step=31;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=4;
now->x=0;
now->step=31;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=3;
now->x=2;
now->dx=6;
now->step=28;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=4;
now->x=2;
now->dx=6;
now->step=30;
now->type=LINE;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=2;
now->x=0;
now->step=26;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->y=3;
now->x=0;
now->step=26;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=1;
now->step=27;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=4;
now->step=27;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=3;
now->step=28;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=4;
now->step=28;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=2;
now->step=29;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=3;
now->step=29;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=1;
now->step=30;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=4;
now->step=30;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=1;
now->step=31;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=2;
now->step=31;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=3;
now->step=32;
now->type=HORIZON;
now=now->next;

now->next=calloc(1,sizeof(AttackModule));
now->x=0;
now->y=4;
now->step=32;
now->type=HORIZON;
now=now->next;

//https://www.youtube.com/watch?v=3HhFV7yy9Xo 0:56

now->next=calloc(1,sizeof(AttackModule));//¤j¿E¥ú(2,1)(8,4)
now->x=2;
now->y=1;
now->dx=6;
now->dy=3;
now->step=;
now->type=AREA;
now=now->next;//second stage end

}

void clearAttack(STAGE *stage)
{
AttackModule *now =stage->attack;
AttackModule *next;

for (;now!=NULL;now=next)
{
    next=now->next;
    free(now);
}



}

void addAttack(STAGE *stage)
{
AttackModule *now =stage->attack;
for (;now!=NULL; now=now->next)
{
    now->step--;

}

}


void drawAttack(STAGE *stage,RESOURCE *res,CONFIG *config)

{
AttackModule *now = stage->attack;
BOX ***box =stage->box;
for (;now!=NULL;now=now->next)
{
    if(now->type==HORIZON)
    {
        if (now->step==1)
    {
    //al_draw_line(0,box[0][now->y]->y+stage->length/2,190*config->unit,box[0][now->y]->y+stage->length/2,al_map_rgb(255,255,255),3*config->unit);
    int length=stage->length*(1+res->temp);
    if (length>=config->unit*160)
    length=config->unit*160;

//if(al_get_timer_count(res->timers[AttackTime])%3)
    al_draw_scaled_bitmap(res->bitmaps[Attack],0,0,960,60,0,box[0][now->y]->y,length,stage->length,0);
//else
    al_draw_scaled_bitmap(res->bitmaps[Attack],0,0,960,60,160*config->unit-length,box[0][now->y]->y,length,stage->length,1);


    for(int x=0;x<11;x++)
    box[x][now->y]->damage=HURT;
    }
    else if (now->step==3)
    {
    al_draw_line(0,box[0][now->y]->y+stage->length/2,190*config->unit,box[0][now->y]->y+stage->length/2,al_map_rgba(150,10,10,1),3*config->unit);

    }
    else if (now->step==0)
    {

        for(int y=0;y<6;y++)

        box[now->x][y]->damage=NO;
        now->y=rand()%8;
        int chance=rand()%3;
        if (chance==0)
            now->type=VERTIC;
        else if(chance==1)
            now->type=HORIZON;
        else if(chance==2)
            now->type=POINT;
    }
    }

    if(now->type==VERTIC)
    {
        if (now->step==1)
    {
    al_draw_line(box[now->x][0]->x+stage->length/2,0,box[now->x][0]->x+stage->length/2,90*config->unit,al_map_rgb(255,255,255),3*config->unit);
    for(int y=0;y<6;y++)
    box[now->x][y]->damage=HURT;
    }
    else if (now->step==3)
    {
    al_draw_line(box[now->x][0]->x+stage->length/2,0,box[now->x][0]->x+stage->length/2,90*config->unit,al_map_rgba(150,10,10,1),3*config->unit);
    for(int y=0;y<6;y++)
    box[now->x][y]->damage=NO;
    }
    else if(now->step==0)
    {
    for(int y=0;y<6;y++)
    box[now->x][y]->damage=NO;
    now->x=rand()%8;
        int chance=rand()%3;
        if (chance==0)
            now->type=VERTIC;
        else if(chance==1)
            now->type=HORIZON;
        else if(chance==2)
            now->type=POINT;
    }
    }
     if(now->type==POINT)
     {
          if (now->step%4==3)
    {
    al_draw_filled_circle(box[now->x][now->y]->x+stage->length/2,box[now->x][now->y]->y+stage->length/2,config->unit*3,al_map_rgb(255,255,255));
    box[now->x][now->y]->damage=HURT;
    }
    else if (now->step%4==1)
    {
    al_draw_filled_circle(box[now->x][now->y]->x+stage->length/2,box[now->x][now->y]->y+stage->length/2,config->unit*3,al_map_rgba(150,10,10,1));
    box[now->x][now->y]->damage=NO;
    }
    else if (now->step%4==0)
    {

        box[now->x][now->y]->damage=NO;
        now->y=rand()%8;
        now->x=rand()%8;
        int chance=rand()%3;

        if (chance==0)
            now->type=VERTIC;
        else if(chance==1)
            now->type=HORIZON;
        else if(chance==2)
            now->type=POINT;
    }


     }
     if(now->type==LINE)
    {
        if (now->step==1)
    {
    al_draw_line(box[now->x][now->y]->x+stage->length/2,box[now->x][now->y]->y+stage->length/2,
                 box[now->x+now->dx][now->y+now->dy]->x-stage->length/2,box[now->x+now->dx][now->y+now->dy]->y+stage->length/2,al_map_rgb(255,255,255),3*config->unit);
    for(int y=0;y<6;y++)
    box[now->x][y]->damage=HURT;
    }
    else if (now->step==2)
    {
    al_draw_line(box[now->x][now->y]->x+stage->length/2,box[now->x][now->y]->y+stage->length/2,
                 box[now->x+now->dx][now->y+now->dy]->x-stage->length/2,box[now->x+now->dx][now->y+now->dy]->y+stage->length/2,al_map_rgba(150,10,10,1),3*config->unit);
    for(int y=0;y<6;y++)
    box[now->x][y]->damage=NO;
    }
    else if(now->step==0)
    {
    for(int y=0;y<6;y++)
    box[now->x][y]->damage=NO;

    }

    }


}

}
