#include <allegro5/allegro.h>

typedef struct CharaEvent
{
   int value;
} CharaEvent;

enum
{
CharaEventType = ALLEGRO_GET_EVENT_TYPE('C', 'H', 'E', 'V')
};
