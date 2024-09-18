// Q1. Create a class Date with data memebrs day,month and year.
// Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of 
// type Date.
// Cretae a class Employee with data members id, sal, dept and joining date. The joining date should 
// be of type date.
// Employee class should be inherited from Person.
// Implement following classes. Test all functionalities in main().
// (Note - Perform the Association and Inheritance in the above case.)

#include<iostream>
using namespace std;
class date{
    int day;
    int month;
    int year;
    public:
    date()
    {
        day=0;
        month=0;
        year=0;
    }
    date(int day, int month, int year)
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    void acceptdate()
    {
       cin>>day>>month>>year;
    }
    void dispalydate()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }

};
//persong has a date of birth

class person{
    string name;
    string addr;
    date dob;

    public:
    person()
    {
        name="";
        addr="";
    }
    person(string name,string addr,int day,int month,int year):dob(day,month,year)
    {
        this->name=name;
        this->addr=addr;
        
    }
    virtual void acceptper()
    {
        cout<<"Enter person name: ";
        cin>>name;
        cout<<"Enter address: ";
        cin>>addr;
        cout<<"Enter Date of Birth: ";
        dob.acceptdate();
    }
    virtual void displayper()
    {
        cout<<"Person name- "<<name<<endl;
        cout<<"Address- "<<addr<<endl;
        cout<<"Date of Birth- ";
        dob.dispalydate();
    }
};
//Employee has a date of joining
//Employee is a person
class Employee: public person{
    int empid;
    int sal;
    string dept;
    date doj;
    public:
    Employee()
    {
        empid=0;
        sal=0;
        dept="";

    }
    Employee(int empid,int sal,string dept,int day,int month,int year):doj(day,month,year)
    {
        this->empid=empid;
        this->sal=sal;
        this->dept=dept;

    }
    void acceptemp()
    {
        cout<<"------ENTER DETAILS-----"<<endl;
        person::acceptper();
        cout<<"Enter empid: ";
        cin>>empid;
        cout<<"Enter sal- ";
        cin>>sal;
        cout<<"Enter Department: ";
        cin>>dept;
        cout<<"Enter Joining date: ";
        doj.acceptdate();
        cout<<"--------------------------"<<endl;

    }
    void displayemp()
    {
        cout<<"-----EMPLOYEE DETAILS-----"<<endl;
        person::displayper();
        cout<<"Empid: "<<empid<<endl;
        cout<<"sal: "<<sal<<endl;
        cout<<"department: "<<dept<<endl;
        cout<<"Date of Joining: ";
        doj.dispalydate();
        cout<<"--------------------------"<<endl;
    }
};
int main()
{

    // person *ptr=new Employee;

    // Employee *eptr=(Employee *)ptr;
    // eptr->acceptemp();
    // eptr->displayemp();

    person *ptr=NULL;
    int choice;
    
    do{
        cout<<"1.Add Employee details"<<endl;
        cout<<"2.Display Employee Details"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter Your choice"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                 ptr=new Employee;
                //eptr->acceptemp();
                break;

            case 2:
                //eptr->displayemp();
                break;

            case 3:
                break;

            default:
                cout<<"Invalid Choice"<<endl;
                break;
        }

        if(ptr!=NULL)
         {
            Employee *eptr=(Employee *)ptr;
            eptr->acceptemp();
            eptr->displayemp();
         }
    }while(choice!=3);

    


}