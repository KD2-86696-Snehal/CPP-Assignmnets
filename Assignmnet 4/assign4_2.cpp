#include<iostream>
using namespace std;
class stack{
    
    int num;
    public : 
    int size;
    static int top;
    public:
    stack()
    {
         size=5;
    }
    stack(int size)
    {
        this->size=size;
    }
    void acceptsize(){
        cout<<"Enter size of stack";
        cin>>size;
    }

    void display(){
        cout<<num<<endl;
    }
    int isfull()
    {
        if(top==size-1){
           return 1;
        }
       else{
        return 0;
       }
    }
    int isempty()
    {
        if(top==-1)
        {
           return 1;
        }
        else {
        return 0;
        }
    }
        void pop(){
            num=0;
            top--;
        }


    
    void push()
    {
       top++;
        cout<<"Enter element"<<endl;
        cin>>num;
        cout<<"top"<<top<<endl;

    }
    int peek()
    {
        return top;
    }

};
int stack::top=-1;

int main()
{
   int choice;
    stack s1;
    s1.acceptsize();
    stack **sptr=new stack*[s1.size];
    do{
        cout<<"1.Push Elements:"<<endl;
        cout<<"2.pop Element:"<<endl;
        cout<<"3.display Elements"<<endl;
        cout<<"Enter your Choice: "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            if(s1.isfull())
            {
                cout<<"Stack is full"<<endl;
            }
            else{
            for(int i=0; i<s1.size; i++){
            
            
            sptr[s1.top]=new stack;
            sptr[s1.top]->push();
            }
            }
            break;

            case 2:
            cout<<"here if"<<endl;
            if(s1.isempty())
            {
                
                cout<<"Stack is Empty"<<endl;
            }
            else{
            // s1.pop();
            // sptr[top]=new stack;
                s1.peek();
                sptr[s1.top]->pop();
                cout<<"here else"<<endl;
            }
            break;

            case 3:
            //for(int i=0; i<s1.size; i++){
            sptr[0]->display();
            //}
            break;

            case 0:
            break;

            default:
            cout<<"invalid choice"<<endl;
            break;



        }

    }while(choice!=0);
    
    for(int i=0; i<s1.size; i++)
    {
        delete sptr[i];
        sptr[i]=NULL;
    }
    delete[]sptr;
    sptr=NULL;
}

  
       
        
     
    //s}

// for(int i=0; i<s1.size; i++){
//     sptr=
// }



