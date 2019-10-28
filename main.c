#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"header.h"
#include<time.h>

int main()
{
    int box[N][M],i,j,x,y,speed,gy,tail,head,game,frogs,a,b,highscore=0,choice=1,dhuttor,rong;
    char pos,Var,name[20];

    dhuttor=getChoice(choice);
    switch(dhuttor)
    {
    case 1:
    {
        arcade();
        break;
    }
    case 2:
    {
        rong=settings();
        if(rong==1)system("color B");
        else if(rong==2)system("color 4");
        else if(rong==3)system("color 6");
        else if(rong==4)system("color 2");
        main();
        break;
    }
    case 3:
    {
        aboutus();
        break;
    }
    case 4:
    {
        highscores();
        break;
    }
    case 5:
        break;

    }


}

int getChoice(int choice)
{
    char ch=10;
    while(ch!=13)
    {
        system("cls");
        if(choice==1)
        {
            printf("\n   -->\t%s","A R C A D E   M O D E");
        }
        else printf("\n\t%s","Arcade Mode");

        if(choice==2)
        {
            printf("\n   -->\t%s","S E T T I N G S");
        }
        else printf("\n\t%s","Settings");

        if(choice==3)
        {
            printf("\n   -->\t%s","A B O U T   U S");
        }
        else printf("\n\t%s","About Us");

        if(choice==4)
        {
            printf("\n   -->\t%s","H I G H    S C O R E");
        }
        else printf("\n\t%s","High Score");

        if(choice==5)
        {
            printf("\n   -->\t%s","E X I T");
        }
        else printf("\n\t%s","Exit");

        printf("\n\n[ Use UP and DOWN arrow to select an option ]\n\n\n");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
    }

    return choice;
}


