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











// #include<iostream>
// #include<typeinfo>

// using namespace std;

// class Product
// {
//     int id;
//     string title;
//     double price;

//     public:
//     Product()
//     {
//         id = 0;
//         title = " ";
//         price = 0;
//     }

//     Product(int id,string title,double price)
//     {
//         this->id = id;
//         this->title = title;
//         this-> price = price;
//     }

//     virtual void Accept()
//     {
//         cout<<"Enter the Id:"<<endl;
//         cin>>id;

//         cout<<"Enter the title:"<<endl;
//         cin>>title;

//         cout<<"Enter the price :"<<endl;
//         cin>>price;

//     }


//     virtual void Display()
//     {
//         cout<<"Product ID :"<<id<<endl;
//         cout<<"Name of the Product:"<<title<<endl;
//         cout<<"Price :"<<price<<endl;

    
//     }

//     double getDiscountPrice()
//     {
//         return price ;

//     }
   
// };

// class Book : public Product
// {
//     string author;
//     string bookName;

//     public:
    
//     Book()
//     {
//         author = "";
//     }

//     Book(string bookName,string author,int id,string title,double price ):Product(id,title,price)
//     {
//         this->bookName = bookName;
//         this->author = author;
//     }

//     void Accept()
//     {
//         cout<<"-----Enter the Book Product Details----- "<<endl;

//         cout<<"Enter the Book Name :"<<endl;
//         cin>>bookName;

//         cout<<"Enter the Author of Book"<<endl;
//         cin>>author;

//         Product::Accept();     

//     }

//     void Display()
//     {
//         cout<<"Book Name :"<<bookName<<endl;
        
//         cout<<"Author of Book:"<<author<<endl;

//         Product :: Display();

//     }

// };

// class Tape : public Product
// {
//     string artist;
//     string TapeName;

//     public:
//     Tape()
//     {
//         TapeName= "";
//         artist = "";

//     }

//     Tape(string artist,int id,string title,double price ): Product(id,title,price)
//     {
//         this->artist = artist;

//     }

//     void Accept()
//     {
//         cout<<"-----Enter the Tape Product Details-----"<<endl;

//         cout<<"Tape Artist name :"<<endl;
//         cin>>artist;

//         Product::Accept();

//     }

//     void Display()
//     {
//         cout<<TapeName<<endl;

//         cout<<"Aritst :"<<artist<<endl;

//         Product::Display();

//     }
// };

// int menu()
// {
//     int choice = 0;
    
   
//     cout << "1. Add BOOK" << endl;
//     cout << "2. Add Product " << endl;
//     cout << "3.Display Books" <<endl;
//     cout << "4.Display Tapes" <<endl;
//     cout << "5.Calculate Discount" <<endl;
//      cout << "0. EXIT" << endl;
//     cout<<"Enter Your choice"<<endl;
//     cin >> choice;
//     cout << "----------------------" << endl;

//     return choice;
// }

// double calculateDiscount(Product **ptr)
// {
//     double total = 0.0;

//     for(int i = 0;i<3;i++)
//     {
//         if(typeid(*ptr[i])==typeid(Book))
//         {
//             Book * bptr = (Book* )ptr[i];
//             double price = bptr->getDiscountPrice();
//             total = total + price * 0.1;
//         }

//         else
//         {
//             if(typeid(*ptr[i])==typeid(Tape))
//         {
//             Tape * tptr = (Tape* )ptr[i];
//             double price = tptr->getDiscountPrice();
//             total = total + price * 0.05;
//         }
            
//         }
//     }

//     return total;
// }

// int main()
// {
//     int choice = 0;
//     double price  = 0;

//     Product *arr[3];

//     int index = 0;

//     while((choice = menu())!=0)
//     {
//         switch (choice)
//         {

//         case 1:
//         if(index<3)
//         {
//             arr[index] = new Book;
//             arr[index] ->Accept();
//             index++;
//         }

//         else
//         {
//             cout<<"Books are Full"<<endl;
//         }
        
//         break;


//         case 2:
//         if(index<3)
//         {
//             arr[index] = new Tape;
//             arr[index]->Accept();
//             index++;
//         }

//         else
//         {
//             cout<<"Tape are Full"<<endl;

//         }

//         break;

//         case 3:
//         for(int i = 0;i<3;i++)
//         {
//             if(typeid(*arr[i])==typeid(Book))
//             {
//                 arr[i]->Display();

//             }
//         }
//         break;

//         case 4:
//         for(int i = 0;i<3;i++)
//         {
//             if(typeid(*arr[i])==typeid(Tape))
//             {
//                 arr[i]->Display();

//             }
//         }
//         break;

//         case 5:
//         price = calculateDiscount(arr);
//         cout<<"The Product Discount is :"<<price<<endl;
//         break;

        
//         default:
//         cout<<"Wrong Choice"<<endl;
//         break;

//         }
//     }    

//     return 0;
// }
