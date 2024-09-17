// Q1. Create a class Date with data memebrs day,month and year.
// Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of 
// type Date.
// Implement above classes. Test all functionalities in main().

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
    void setDay(){
        this->day=day;
    }
    void setMonth(){
        this->month=month;
    }
    void setYear()
    {
        this->year=year;
    }
    void acceptdate()
    {
        cin>>day>>month>>year;
    }
    void displaydate()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;;
    }
};
class person{
    string name;
    string addr;
    date dob;//composition
    public:
    person(){
        name="";
        addr="";   
    }
    person(string name,string addr,int day, int month,int year): dob(day ,month,year)
    {
        this->name=name;
        this->addr=addr;
        dob.setDay();
        dob.setMonth();
        dob.setYear();
    }
    void acceptper()
    {
        cout<<"-----ENTER DETAILS OF THE PERSON-----"<<endl;
        cout<<"Enter name- ";
        cin>>name;
        cout<<"Enter Address- ";
        cin>>addr;
        cout<<"Enter Date of Birth- ";
        dob.acceptdate();
        cout<<"--------------------------------"<<endl;

    }
    void displayper()
    {
        cout<<"-----DETAILS OF THE PERSON-----"<<endl;
        cout<<"Name of the person- "<<name<<endl;
        cout<<"Address of the persom- "<<addr<<endl;
        cout<<"Birthdate og the person- ";
        dob.displaydate();
        cout<<"--------------------------------"<<endl;

    }

};
int main()
{
    person p1;
    p1.acceptper();
    person p2("shruti","sangli",1,1,2001);
    p2.displayper();
    p1.displayper();
}