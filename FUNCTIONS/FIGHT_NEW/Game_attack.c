#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"

void loadAttack(STAGE *stage)
{

stage->attack=calloc(1,sizeof(AttackModule));
AttackModule *now=stage->attack;
for (int i=0;i<4;i++)
{
now->next=calloc(1,sizeof(AttackModule));
now->y=2*i;
now->x=2*i;
now->step=0;
now=now->next;
now->type=VERTIC;
}

}

void addAttack(STAGE *stage)
{
AttackModule *now =stage->attack;
for (int i=0;i<4;i++)
{
    now->step++;
    now=now->next;
}

}


void drawAttack(STAGE *stage,RESOURCE *res,CONFIG *config)

{
AttackModule *now = stage->attack;
BOX ***box =stage->box;
for (int i=0;i<4;i++)
{
    if(now->type==HORIZON)
    {
        if (now->step%3==2)
    {
    al_draw_line(box[0][0]->x,box[0][now->y]->y+stage->length/2,box[8][0]->x,box[0][now->y]->y+stage->length/2,al_map_rgb(255,255,255),3*config->unit);
    for(int x=0;x<9;x++)
    box[x][now->y]->damage=HURT;
    }
    else if (now->step%3==1)
    {
    al_draw_line(box[0][0]->x,box[0][now->y]->y+stage->length/2,box[8][0]->x,box[0][now->y]->y+stage->length/2,al_map_rgba(100,100,100,1),3*config->unit);
    for(int x=0;x<9;x++)
    box[x][now->y]->damage=NO;
    }
    else
    {

        for(int y=0;y<9;y++)

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
        if (now->step%3==2)
    {
    al_draw_line(box[now->x][0]->x+stage->length/2,box[0][0]->y,box[now->x][0]->x+stage->length/2,box[0][8]->y,al_map_rgb(255,255,255),3*config->unit);
    for(int y=0;y<9;y++)
    box[now->x][y]->damage=HURT;
    }
    else if (now->step%3==1)
    {
    al_draw_line(box[now->x][0]->x+stage->length/2,box[0][0]->y,box[now->x][0]->x+stage->length/2,box[0][8]->y,al_map_rgba(100,100,100,1),3*config->unit);
    for(int y=0;y<9;y++)
    box[now->x][y]->damage=NO;
    }
    else
    {
    for(int y=0;y<9;y++)
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
          if (now->step%3==2)
    {
    al_draw_filled_circle(box[now->x][now->y]->x+stage->length/2,box[now->x][now->y]->y+stage->length/2,config->unit*3,al_map_rgb(255,255,255));
    box[now->x][now->y]->damage=HURT;
    }
    else if (now->step%3==1)
    {
    al_draw_filled_circle(box[now->x][now->y]->x+stage->length/2,box[now->x][now->y]->y+stage->length/2,config->unit*3,al_map_rgba(100,100,100,1));
    box[now->x][now->y]->damage=NO;
    }
    else
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



now=now->next;
}

}
