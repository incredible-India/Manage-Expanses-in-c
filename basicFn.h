void gotoxy(int,int);
void setcolor(int);
void exitFN(void);
void AddData(void);


void ShowMenu(void)
{
extern int i;

char choice;




SetConsoleTitle("Menu");

    Sleep(10);
    system("cls");
     gotoxy(30,1);
     printf("%s",__DATE__);

    gotoxy(10,2);
    setcolor(6);
    printf("1 : New Entry..");

    gotoxy(10,4);
    setcolor(2);
    printf("2 : See Records");

      gotoxy(10,6);
    setcolor(3);
    printf("3 : Delete Records");

       gotoxy(10,8);
    setcolor(4);
    printf("4 : Exit");

    fflush(stdin);

    readAgain:

   gotoxy(10,10);
    choice =getch();

    if(choice == '1')
    {
         system("cls");
        AddData();

    }else if(choice == '1')
    {

    }else if(choice == '2')
    {

    }else if(choice == '3')
    {

    }else if(choice == '4')
    {
            exitFN();

    }else
    {
        printf("\n");
        goto readAgain;
    }


}


//for changing the co-ordinates
void gotoxy(int a,int b)
{
      COORD x;
      x.X=a;
      x.Y=b;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),x);



}

//for changing the text color
void setcolor(int ForgC)
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void exitFN()
{
    system("cls");
    setcolor(4);
    gotoxy(40,12);
    printf("Thanx For Visiting Us");
    getch();
    exit(0);
}

void ShowMenuOPT()
{
    gotoxy(5,1);
    setcolor(2);
    printf("1 : Add New");

        gotoxy(20,1);
    setcolor(7);
    printf("2 : Menu");

         gotoxy(35,1);
    setcolor(3);
    printf("3 : Delete");

       gotoxy(50,1);
    setcolor(6);
    printf("4 : Save");

    gotoxy(65,1);
    setcolor(9);
    printf("5 : Exit");

}
