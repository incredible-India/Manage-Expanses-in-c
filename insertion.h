
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
struct myExpanses* deleteIT(struct myExpanses *);
void SaveDATA(struct myExpanses *);
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
                data = deleteIT(data);
               system("cls");
                ShowMenuOPT();
                showData(data);
                goto w5;



           }else if(ch == '4')
           {
               SaveDATA(data);
           }

           else if(ch == '5')
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

struct myExpanses * deleteIT(struct myExpanses *CRTdata)
{

extern int j;
   struct myExpanses *oldONE = CRTdata;
    struct myExpanses *delete_item = CRTdata->next;
    struct myExpanses *blankSPACE;

    blankSPACE= (struct myExpanses *) malloc(sizeof(struct myExpanses *));
    blankSPACE->title[0] = 'E';
    blankSPACE->title[1] = 'm';
    blankSPACE->ammount =0;
    blankSPACE->next =NULL;

    int choice;
    int index;
    w3:
    gotoxy(40,12);
    setcolor(100);
    printf("Enter The Serial Number You Want to Delete");
      gotoxy(40,14);
    setcolor(101);
    scanf("%d",&choice);
    index = choice;
    if(choice < 0)
    {
        setcolor(2);
         gotoxy(40,16);
        printf("invalid option press any key to enter again..");
        getch();
        system("cls");
        goto w3;

    }else
    {
        if(index == 0)
        {
            free(oldONE);
            return blankSPACE;
        }else
        {
               for(j=0; j<(index-1);j++)
        {
            delete_item = delete_item->next;
            oldONE = oldONE->next;
        }

        oldONE->next = delete_item->next;

        free(delete_item);
        return oldONE;

        }

    }



}

void SaveDATA(struct myExpanses *datas)
{

    FILE *p;

    extern int i;
    i=0;
    p = fopen("SAVEDATA.txt","a");

    fprintf(p,"%s\n",__DATE__);
      while(datas != NULL)
    {
     ++i;

        fprintf(p,"\n%d  \t%s\t",i,datas->title);


        fprintf(p,"%0.2f\n",datas->ammount);

       // datas->ammount +=datas->ammount;
        datas = datas->next;

    }
    fclose(p);
    system("cls");
    gotoxy(40,12);
    printf("File has benn saved..");
    getch();
    ShowMenu();


}
