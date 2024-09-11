#include<iostream>
using namespace std;
class date{
    int day;
    int month;
    int year;

public:
    void initDate(){
        day=1;
        month=1;
        year=1990;

    }
    void printDateOnConsole(){
        cout<<"Date : "<<day<<"/"<<month<<"/"<<year<<endl;

    }
    void acceptDateFromConsole(){
        cout<<"Enter date: "<<endl;
        cin>>day>>month>>year;

    }
    bool isLeapYear(){
        if((year%4==0 && year%400==0)||year%100!=0)
        {
            return true;
        }
        else
        {
            return false;
        }

    } 
};
int main()
{
    
    int choice;
    date d1;
    d1.initDate();
    do{
        cout<<"1.Enter date: "<<endl;
        cout<<"2.Display date and check leap year or not: "<<endl;
        //cout<<"3.check date"<<endl;
        cout<<"0.exit"<<endl;
        cout<<"Enter Your choice :"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            d1.acceptDateFromConsole();
            break;

            case 2:
            d1.printDateOnConsole();
            if (d1.isLeapYear())
            {
                
                cout<<"Leap year"<<endl;
            }
            else{
                cout<<"not a Leap year"<<endl;
            }
            break;

            /*case 3:
           
            if (d1.isLeapYear())
            {
                
                cout<<"Leap year"<<endl;
            }
            else{
                cout<<"not a Leap year"<<endl;
            }
            break;*/

            case 0:
            break;

            default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }while(choice!=0);
}
