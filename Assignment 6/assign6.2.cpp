#include<iostream>
using namespace std;
class Employee{
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
    void setId(int id){
        this->id=id;
    }
    int getId(){
        return id;
    }
    void setSalary(double salary){
        this->salary=salary;
    }
    double getSalary(){
        return salary;
    }
    void accept(){
        
        cout<<"Enter id";
        cin>>id;
        cout<<"Enter salary : ";
        cin>>salary;
    }
    void display(){
        cout<<"ID : "<<id<<endl;
        cout<<"salary : "<<salary<<endl;
    }
};

class manager: public virtual Employee
{
double bonus;

public:
manager()
{
bonus=0;
}
manager(int id,double salary,double bonus):Employee(id,salary){
    Employee::setId(id);
    Employee::setSalary(salary);
    this->bonus=bonus;
}
void setBonus(int bonus)
{
    this->bonus=bonus;
}
double getBonus()
{
    return bonus; 
}
protected:
void acceptmanager()
{
    cout<<"Enter Data for Manager"<<endl;
    Employee::accept();
    cout<<"Enter bonus- "<<endl;
    cin>>bonus;
}
void displaymanger()
{
    cout<<"Manager Details"<<endl;
    Employee::display();
    cout<<"Bonus- "<<bonus<<endl;
}

};
class Salesman: public virtual Employee
{
double Commision;

public:
Salesman()
{
Commision=0;
}
Salesman(int id,double salary,double Commision):Employee(id,salary){
    
    Employee::setId(id);
    Employee::setSalary(salary);
    this->Commision=Commision;
}
void setCommision(int Commision)
{
    this->Commision=Commision;
}
double getCommision()
{
    return Commision; 
}
protected:
void acceptsalesman()
{
    cout<<"Enter Data for Salesman"<<endl;
    Employee::accept();
    cout<<"Enter Commision- "<<endl;
    cin>>Commision;
}
void displaysalesman()
{
    cout<<"----Salesman Details-----"<<endl;

    Employee::display();
    cout<<"Commision- "<<Commision<<endl;
}

};

class SalesManager : public manager,public Salesman{
    public:
    SalesManager()
    {

    }
    SalesManager(int id,double salary,double bonus,double commision):Employee(id,salary){
        Employee::setId(id);
        Employee::setSalary(salary);
        manager::setBonus(bonus);
        Salesman::setCommision(commision);

    }
    void acceptsalesManager()
    {
    cout<<"Enter Data for Salesmanger"<<endl;

        Employee::accept();
        manager::acceptmanager();
        Salesman::acceptsalesman();
    }
    void displaysalesManager()
    {
    cout<<"SalesManager Details"<<endl;

        Employee::display();
        manager::displaymanger();
        Salesman::displaysalesman();
    }
};

int main()
{
    SalesManager s1;
    s1.acceptsalesManager();
    s1.displaysalesManager();


}






// #include<iostream>
// using namespace std;

// class Employee{
    
//     int id;
//     double salary;

//     public:
//     Employee(){
        
//         this->id=0;
//         this->salary=0;
//     }
//     Employee(int id,double salary){
//         this->id=id;
//         this->salary=salary;
//     }
//     void setid(int id){
//         this->id=id;
//     }
//     int getid(){
//         return id;
//     }
//     void setSalary(double salary){
//         this->salary=salary;
//     }
//     double getSalary(){
//         return salary;
//     }
//     void accept(){
//         cout<<"Enter id";
//         cin>>id;
//         cout<<"Enter salary : ";
//         cin>>salary;
//     }
//     void display(){
//         cout<<"id : "<<id<<endl;
//         cout<<" salary : "<<salary<<endl;
//     }
// };

// class Manager:virtual public Employee{

//     double bonus;
// public:
//     Manager(){
    
//     }
//     Manager(int id,double bonus,double salary){
//         this->id=id;
//         this->bonus=bonus;
//         this->salary=salary;
//     }

//     void setBonus(){
//         this->bonus=bonus;
//     }

//     double getBonus(){
//         return bonus;
//     }

//     void acceptManager(){
//         accept();
//         cout<<"Enter Bonus : ";
//         cin>>bonus;
//     }

//     void displayManager(){
//         display();
//         cout<<"Bonus : "<<bonus<<endl;
//     }
// };

// class Salesman: virtual public Employee{
 
//  protected:
//     double commission;
// public:
//     Salesman(){
      

//         this->commission=0;
//     }
//     Salesman(int id,double commission,double salary ){
//         this->commission=commission;
//         this->id=id;
//         this->salary=salary;
//     }
//     void setCommission(double commission){
//            this->commission=commission;
//     }
//     double getCommission(){
//           return commission;
//     }
//     void acceptCommission(){
//         accept();
//         cout<<"Enter Commision : ";
//         cin>>commission;
//     }
//     void displaySalesman(){
//         display();
//         cout<<"Commission is : "<<commission;
//     }

// };
// class SalesManager:Manager,Salesman{
    
// public:  
//       SalesManager(){
        

//         this->id=0;
//              this->salary=0;
//              this->commission=0;
//              this->bonus=0;
//       }
//       SalesManager(int id, double salary,double commission,double bonus){
//              this->id=id;
//              this->salary=salary;
//              this->commission=commission;
//              this->bonus=bonus;
             
//       }
      
//       void accept(){
//           acceptManager();
//           acceptCommission();             
//       }

//       void display(){
//         displayManager();
//         displaySalesman();
//       }
      
// };

// int main(){

//     SalesManager s1(1,90000,10000,45000);
//     s1.display();

//     SalesManager s2(2,88000,6766,9000);
//     s2.display();
    
  

// }