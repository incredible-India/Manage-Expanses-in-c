
struct myExpanses
{
     char title[100];
     float ammount;
     struct myExpanses *next;


};
//declaration
struct myExpanses * __addone(struct myExpanses *);

//functions
void AddData(void)
{
    struct myExpanses *data;

    data = (struct myExpanses *) malloc(sizeof(struct myExpanses));

    data = __addone(data);

}

struct myExpanses * __addone(struct myExpanses *add)
{
     struct myExpanses *newData;

    newData = (struct myExpanses *) malloc(sizeof(struct myExpanses));

    printf("Enter the title\n");
    fflush(stdin);
    gets(newData->title);
      printf("Enter the Ammount\n");
 scanf("%f",newData->ammount);


    newData->next =NULL;
}
