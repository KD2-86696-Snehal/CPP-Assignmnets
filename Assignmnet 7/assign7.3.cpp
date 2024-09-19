// Q3. Write a class to store Account information of Bank customer by using following class diagram. 
// Use enum to store information of account type. 
// Create an array of 5 Accounts in main() and accept their details from user.
// Write Menu driven program to deposit/withdraw amount from the account.
// After each transaction display updated account balance. 
// Throw exceptions for invalid values. 
// Also implement an exception class InsufficientFundsException.
// In withdraw if sufficient balance is not available in account or while deposit the entered amount is 
// negative then throw this exception


#include<iostream>
using namespace std;

class InsufficientFundsException{
    string message;
    double currentbal;
    double withdrawamt;
    public:
    InsufficientFundsException(string message){
        this->message=message;
    }
    InsufficientFundsException(double currentbal,double withdrawamt)
    {
        this->currentbal=currentbal;
        this->withdrawamt=withdrawamt;
    }
    void display()
    {
        cout<<message<<endl;
        cout<<"Current Balance="<<endl;
        cout<<"Withdrawal amount"<<endl;
    }

};
 enum EAccountType
    {
        Savings=1,
        Current,
        Dmat
    };
class bank{
    const int accno;
    EAccountType type;
    double bal;
    static int generate_accno;

    public:
    bank():accno(++generate_accno)
    {
       
        bal=0;
    }
    bank(EAccountType type,double bal):accno(++generate_accno)
    {
        //this->name=name;
        this->type=type;
        this->bal=bal;
    }
     void acceptdet()
    {
        // cout<<"Enter name:"<<endl;
        // cin>>name;
        int choice;
        cout<<"-----Enter Account Details-----"<<endl;
        cout<<"1. Savings"<<endl;
        cout<<"2. Current"<<endl;
        cout<<"3. Dmat"<<endl;
        cout<<"Enter the choice of account"<<endl;
        
        cin>>choice;
        type=EAccountType(choice);
        cout<<"Intial Balance: "<<endl;
        cin>>bal;
        cout<<"Account created"<<endl;
    }

    void deposite(){
       double amt;
        cout<<"Enter amount to deposite: "<<endl;
        cin>>amt;
        if (amt<0)
        {
            throw InsufficientFundsException("Amount cannot be negative");
        }
        else{
        bal=bal+amt;
        cout<<"Amount deposited succefully"<<endl;
        }
    }
    void withdraw(){
        double amt;
        cout<<"Enter amount of withdraw: "<<endl;
        cin>>amt;
        if(amt>bal)
        {
       throw InsufficientFundsException("Withdrawal amount is greater than current blanace");
        }
        else{
             bal=bal-amt;
        cout<<"Withdrawal Successfull"<<endl;;
        }
    }
    void displaydtls()
    {
        cout<<"------ACCOUNT DETAILS------" <<endl;
        cout<<"Account no : "<<accno<<endl;
       // cout<<"name : "<<name<<endl;
       switch(type)
       {
        case Savings:
            cout<<"Account Type = Savings"<<endl;
             break;
        case Current:
            cout<<"Account Type = Current"<<endl;
             break;
        case Dmat:
            cout<<"Account Type = Dmat"<<endl;
            break;
        }

        cout<<"balance : "<<bal<<endl;
        cout<<"--------------------------------"<<endl;
    }
    // void setName(string name){
    //     this->name=name;
    // }
    // string getName(){
    //     return name;
    // }

    void setBalance(int bal)
    {
        this->bal=bal;
    }
    double getBalance()
    {
        return bal;
    }
    int getAccno()
    {
        return accno;
    }


};
int bank::generate_accno=1000;

int menu()
{
    int choice;
    cout<<"----WELCOME TO OUR BANK------"<<endl;
    cout<<"1.Add Bank Details"<<endl;
    cout<<"2.Depostite balance"<<endl;
    cout<<"3.Withdraw amount"<<endl;
    cout<<"4.Display Account Details"<<endl;
    cout<<"5.Display All Account Details"<<endl;
    cout<<"Enter Your choice:"<<endl;
    cin>>choice;
    cout<<"-----------------------------"<<endl;
    return choice;
}
    int findaccount(bank **ptr)
    {
        int accno1;
        cout<<"Enter accno to find: ";
        cin>>accno1;
        for(int i=0; i<5; i++)
        {
            if(accno1==ptr[i]->getAccno())
            {
                return i;
            }
        }
        return -1;
    }


int main()
{
    try{
    // bank b1;
    // b1.acceptdet();
    // b1.displaydtls();
    // b1.deposite();
    // b1.displaydtls();
    // b1.withdraw();
    // b1.displaydtls();

    bank *arr[5];
    int index=0;
    int j=0;
    int choice;
    while((choice=menu())!=0){
//cout<<"here";
        switch (choice)
        
        {
        case 1:
            /* code */
            if(index<5)
            {
                //cout<<"here";
                arr[index]=new bank;
                arr[index]->acceptdet();
                index++;
            }
            else{
                cout<<"Account limit exceeds"<<endl;
            }
            break;

            case 2:
            j=findaccount(arr);
            if(j!=-1){
            arr[j]->deposite();
            }
            else{
                cout<<"Account not Found..."<<endl;
            }
            break;

            case 3:
            j=findaccount(arr);
            if(j!=-1){
            arr[j]->withdraw();
            }
             else{
                cout<<"Account not Found..."<<endl;
            }
            break;

            case 4:
             j=findaccount(arr);
             if(j!=-1){
            arr[j]->displaydtls();
             }
              else{
                cout<<"Account not Found..."<<endl;
            }
            break;

            case 5:
            for(int i=0; i<index; i++)
            {
                arr[i]->displaydtls();
            }
            break;

            case 0:
            break;
        
        default:
        cout<<"Invalid Choice"<<endl;
            break;
        }
    }


    
    }
    catch(InsufficientFundsException e)
    {
        e.display();
    }
}