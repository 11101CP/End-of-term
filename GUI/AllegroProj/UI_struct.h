#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>

typedef struct
{
int unit;

} Config;

typedef enum
{
FULLSCREEN=0,
RESOLUTION=1,
PLAY=2,
QUIT=3,
}ButtonName;

typedef struct
{
float x;
float y;
float width;
float height;
bool active;
} UIButton;

typedef struct
{
bool drop;
int number;
int choise;
char *item[10];

}DropDownMenu;

typedef struct
{
ALLEGRO_FONT* font;
ALLEGRO_COLOR black;
ALLEGRO_COLOR gray;
ALLEGRO_COLOR grayer;
ALLEGRO_COLOR line;
ALLEGRO_COLOR white;

ALLEGRO_DISPLAY *display;
ALLEGRO_DISPLAY *sub;
ALLEGRO_BITMAP *thumbnail;

float unit;

}UIResource;
