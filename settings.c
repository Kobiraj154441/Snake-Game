#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"header.h"
#include<time.h>
int settings()
{
    system("cls");
    int n,choice=1;
    char ch=10;

    while(ch!=13)
    {
        system("cls");
        printf("\n\n   What color do you want?\t\t\n");
        if(choice==1)
        {
            printf("\n   -->\t%s","B L U E");
        }
        else printf("\n\t%s","Blue");

        if(choice==2)
        {
            printf("\n   -->\t%s","R E D");
        }
        else printf("\n\t%s","Red");

        if(choice==3)
        {
            printf("\n   -->\t%s","Y E L L O W");
        }
        else printf("\n\t%s","Yellow");

        if(choice==4)
        {
            printf("\n   -->\t%s","G R E E N");
        }
        else printf("\n\t%s","Green");

        printf("\n\n[ Use UP and DOWN arrow to select an option ]");
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
