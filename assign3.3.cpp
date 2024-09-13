#include<iostream>
using namespace std;
class address{
    string building;
    string street;
    string city;
    int pin;
    public:
    address()
    {
        building=" ";
        street=" ";
        city=" ";
        pin=0;
    }
    /*address(string building, string street, string city,int pin){
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;

    }*/
//setters and getters method
    void setBuilding(string building)
    {
        this->building=building;
    }
    string getBuilding()
    {
        return building;
    }


    void setStreet(string street)
    {
        this->street=street;
    }
    string getStreet()
    {
        return street;
    }

    void setCity(string city)
    {
        this->city=city;
    }
    string getCity()
    {
        return city;
    }

    void setPin(int pin)
    {
    this->pin=pin;
    }
    int getPin()
    {
        return pin;

    }

    //accept data by user
    void accept(){
        cout<<"Enter Building name: "<<endl;
       getline(cin,building);

        cout<<"Enter street name: "<<endl;
        getline(cin,street);

        cout<<"Enter city name: "<<endl;
        cin>>city;

        cout<<"Enter Pin: "<<endl;
        cin>>pin;

    }
    //display data
    void display()
    {
        cout<<"Address: \""<<building<<"\", "<<street<<", "<<city<<", "<<pin<<endl;
    }
};
int main()
{
    address a1;
    a1.accept();
    a1.display();
    a1.setBuilding("Suparshwa");
    a1.setStreet("RK nagar");
    a1.setCity("Ich");
    a1.setPin(416146);
    a1.display();
}