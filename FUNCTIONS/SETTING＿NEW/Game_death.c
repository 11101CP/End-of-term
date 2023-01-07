#include "Common.h"
#include "AL_general.h"
#include "Game_frame.h"
#include "Loading_enum.h"

int death(RESOURCE* res,STAGE *stage ,CONFIG *config)
{
    int unit=config->unit;
    int choose = Death1;
    //choose+=rand()%2;

    //fix with draw_centered_bitmap

    for (int i=0;i<60;i++)
   {
    al_draw_tinted_scaled_bitmap(res->bitmaps[choose],al_map_rgba(2*i,2*i,2*i,2*i),0,0,275,183,0*unit,0*unit,160*unit,90*unit,0);
    al_draw_text(res->fonts[0],al_map_rgb(255,0,0),unit*80,unit*10,ALLEGRO_ALIGN_CENTER,"YOU DIED");
    al_flip_display();
    al_rest(0.05);
   }

}
