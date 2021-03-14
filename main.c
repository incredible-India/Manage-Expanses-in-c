/*Himanshu Sharma */
/*Date 15/03/2020*/

#include<stdio.h>
#include<windows.h>

//user Define Header Files
#include"basicFn.h" //(showMenu,gotoxy,setcolor)

//Functions declaration

void ShowMenu(void);

//global variables
struct myExpanses
{
     char title[100];
     float ammount;
     struct myExpanses *next;


};


int i,j;


int main()
{
    void (*__menu)(void);

    __menu = ShowMenu;

    __menu();

    return 0;
}

