#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include<string.h>

typedef struct
{
    char name[10];
    int point;
}LeaderBoard;

typedef struct
{

int ProgressPuzzle;
int ProgressFight;
LeaderBoard id[5];

}GameData;

int main()
{
int i;

GameData gamedata;





 FILE *file = fopen("./GameData.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return false;
    }
fread(&gamedata, sizeof(GameData), 1, file);
for(i=0;i<5;i++)
{
    printf("%d\n",gamedata.id[i].point);
    printf("%s\n",gamedata.id[i].name);
}


    fclose(file);
    return true;
}

