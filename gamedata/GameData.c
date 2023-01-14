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
for(i=0;i<5;i++)
gamedata.id[i].point=0;
for(i=0;i<5;i++)
    strcpy(gamedata.id[i].name,"----------");







FILE *file = fopen("./GameData.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&gamedata, sizeof(GameData), 1, file);
    fclose(file);




    return 0;
}
