
void drawSettingPage(RESOURCE *res, CONFIG *config,unsigned short control)
{
    int unit;
    unit=config->unit;
    al_clear_to_color(al_map_rgb(150,150,150));
    if(control%4==0)
         al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
    else al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5),ALLEGRO_ALIGN_CENTER,"%6s","RESUME");
    if(control%4==1)
        al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
    else al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*2,ALLEGRO_ALIGN_CENTER,"%7s","RESTART");
    if(control%4==2)
        al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
    else  al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*3,ALLEGRO_ALIGN_CENTER,"%5s","SOUND");
    if(control%4==3)
        al_draw_textf (res->fonts[0],al_map_rgb(0, 0, 0),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");
    else al_draw_textf (res->fonts[0],al_map_rgb(250, 250, 250),(unit*160)/2,((unit*90)/5)*4,ALLEGRO_ALIGN_CENTER,"%4s","MENU");
        al_flip_display();
}
