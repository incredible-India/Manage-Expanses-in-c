

void ShowMenu(void)
{
printf("hello world !!");


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
