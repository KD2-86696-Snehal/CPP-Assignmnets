// Q2. Write a menu driven program for Student management.
// Create a class student with data members name, gender, rollNumber(Auto generated) and array to 
// keep marks of three subjects. 
// Accept every thing from user and Print name, rollNumber, gender and percentage.
// In main(), create Student* arr[5] and provide facility for accept, print, search.
// Search function returns index of found Student, otherwise returns -1

#include<iostream>
using namespace std;
class student{
    string name;
    string gender;
    const int roll_no;
    static int gener_rollno;
    double mark[3];

    public:
    student():roll_no(++gener_rollno)
    {
        name="";
        gender="";
        for(int i=0;i<3;i++)
        {
            mark[i]=0;
        }
 
    }
    student(string name, string gender):roll_no(++gener_rollno)
    {
        this->name=name;
        this->gender=gender;
    }
    void acceptstudents()
    {
        cout<<"Enter Student Name: ";
        cin>>name;
        cout<<"Enter gender- ";
        cin>>gender;
        cout<<"Enter Marks of Physics,Chemistry and maths: ";
        for(int i=0; i<3; i++){
            cin>>mark[i];
        }
    }
    void displaystud()
    {
        cout<<"Name of the Student- "<<name<<endl;
        cout<<"Gender of student- "<<gender<<endl;
        cout<<"percentage- ";
        percentage();
    }
    void percentage(){
        double per,sum=0;
        for(int i=0; i<3; i++)
        {
            //cout<<mark[i]<<endl;
            sum+=mark[i];
           // cout<<sum<<endl;
        }
       
        per=(sum/300)*100;
        cout<<per<<endl;
    }
};
int student :: gener_rollno=1;
int main()
{
    student s1;
    s1.acceptstudents();
    s1.displaystud();
    
}