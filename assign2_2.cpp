#include<iostream>
using namespace std;
class student{
    int roll_no;
    string sname;
    int marks;

public:
    void initStudent(/*int roll_no=0,string sname=" ",int marks=0*/){
        roll_no=0;
        sname=" ";
        marks=0;
        

    }
    void printStudentOnConsole(){
        cout<<"-----Student Details-----"<<endl;
        cout<<"Roll_no :"<<roll_no<<endl;
        cout<<"Student name : "<<sname<<endl;
        cout<<"Marks Obtained : "<<marks<<endl;
    }
    void acceptStudentFromConsole(){
        cout<<"-----Enter Details-----"<<endl;
        cout<<"Enter roll_no: "<<endl;
        cin>>roll_no;

        cout<<"Enter Student name: "<<endl;
        getline(cin,sname)>>sname;

        cout<<"Enter marks out of 100"<<endl;
        cin>>marks;
        cout<<"-------------------------------"<<endl;

    }
    
};
int main()
{
    
    int choice;
    student s1,s2;
    
    s1.initStudent();
    do{
        cout<<"......................"<<endl;
        cout<<"|-------WELCOME-------|"<<endl;
        cout<<"....................."<<endl;
        cout<<"1.Enter student Details "<<endl;
        cout<<"2.Display Student Details "<<endl;
        //cout<<"3.check date"<<endl;
        cout<<"0.exit"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"Enter Your choice :"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            s1.acceptStudentFromConsole();
            //s2.acceptStudentFromConsole();
            
            break;

            case 2:
            s1.printStudentOnConsole();
            //s2.printStudentOnConsole();


            case 0:
            break;

            default:
            cout<<"Invalid Choice"<<endl;
            cout<<"Enter your choice again: "<<endl;
            break;
        }
    }while(choice!=0);
}
