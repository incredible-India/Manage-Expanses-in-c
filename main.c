/*Himanshu Sharma */
/*Date 15/03/2020*/

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

//user Define Header Files
#include"basicFn.h" //(showMenu,gotoxy,setcolor)
#include"insertion.h"//(AddData);

//define macro
#define ESC 27
//Functions declaration
void ShowMenu(void);

//global variables


int i,j;


int main()
{
    void (*__menu)(void);

    __menu = ShowMenu;

    __menu();

    return 0;
}

