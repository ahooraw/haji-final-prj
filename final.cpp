#include<iostream>
#include<fstream>
#include <ctime>
#include<conio.h>
using namespace std;

fstream members;
fstream mahsoolat;

class produc{
    private:
        float price;
        string name;
    public:
        produc(string i , float j);
        float get_price(){return price;};
        string get_name(){return name;};
        friend void filenevis(produc d);
        friend void discount(produc d);
        produc();
};

produc::produc(){
    
    price=50;
    name="dd";
}

produc::produc(string i, float j){
    
    price=j;
    name=i;
}

void filenevis(produc d){
    mahsoolat.open("mahsoolat.txt",ios::app|ios::in);
    mahsoolat<<d.name<<d.price;
}

void discount(produc d){
    float num1,num2,pric;
    cin>>num1;
    num2=(100-num1);
    pric=(num2*100/d.price);
}

struct member{
    float mony;
    string password;
    string username;
};

void add_member(){
    member user;
    string user1;
    
    
    members.open("member.txt",ios::in|ios::app);
    while(1){
        cin>>user1;
        members>>user.username;
        if(user.username==user1){
            cout<<"this name allready used\n";
        }
        else{
            
            user.username = user1;
            members<<user.username<<" ";
            cout<<"enter password ";
            cin>>user.password;
            members<<user.password<<" ";
            cout<<"how much mony u want to add to your accuont?";
            cin>>user.mony;
            members<<user.mony<<endl;
        }
    }
}

int zaman(){//saal v mah ro tabdil be rooz mikone barmigardoone
     time_t now = time(0);
     tm *ltm = localtime(&now);
     int  d = (((1900 + ltm->tm_year)*365)+((1 + ltm->tm_mon)+30)+(ltm->tm_mday));
     return d;
}


int main(){

    

}