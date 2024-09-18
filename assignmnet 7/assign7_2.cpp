#include<iostream>
#include<typeinfo>

using namespace std;

class Employee
{
    int id;
    double salary;

    public:

    Employee()
    {
        id = 0;
        salary = 0;
    }

    Employee(int id,double salary)
    {
        this->id = id;
        this->salary = salary;

    }

    virtual void Accept()
    {
        cout<<"Enter the Id:"<<endl;
        cin>>id;
        cout<<"Enter the salary :"<<endl;
        cin>>salary;

    }
    virtual void Display()
    {
        cout<<"ID : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }

};

class Manager : virtual public Employee
{
    double bonus;

    protected:
    void AcceptManager()
    {
        cout<<"Enter the Bonus :"<<endl;
        cin>>bonus;
    }

    void DisplayManager()
    {
        cout<<"Bonus :"<<bonus<<endl;
    }

    public:

    Manager()
    {
        bonus = 0;
    }

    Manager(int id,double bonus,double salary):Employee(id,salary)
    {
        this->bonus = bonus;
    }

    void Accept()
    {
        Employee::Accept();
        AcceptManager();
        

    }

    void Display()
    {
        Employee::Display();
        DisplayManager();
        
    }


};


class Salesman : virtual public Employee
{
    double commission ;

    protected:

    void AcceptSalesMan()
    {
        cout<<"Enter the Commission"<<endl;
        cin>>commission;
    }

    void DisplaySalesMan()
    {
            cout<<"Commission of Salesman :"<<commission<<endl;
    }

    public:
    Salesman() : commission(0){}

    Salesman (int id,double commission,double salary) : Employee(id,salary)
    {
        this->commission = commission;
    }


    void Accept()
    {
        Employee :: Accept();
        AcceptSalesMan();
        
    }

    void Display()
    {
        Employee::Display();
        DisplaySalesMan();


    }


};

class SalesManager :public Manager ,public Salesman
{
    public:

    SalesManager(){}

    SalesManager(int id,double sal,double commission):Employee(id,sal)
    {

    }

    void Accept()
    {
        Employee::Accept();
        Manager::AcceptManager();
        SalesManager::AcceptSalesMan();



    }

    void Display()
    {
        Employee::Display();
        this->DisplayManager();
        this->DisplaySalesMan();
    }

};

int menu()
{
    int choice = 0;

    cout << "---------------------------------" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Add Manager" << endl;
    cout << "2. Add Salesman " << endl;
    cout << "3.Accept SalesManager" <<endl;
    cout << "4.Display Count of all employees" <<endl;
    cout << "5.Display All Manager" <<endl;
    cout << "6. Display All Salesman" << endl;
    cout << "7. Display Salesmanager " << endl;

    cin >> choice;
    cout << "----------------------------------" << endl;

    return choice;
}



int main()
{
   int choice = 0;

    Employee *arr[3];
    int index = 0;

    while((choice = menu())!=0)
    {
        switch (choice)
        {
            case 1:
            arr[index] = new Manager;
            arr[index]->Accept();
            index++;

            break;

            case 2:

            arr[index] = new Salesman;
            arr[index]->Accept();
            index++;

            break;

            case 3:
            arr[index] = new SalesManager;
            arr[index]->Accept();
            break;

            case 4:
            cout<<"Count of all Employess : "<<index<<endl;
            break;

            case 5:
            cout<<"Displaying all Manager"<<endl;
            for(int i = 0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(Manager))
                {
                    arr[i]->Display();

                }

                else
                {
                    cout<<"No Manager Found..."<<endl;

                }
            }

            break;

            case 6:
            cout<<"Displaying all SalesMan"<<endl;
            for(int i = 0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(Salesman))
                {
                    arr[i]->Display();

                }

                else
                {
                    cout<<"No Salesman Found..."<<endl;

                }
            }

            break;

             case 7:
            cout<<"Displaying all Salesmanager"<<endl;
            for(int i = 0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(SalesManager))
                {
                    arr[i]->Display();

                }

                else
                {
                    cout<<"No SalesManager Found..."<<endl;
                }
            }

            break;


            default:
            cout<<"Invalid choice"<<endl;
            break;

            
        }
    }


    return 0;


}