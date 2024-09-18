#include<iostream>
using namespace std;

class Employee{
    protected:
    int id;
    double salary;

    public:
    Employee(){
        
        this->id=0;
        this->salary=0;
    }
    Employee(int id,double salary){
        this->id=id;
        this->salary=salary;
    }
    void setid(int id){
        this->id=id;
    }
    int getid(){
        return id;
    }
    void setSalary(double salary){
        this->salary=salary;
    }
    double getSalary(){
        return salary;
    }
   virtual void accept(){
        cout<<"Enter id";
        cin>>id;
        cout<<"Enter salary : ";
        cin>>salary;
    }
   virtual void display(){
        cout<<"id : "<<id<<endl;
        cout<<" salary : "<<salary<<endl;
    }
};

class Manager:virtual public Employee{
protected:
    double bonus;
public:
    Manager(){
        

        this->bonus;
    }
    Manager(int id,double bonus,double salary){
        this->id=id;
        this->bonus=bonus;
        this->salary=salary;
    }

    void setBonus(){
        this->bonus=bonus;
    }

    double getBonus(){
        return bonus;
    }

    void acceptManager(){
        Employee::accept();
        cout<<"Enter Bonus : ";
        cin>>bonus;
    }

    void displayManager(){
        Employee::display();
        cout<<"Bonus : "<<bonus<<endl;
    }
};

class Salesman: virtual public Employee{
 
 protected:
    double commission;
public:
    Salesman(){
      

        this->commission=0;
    }
    Salesman(int id,double commission,double salary ){
        this->commission=commission;
        this->id=id;
        this->salary=salary;
    }
    void setCommission(double commission){
           this->commission=commission;
    }
    double getCommission(){
          return commission;
    }
    void acceptCommission(){
        Employee::accept();
        cout<<"Enter Commision : ";
        cin>>commission;
    }
    void displaySalesman(){
        Employee::display();
        cout<<"Commission is : "<<commission;
    }

};
class SalesManager:public Manager,public Salesman{
    
public:  
      SalesManager(){
        

        this->id=0;
             this->salary=0;
             this->commission=0;
             this->bonus=0;
      }
      SalesManager(int id, double salary,double commission,double bonus):Employee(id,salary){
             this->id=id;
             this->salary=salary;
             this->commission=commission;
             this->bonus=bonus;
             
      }
      
      void accept(){
        Employee::accept();
          this->acceptManager();
          this->acceptCommission();             
      }

      void display(){
        Employee::display();
        this->displayManager();
        this->displaySalesman();
      }
      
};

// int main(){

//     SalesManager s1(1,90000,10000,45000);
//     s1.display();

//     SalesManager s2(2,88000,6766,9000);
//     s2.display();
    
  

// }
int menu()
{
    int choice = 0;

    cout << "----------WELCOME-----------" << endl;
   
    cout << "1. Add Manager" << endl;
    cout << "2. Add Salesman " << endl;
    cout << "3.accept SalesManager" <<endl;
    cout << "4.display Count of all employees" <<endl;
    cout << "5.display  Manager" <<endl;
    cout << "6. display  Salesman" << endl;
    cout << "7. display Salesmanager " << endl;
     cout << "0. EXIT" << endl;

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
            arr[index]->accept();
            index++;

            break;

            case 2:

            arr[index] = new Salesman;
            arr[index]->accept();
            index++;

            break;

            case 3:
            arr[index] = new SalesManager;
            arr[index]->accept();
            break;

            case 4:
            cout<<"Count of all Employess : "<<index<<endl;
            break;

            case 5:
            cout<<"displaying all Manager"<<endl;
            for(int i = 0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(Manager))
                {
                    arr[i]->display();

                }

                else
                {
                    cout<<"No Manager Found..."<<endl;

                }
            }

            break;

            case 6:
            cout<<"displaying all SalesMan"<<endl;
            for(int i = 0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(Salesman))
                {
                    arr[i]->display();

                }

                else
                {
                    cout<<" Salesman not  Found"<<endl;

                }
            }

            break;

             case 7:
            cout<<"displaying all Salesmanager"<<endl;
            for(int i = 0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(SalesManager))
                {
                    arr[i]->display();

                }

                else
                {
                    cout<<" Salesmanager not  Found"<<endl;

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