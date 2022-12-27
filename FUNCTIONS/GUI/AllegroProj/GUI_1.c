#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

int getScreenInfo (void)
{
    ALLEGRO_MONITOR_INFO info;

    al_get_monitor_info(0,&info);


    printf("%d %d %d %d\n",info.x1,info.x2,info.y1,info.y2);

    int x = info.x2/16;
    int y = info.y2/9;
    int set;

    if (x<y)
    set=x;
    else
        set=y;
        set=set/20;

    printf("x=%d  y=%d\n\n",x,y);

    switch(set)
    {
    default:
    case 12:
        puts("3840x2160");
    case 11:
    case 10:
        puts("3200x1800");
    case 9:
        puts("2880x1620");
    case 8:
        puts("2560x1440");
    case 7:
        puts("2240x1260");
    case 6:
        puts("1920x1080");
    case 5:
        puts("1600x900");
    case 4:
        puts("1280x720");
    case 3:
        puts("960x540");
        break;
    case 2:
    case 1:
    case 0:
        puts("incompatible monitor");
    }

    set-=3;
return set;
}


