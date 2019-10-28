#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"header.h"
#include<time.h>

void highscores()
{
    system("cls");
    int score_1,score_2,score_3,x;
    char name_1[15],name_2[15],name_3[15],name[15],ko[15];

    FILE *fp;
    fp=fopen("highscores.txt","r");

    fscanf(fp,"%s %d",&name_1,&score_1);
    fscanf(fp,"%s %d",&name_2,&score_2);
    fscanf(fp,"%s %d",&name_3,&score_3);
    if(score>score_1)
    {
        printf("                                 Congratulation!!!\n");
        printf("                            You have made a High Score\n\n");
        printf("                            Enter Your Name: ");
        gets(ko);
        x=score;
        strcpy(ko,name);
        score_3=score_2;
        strcpy(name_3,name_2);
        score_2=score_1;
        strcpy(name_2,name_1);
        score_1=x;
        strcpy(name_1,ko);

    }
    else if(score>score_2)
    {
        printf("                                 Congratulation!!!\n");
        printf("                            You have made a 2nd High Score\n\n");
        printf("                            Enter Your Name: ");
        gets(ko);
        x=score;
        strcpy(ko,name);
        score_3=score_2;
        strcpy(name_3,name_2);
        score_2=x;
        strcpy(name_2,ko);
    }

    else if(score>score_3)
    {
        printf("                                 Congratulation!!!\n");
        printf("                            You have made a 3rd High Score\n\n");
        printf("                            Enter Your Name: ");
        gets(ko);
        x=score;
        strcpy(ko,name);
        score_3=x;
        strcpy(name_3,ko);
    }
    fclose(fp);

    fp=fopen("highscores.txt","w");
    fprintf(fp,"%s %d\n%s %d\n%s %d\n",name_1,score_1,name_2,score_2,name_3,score_3);

    fclose(fp);

    printf("%s %d\n",name_1,score_1);
    printf("%s %d\n",name_2,score_2);
    printf("%s %d\n",name_3,score_3);
}
