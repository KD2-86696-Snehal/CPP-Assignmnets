#include<iostream>
using namespace std;
class tollbooth{
    unsigned int car;
    double pay;
    int paycar;
    int nopaycar;
    
public:
    tollbooth()
    {
        car=0;
        pay=0;
        paycar=0;
        nopaycar=0;
    }
    void payingCar()
    {
        paycar++;
        this->car=car+1;
        this->pay=pay+0.5;
        cout<<"Car Added with payment"<<endl;
    }
    void nopayCar()
    {
        nopaycar++;
        this->car=car+1;
        cout<<"non paying Car Added"<<endl;


    }
    void printOnConsole()
    {
        cout<<"total no of cars=:"<<car<<endl;
        cout<<"Total amount collected: "<<pay<<endl;
        cout<<"Total paying cars: "<<paycar<<endl;
        cout<<"Total nonpaying cars: "<<nopaycar<<endl;
    }

};
int main()
{
    int choice;
    tollbooth t1;
    do{
        cout<<"-----WELCOME TO TOLLBOOTH-----"<<endl;
        cout<<"1.press 1 for Paying car"<<endl;
        cout<<"2.press 2 for Non paying car"<<endl;
        cout<<"3.press 3 to Display all details"<<endl;
        cout<<"press 0 to EXIT"<<endl;
        cout<<"-------------------------------"<<endl;
        
        cin>>choice;

        switch(choice)
        {
            case 1:
             t1.payingCar();
             break;

            case 2:
            t1.nopayCar();
            break;

            case 3:
            t1.printOnConsole();
            break;

            case 0:
            break;

            default:
            cout<<"Invlid choice"<<endl;
            break;


        }

    }while(choice!=0);
   
    
}