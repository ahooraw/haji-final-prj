// #include <iostream>
// using namespace std;
// #define SIZE 100
// // this creates the class stack.
// class stack {
//  int stck[SIZE];
//  int tos;
// public:
// void init( );
//  int pop( );
//  void push(int i);
//  };
// void stack :: init( )
// {
//  tos = 0 ;
// }
// void stack :: push(int i)
// {
//  if(tos == SIZE) {
//  cout << "stack is full." ;
//  return ;
//  }
// stck[tos] = i ;
// tos ++ ;
// }
// int stack :: pop( )
// {
//  if(tos == 0) {
//  cout << "stack underflow." ;
//  return 0 ; }
//  tos -- ;
//  return stck[tos];
// }
// int main( )
// {
// stack st1, st2; // create two objects
// st1. init( );
// st2.init( );
// st1.push(1);
// st2.push(2);
// st1.push(3);
// st2.push(4);
// cout << st1.pop( ) << endl;
// cout << st1.pop( ) << endl;
// cout << st2. pop( ) << endl;
// cout << st2. pop( ) << endl;
// return 0; }

//-------------------------------------------------------------

// #include<iostream>
// #include<fstream>
// using namespace std;

// int main(){
//     // fstream phone;
//     // phone.open("samsung.txt",ios::out);
//     // phone<<"salam\n"<<"dana"<<"tavana";
//     ofstream phone ("samsung.txt");
//     phone<<"dana";
//     string dana="dana";
//     ifstream phone("samsung.txt");
//     phone >> dana ;
// }

//-----------------------------------------------------------
// #include <iostream>
// #include <ctime>

// using namespace std;

// int main() {
//    // current date/time based on current system
//    time_t now = time(0);

//    cout << "Number of sec since January 1,1970:" << now << endl;

//    tm *ltm = localtime(&now);

//    // print various components of tm structure.
//    cout << "Year" << 1970 + ltm->tm_year<<endl;
//    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
//    cout << "Day: "<<  ltm->tm_mday << endl;
//    cout << "Time: "<< 1 + ltm->tm_hour << ":";
//    cout << 1 + ltm->tm_min << ":";
//    cout << 1 + ltm->tm_sec << endl;
// }

//------------------------------------------------

// class member{
//     private:
//       string user , pass;
//       float mony;
//     public:
//       member(){user="",pass="",mony=0;}
//       member(string i,string j){user=i ; pass=j ; mony=0;};
//       void add_mony(float i){mony+=i;}
//       friend void add_member(member d);
// };

// void add_member(member d){

//     members.open("members.txt",ios::app|ios::in);
//     members<<d.user<<d.pass<<d.mony;
// }
//_____________________________________________________

// #include<iostream>
// #include<string.h>
// #include<fstream>
// #include<string>
// using namespace std;

// fstream members;

// struct member{
//     float mony;
//     string password;
//     string username;
// };

// void add_member(){
//     member user;
//     string user1,user2;

//     members.open("member.txt",ios::in|ios::app);
//     while(1){
//         getline(cin,user1);
//         members>>user.username;
//         getline(members,user2);
//         strcmp(user2,user1);
//         if(1){
//             cout<<"this name allready used\n";
//         }
//         else{

//             user.username = user1;
//             members<<user.username<<" ";
//             cout<<"enter password ";
//             cin>>user.password;
//             members<<user.password<<" ";
//             cout<<"how much mony u want to add to your accuont?";
//             cin>>user.mony;
//             members<<user.mony<<endl;
//             members.close();
//         }
//         break;
//     }
// }
// int main(){
//  char *s1,*y;

//  cin>>s1;
//  cin>>;
//  strcmp(x,y);

// }

//--------------------------------------------------------------------------------------------------
// #include<iostream>
// #include<fstream>
// #include<string>
// #include<conio.h>

// using namespace std;
// int main(){
//     fstream dana;
//     string did;
//      dana.open("dana.txt,", ios::app|ios::in);
//      struct member
//      {
//         string username;
//         string password;
//         float mony;
//      };
//      member m1;

//         getline(cin , m1.username);
//         dana<<m1.username<<" ";

//         getline(cin , m1.password);
//         dana<<m1.password<<" ";
//         cin>> m1.mony;
//         dana<<m1.mony<<endl;
//         dana.close();
//         dana.open("dana.txt",ios::in);
//         dana>>did;
//         cout<<did;
// }
//========================================================================================================
#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
using namespace std;

fstream members;
fstream mahsoolat;

class produc
{
private:
    float price;
    string name;

public:
    produc(string i, float j);
    float get_price() { return price; };
    string get_name() { return name; };
    friend void filenevis(produc d);
    friend void discount(produc d);
    produc();
};

produc::produc()
{

    price = 50;
    name = "dd";
}

produc::produc(string i, float j)
{

    price = j;
    name = i;
}

void filenevis(produc d)
{
    mahsoolat.open("mahsoolat.txt", ios::app | ios::in);
    mahsoolat << d.name << d.price;
}

void discount(produc d)
{
    float num1, num2, pric;
    cin >> num1;
    num2 = (100 - num1);
    pric = (num2 * 100 / d.price);
}

class member
{
private:
    string user, password;
    float mony;

public:
    member(string i, string j, float q)
    {
        user = i;
        password = j;
        mony = q;
    }
    void add_member(member d);
};

void add_member()
{
}

int zaman()
{ // saal v mah ro tabdil be rooz mikone barmigardoone
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int d = (((1900 + ltm->tm_year) * 365) + ((1 + ltm->tm_mon) + 30) + (ltm->tm_mday));
    return d;
}

class User
{
    string username;
    string password;

public:
    User(string u, string p)
    {
        username = u;
        password = p;
    }
    string get_username()
    {
        return username;
    }
    string get_password()
    {
        return password;
    }
    void print_user()
    {
        cout << "- User: " << endl;
        cout << "    Username: " << username << endl;
        cout << "    Password: " << password << endl;
    }
};

int main()
{
}