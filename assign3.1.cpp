#include<iostream>
using namespace std;
class box{
    int length;
    int width;
    int height;
    int volume;

    public:
    box(){
        length=1;
        width=1;
        height=1;
    }
    box(int value)
    {
        this->length=value;
        this->width=value;
        this->height=value;

    }
    box(int length,int width,int height)
    {
        this->length=length;
        this->width=width;
        this->height=height;

    }
    void calvolume
    ()
    {
        volume=length*width*height;
    }
    void display()
    {
        cout<<"volume of Box: "<<volume<<endl;
    }
};
int main()
{
    int choice;
    box b1;
    box b2(5);
    box b3(4,5,6);
    
   
    do{
        cout<<"1.calculte volume  of box with default value"<<endl;
        cout<<"2.calulate volume of box by passing lenght,width,and hight"<<endl;
        cout<<"3.Calculate volume of box by passing lenght widht and hight as same"<<endl;
        //cout<<"4.display volume of box:"<<endl;
        cout<<"0.exit"<<endl;
        cout<<"Enter YOur choice: "<<endl;
        cin>>choice;


        switch(choice)
        {
            case 1:
             
            b1.calvolume
            ();
            b1.display();
            break;

            case 2:
           
            b2.calvolume
            ();
            b2.display();
            break;

            case 3:
            b3.calvolume
            ();
            b3.display();

            case 0:
            break;

            default :
            cout<<"Invalid choice"<<endl;
            break;
        }
    }while(choice!=0);
}

    /*box b1;
    b1.calvolume
    ();
    b1.display();
    box b2(5);
    b2.calvolume
    ();
    b2.display();
    box b3(4,5,6);
    b3.calvolume
    ();
    b3.display();*/

