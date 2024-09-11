#include<stdio.h>

struct date{
    int day;
    int month;
    int year;

};
void initDate(struct date* ptrDate)
{
    
    ptrDate->day=1;
    ptrDate->month=1;
    ptrDate->year=2000;

    //printf("DATE: %d/%d/%d",ptrDate->day,ptrDate->month,ptrDate->year);
}
void printDATEONConsole(struct date* ptrDate)
{
    printf("date : %d/%d/%d",ptrDate->day,ptrDate->month,ptrDate->year);
}
void acceptDatefromConsole(struct date* ptrDate)
{
    printf("\nEnter date :");
    scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
}
int main()
{
    struct date d1;
    initDate(&d1);
    int choice;
    do {
            printf("\n-----------------\n-----Welcome-----\n-----------------");
          
            printf("\n1.Enter date: \n");

            printf("2.dispaly date: \n");

            printf("0.exit");
            printf("\nEnter Your choice: \n");
            scanf("%d",&choice);

        switch(choice){
                case 1:
                    acceptDatefromConsole(&d1);
                    break;
                case 2:
                    printDATEONConsole(&d1);
                    break;
                case 0:
                break;
                
                default :
                printf("Invalid choice");
                break;

        
    }
    }while(choice!=0);
}


