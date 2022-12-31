#include "AlHeader.h"

int main()
{
    srand(time(0));

    Resource res;
    while(res.data.state!=EXIT)
    {
        drawMenu(&res);
        drawStageMenu(&res);
    }


    return 0;
}
