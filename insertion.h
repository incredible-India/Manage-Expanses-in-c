
struct myExpanses
{
     char title[100];
     float ammount;
     struct myExpanses *next;


};
//declaration
struct myExpanses* __addone(struct myExpanses *);
struct myExpanses* insertNEW(struct myExpanses *);
void showData(struct myExpanses *);
int deleteIT(struct myExpanses *);

//functions
void AddData(void)
{
    struct myExpanses *data;
int retVAL;


    data = (struct myExpanses *) malloc(sizeof(struct myExpanses));


    data = __addone(data);

       ShowMenuOPT();
       showData(data);

       {

           char ch;
                w1:
                    w4:
                        w5:
           readAg:
           ch=getch();

           if(ch == '1')
           {
            system("cls");

            data = insertNEW(data);
            system("cls");
            ShowMenuOPT();
            showData(data);
            goto w1;

           }else if(ch == '2')
           {
               free(data);
                ShowMenu();

           }else if (ch == '3')
           {
               system("cls");
                retVAL = deleteIT(data);
                if(retVAL == 2)
                {
                    goto w4;
                }else
                {  system("cls");
                ShowMenuOPT();
                showData(data);
                goto w5;

                }

           }else if(ch == '5')
           {
               free(data);
               exitFN();
           }else
           {
               printf("\a");
               goto readAg;
           }
       }


}

struct myExpanses * __addone(struct myExpanses *add)
{
     struct myExpanses *newData;

    newData = (struct myExpanses *) malloc(sizeof(struct myExpanses));


    gotoxy(10,4);
    setcolor(2);
    printf("Enter the title\n");
    fflush(stdin);
    gotoxy(10,6);
    gets(newData->title);
      gotoxy(10,8);
    setcolor(3);
    fflush(stdin);
      printf("Enter the Ammount\n");
          gotoxy(10,10);
 scanf("%f",&newData->ammount);


    newData->next =NULL;
system("cls");
    return newData;
}


void showData(struct myExpanses *datas)
{
    extern int i;
    fflush(stdin);

    printf("\n\t\n");
   i=0;
    while(datas != NULL)
    {

   ++i;
        printf("\n%d  \t%s\t",i,datas->title);


        printf("%0.2f\n",datas->ammount);

       // datas->ammount +=datas->ammount;
        datas = datas->next;

    }











}


struct myExpanses* insertNEW(struct myExpanses *data)
{
    struct myExpanses *insert_data;
    struct myExpanses *oldOne;
    oldOne = data;
    insert_data = (struct myExpanses *) malloc(sizeof(struct myExpanses));


      gotoxy(10,4);
    setcolor(2);
    printf("Enter the title\n");
    fflush(stdin);
    gotoxy(10,6);
    gets(insert_data->title);
      gotoxy(10,8);
    setcolor(3);
    fflush(stdin);
      printf("Enter the Ammount\n");
          gotoxy(10,10);
 scanf("%f",&insert_data->ammount);


 while(oldOne->next != NULL)
 {
     oldOne = oldOne->next;
 }
    oldOne->next =insert_data;

    insert_data->next = NULL;

    return data;


}

int deleteIT(struct myExpanses *CRTdata)
{

extern int j;
    struct myExpanses *delete_item = CRTdata->next;
    struct myExpanses *oldONE = CRTdata;
    int choice;
    w3:
    gotoxy(40,12);
    setcolor(100);
    printf("Enter The Serial Number You Want to Delete (type \'501\' to Back)");
      gotoxy(40,14);
    setcolor(101);
    scanf("%d",&choice);
    if(choice < 0)
    {
        setcolor(2);
         gotoxy(40,16);
        printf("invalid option press any key to enter again..");
        getch();
        system("cls");
        goto w3;

    }else if(choice == 501)
    {

        return 2;
    }else
    {
        for(j=0; j<((choice-1)-1);j++)
        {
            delete_item = delete_item->next;
            oldONE = oldONE->next;
        }

        oldONE->next = delete_item->next;

        free(delete_item);
        return 1;
    }



}
