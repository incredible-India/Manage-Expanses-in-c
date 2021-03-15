void gotoxy(int,int);
void setcolor(int);
void exitFN(void);
void AddData(void);
void seeREC(void);
void  DeleteRECORDS(void);
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

    }else if(choice == '2')
    {
        system("cls");
        seeREC();

    }else if(choice == '3')
    {
          system("cls");
        DeleteRECORDS();

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


void  seeREC()
{

    FILE *p;

    p=fopen("SAVEDATA.txt","r");
    char myDATA;
    if(p==NULL)
    {

        gotoxy(40,12);
        printf("FILE HAS BEEN DELETED...");
        getch();
        ShowMenu();
    }else
    {

        while(!feof(p))
        {
            setcolor(2);
                myDATA = fgetc(p);
                printf("%c",myDATA);

        }
        fclose(p);

        getch();
        ShowMenu();

    }
}

void  DeleteRECORDS()
{

    int del;

    del =remove("SAVEDATA.txt");

    if(del == 0)
    {
           gotoxy(40,12);
           setcolor(5);
        printf("FILE DELETED SUCCESSFULLY...");
        getch();
        ShowMenu();
    }else
    {
             gotoxy(40,12);
        printf("FILE HAS ALREADY DELETED ");
        getch();
        ShowMenu();
    }
}
