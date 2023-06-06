#include<stdio.h>
#include<string.h>
#define LEN 30
#define NUM_OF_MOVE 20
#define FFMI (x<17) ? 1 : (17<=x<=21) ? 1.5 : 2
#define LV (y==1) ? 1 : (y==2) ? 1.5 : (y==3) ? 2 : printf("Too High")

struct move
{
    char name[LEN];
    int set, weight, number;
}all_move[NUM_OF_MOVE];



int main()
{

    FILE *FILE_check_move=fopen("C:/Users/roych/C projects/for-SDL/data.txt","r");
    if(FILE_check_move==NULL)
    {
        printf("(fail)\n");
    }
    int check_move, x, y;
    int i=0;
    while(fscanf(FILE_check_move,"%s %d %d %d",&all_move[i].name,&all_move[i].set,&all_move[i].weight,&all_move[i].number)!=EOF)
    {
        i++;
    }

    for(int i=0;i<24;i++)
    {
        printf("%s %d %d %d\n",all_move[i].name,all_move[i].set,all_move[i].weight,all_move[i].number);
    }

    printf("input the FFMI\n");
    scanf("%d", &x);
    for (int i = 0; i < 23; i++)
    {
        all_move[i].weight*=FFMI;
    }

    printf("input the LV\n");
    scanf("%d", &y);
    for (int i = 0; i < 23; i++)
    {
        all_move[i].weight*=LV;
    }
    
    printf("which part you want to check?(chest=1 leg=2 back=3 shoulder=4 arm=5 body=6)\n");
    while(scanf("%d", &check_move)!=EOF)
    {
        if (check_move<=6 && check_move>=1)//chest=1、leg=2、back=3、shoulder=4、arm=5、body=6
        {
            for (int i = 0 + ((check_move-1) * 4); i < 4 + ((check_move-1) * 4); i++)
            {
                printf("%s %d %d %d\n", all_move[i].name,all_move[i].set,all_move[i].weight,all_move[i].number);
            }
            
        }
        printf("which part you want to check?(chest=1 leg=2 back=3 shoulder=4 arm=5 body=6)\n");
    }
    
}