#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include"header.h"

int arcade()
{
    shapershuru();
    while(game==0)
    {
        print();
        random();
        position();
        tailremove();
        Sleep(speed);
        system("cls");
    }
}

void shapershuru()
{
    system("cls");
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            box[i][j] = 0;
        }
    }
    x=N/2;
    y=M/2;
    speed=99;
    head=5;
    tail=1;
    score=0;
    frogs=0;
    gy=y;
    pstn='d';
    game=0;
    for(i=0,j=0; i<head; i++)
    {
        gy++;
        box[x][gy-head]=i+1;
    }
}

int kisude()
{
    if (_kbhit()) return _getch();
    else return -1;
}

void tailremove()
{
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(box[i][j]==tail)
            {
                box[i][j]=0;
            }
        }
    }
    tail++;
}

void random()
{
    srand(time(h));
    a=1+rand()%17;
    b=1+rand()%37;
    if(frogs==0&&box[a][b]==0)
    {
        box[a][b]=-1;
        frogs=1;
        if(speed>10&&score!=0)speed--;
    }
}

void print()
{
    for(i=0; i<=M+1; i++)
    {
        if(i==0)printf("%c",201);
        else if(i==M+1)printf("%c",187);
        else printf("%c",205);
    }
    printf(" CURRENt SCORE: %d",score);
    printf("\n");
    for(i=0; i<N; i++)
    {
        printf("%c",186);
        for(j=0; j<M; j++)
        {
            if(box[i][j]==0)printf(" ");
            if(box[i][j]>0&&box[i][j]!=head)printf("%c",176);
            if(box[i][j]==head)printf("%c",178);
            if(box[i][j]==-1)printf("%c",15);
            if(j==M-1)printf("%c\n",186);
        }
    }
    for(i=0; i<=M+1; i++)
    {
        if(i==0)printf("%c", 200);
        else if(i==M+1)printf("%c", 188);
        else printf("%c",205);
    }
}

void GameOver()
{
    Sleep(1500);
    system("Cls");
    highscores();
    system("Cls");
    printf("                                 GAME OvER!!! \n\n");
    printf("                                   SCORE: %d \n\n", score);
    printf("                   PRESS ENtER tO PLAy AGAIN OR ESC tO EXIt... \n");

    while(1)
    {
        var=kisude();
        if(var==13)
        {
            game=0;
            shapershuru();
            break;
        }
        else if(var==27)
        {
            game=1;
            break;
        }
    }
    system("Cls");
}

void position()
{
    var=kisude();
    var=tolower(var);
    if(((var=='d'||var=='a')||(var=='w'||var=='s'))&&(abs(pstn-var)>5)) pstn=var;
    if(pstn=='d')
    {
        y++;
        if(box[x][y]!=0&&box[x][y]!=-1)GameOver();
        if(y==M)y=0;
        if(box[x][y]==-1)
        {
            score+=5;
            tail--;
            tail--;
            frogs=0;
        }
        head++;
        box[x][y]=head;
    }

    if(pstn == 'a')
    {
        y--;
        if(y == -1) y = M - 1;
        if(box[x][y]!=0&&box[x][y]!=-1)GameOver();
        if(box[x][y]==-1)
        {
            score=score+5;
            tail--;
            tail--;
            frogs=0;
        }
        head++;
        box[x][y] = head;
    }

    if(pstn == 'w')
    {
        x--;
        if(x == -1) x = N - 1;
        if(box[x][y] != 0 && box[x][y] != -1) GameOver();
        if(box[x][y]==-1)
        {
            score = score + 5;
            tail--;
            tail--;
            frogs = 0;
        }
        head++;
        box[x][y] = head;
    }

    if(pstn == 's')
    {
        x++;
        if(x == N) x = 0;
        if(box[x][y] != 0 && box[x][y] != -1) GameOver();
        if(box[x][y]==-1)
        {
            score = score + 5;
            tail--;
            tail--;
            frogs=0;
        }
        head++;
        box[x][y] = head;
    }

}



