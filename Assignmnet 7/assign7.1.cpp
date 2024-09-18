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
    void acceptproduct()
    {
        cout<<"ID- "<<endl;
        cin>>id;
        cout<<"Title- "<<endl;
        cin>>title;
        cout<<"price- "<<endl;
        cin>>price;

    }
    void displayproduct()
    {
        cout<<"ID- "<<id<<endl;
        cout<<"Title- "<<title<<endl;
        cout<<"price- "<<price<<endl;
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
    void acceptbook()
    {
        product::acceptproduct();
        cout<<"Enter Author name- ";
        cin>>author;
    }
     void displaybook()
    {
        product::displayproduct();
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
    void accepttape()
    {
        product::acceptproduct();
        cout<<"Enter Artist name- ";
        cin>>artist;
    }
     void displayartist()
    {
        product::displayproduct();
        cout<<"Artist name- "<<artist<<endl;
        
    }
   
};
int main()
{
    product *arr[3];
    
}





