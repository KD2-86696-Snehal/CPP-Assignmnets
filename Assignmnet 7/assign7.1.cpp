// Q1. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class 
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books. 
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program 
// should be menu driven and should not cause memory leakage.
// Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3

#include<iostream>
using namespace std;
class product{
    int id;
    string title;
    double price;

    public:
    product()
    {
        id=0;
        title="";
        price=0;

    }
    product(int id, string title, int price)
    {
        this->id=id;
        this->title=title;
        this->price=price;
    }
    virtual void accept()
    {
        cout<<"ID- "<<endl;
        cin>>id;
        cout<<"Title- "<<endl;
        cin>>title;
        cout<<"price- "<<endl;
        cin>>price;

    }
    virtual void display()
    {
        cout<<"ID- "<<id<<endl;
        cout<<"Title- "<<title<<endl;
        cout<<"price- "<<price<<endl;
    }
    double getPrice()
    {
        return price;
    }

};
class book: public product{
    string author;
    public:

    book()
    {
        author="";
    }
    book(int id,string title,int price,string author):product(id,title,price)
    {
        this->author=author;
    }
    void accept()
    {
        product::accept();
        cout<<"Enter Author name- ";
        cin>>author;
    }
     void dispaly()
    {
        product::display();
        cout<<"Author name- "<<author<<endl;
        
    }


};
class tape:public product{
    
  string artist;
  public:
  tape()
    {
        artist="";
    }
    tape(int id,string title,int price,string artist):product(id,title,price)
    {
        this->artist=artist;
    }
    void accept()
    {
        product::accept();
        cout<<"Enter Artist name- ";
        cin>>artist;
    }
     void display()
    {
        product::display();
        cout<<"Artist name- "<<artist<<endl;
        
    }
   
};
int menu()
{
    int choice;
    cout << "1. Add BOOK" << endl;
    cout << "2. Add Tape " << endl;
    cout << "3.Display Books" <<endl;
    cout << "4.Display Tapes" <<endl;
    cout << "5.Calculate Discount" <<endl;
    cout << "0. EXIT" << endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
}
    double calculatediscount(product **ptr)
    {
        double total=0;
         for(int i=0; i<3; i++)
            {
                if(typeid (ptr[i])==typeid(book))
                {
                   book *bptr=(book *)ptr[i];
                    double price=ptr[i]->getPrice();
                    total=total+price*0.1;

                }
                else{
                    for(int i=0; i<3; i++)
                    {
                
                
                   tape *tptr=(tape *)ptr[i];
                    double price=ptr[i]->getPrice();
                    total=total+price*0.05;

                    }
                }
            }
           return total; 
    }



int main()
{
    int choice;
    double price=0;
    product *arr[3];
    int index=0;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1:
                if(index<3)
                {
                    arr[index]=new book;
                    arr[index]->accept();
                    index++;
                }
                else{
                    cout<<"Book full"<<endl;
                }
                break;

            case 2:

                 if(index<3)
                {
                    arr[index]=new tape;
                    arr[index]->accept();
                    index++;
                }
                else{
                    cout<<"tape full"<<endl;
                }
                break;
            
            case 3:
            for(int i=0; i<3; i++){
                if(typeid(arr[i])==typeid(book))
                {
                    arr[i]->display();
                }
                
            }
            break;
            case 4:
             for(int i=0; i<3; i++){
                if(typeid(arr[i])==typeid(tape))
                {
                    arr[i]->display();
                }
                
            }

            case 5:
          price= calculatediscount(arr);
          cout<<"Total bill- "<<price;
          break;
          

          case 0:
          break;
          default:
          cout<<"Invalid choice"<<endl;
          break;
 
        }
    }
    
    
}





