#include<iostream>
using namespace std;
class time{
    int h;
    int m;
    int s;
    public:
    time(){
        h=1;
        m=1;
        s=1;
    }
    time(int h,int m, int s)
    {
        this->h=h;
        this->m=m;
        this->s=s;
    }
    void setHour(int h){
        this->h=h;

    }
    void setMinutes(int m){
        this->m=m;
    }
    void setSeconds(int s){
        this->s=s;
    }
    int getHour()
    {
        return h;
    }
    int getMinutes()
    {
        return m;
    }
    int getSeconds(){
        return s;
    }
    void accept()
    {
        cout<<"Enter hour: "<<endl;
        cin>>h;
        cout<<"Enter minutes: "<<endl;
        cin>>m;
        cout<<"Enter seconds: "<<endl;
        cin>>s;
    }
    void display()
    {
        cout<<"-------------------"<<endl;
        cout<<h<<"Hr : "<<m<<"min : "<<s<<"sec"<<endl;
        cout<<"--------------------"<<endl;
    }
};
int main()
{
    time **tptr=new time*[5];
    for(int i=0; i<6;i++)
    {

    tptr[i]=new time;
        tptr[i]->accept();
    }
        // tptr[1]->accept();
        // tptr[2]->accept();
        // tptr[3]->accept();

        // tptr[4]->accept();
        
for(int i=0; i<5; i++)
{
         tptr[i]->display();
}
        // tptr[1]->display();
        // tptr[2]->display();
        // tptr[3]->display();
        // tptr[4]->display();

    time t1;
    t1.setHour(3);
    t1.setMinutes(23);
    t1.setSeconds(30);

    t1.getHour();
    t1.getMinutes();
    t1.getSeconds();
    t1.display();

for(int i=0; i<5; i++)
{
    delete tptr[i];
    tptr[i]=NULL;
}
delete[]tptr;
tptr=NULL;

}
