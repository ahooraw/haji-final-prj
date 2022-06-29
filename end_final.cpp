#include <bits/stdc++.h>

using namespace std;

// classes
class User
{
    string username;
    string password;
    float wallet;

public:
    User(string u = "null", string p = "null")
    {
        username = u;
        password = p;
        wallet = 0;
    }

    string get_username()
    {
        return username;
    }

    string get_password()
    {
        return password;
    }

    int get_wallet()
    {
        return wallet;
    }

    float increase_wallet(float amount)
    {
        wallet += amount;
    }

    void print_user()
    {
        cout << "- User: " << endl;
        cout << "    Username: " << username << endl;
        cout << "    Password: " << password << endl;
        cout << "    Wallet: " << wallet << endl;
    }
};

class Product
{
    string name;
    float price;

public:
    Product(string n = "null", float p = 0.0)
    {
        name = n;
        price = p;
    }

    string get_name()
    {
        return name;
    }

    float get_price()
    {
        return price;
    }

    void print_product()
    {
        cout << "- Product: " << endl;
        cout << "      Name: \t" << name << endl;
        cout << "      Price: \t" << price << endl;
    }
};

class Factor
{
    float price;
    Product boughts[100]; // max is 100 product
    int boughts_count;
    // todo: date here
    bool is_pay;

public:
    Factor(float p)
    {
        price = p;
        boughts_count = 0;
        is_pay = false;
    }
    float get_price()
    {
        return price;
    }

    Product *get_boughts()
    {
        return boughts;
    }

    int get_boughts_count()
    {
        return boughts_count;
    }

    // todo: get date function

    bool get_is_pay()
    {
        return is_pay;
    }

    void print_Factor()
    {
        cout << "- Factor: " << endl;
        // todo: printing date
        cout << "     price: " << price << endl;
        cout << "     boughts product: " << endl;
        for (size_t i = 0; i < boughts_count; i++)
        {
            cout << "id: " << i << endl;
            boughts[i].print_product();
        }
    }
};

// prototypes
void seperator();
void show_menu();
void exit_fun();
void show_all_products();
User is_valid(string, string);
void person_login();
void show_all_users();
void new_user();
void add_to_users(User);
bool is_available_user(string, string);
void increasing_wallet();
bool is_admin(User);
void after_login_loop_user();
void after_login_loop_admin();
void add_to_products(Product);
void remove_product();
void new_product();

// global variables
const int max_products_count = 100000;
Product products[max_products_count];
int product_count = 0;

string admin_username = "Admin";
string admin_password = "Admin@123456";

// all users except admin
const int max_users_count = 1000;
User users[max_users_count];
int user_count = 0;

User current_user("null", "null");
User admin(admin_username, admin_password);

int main(int argc, char const *argv[])
{

    // Program loop
    while (1)
    {
        seperator();
        show_menu();
        int x;
        cin >> x;
        if (x == 1)
        {
            show_all_products();
        }
        else if (x == 2)
        {
            person_login(); // current user set here
            if (is_admin(current_user))
            {
                after_login_loop_admin();
            }
            else
            {
                after_login_loop_user();
            }
        }
        else if (x == 3)
        {
            new_user();
        }
        else if (x == 4)
        {
            exit_fun();
        }
        else if (x == 5)
        {
            show_all_users();
        }

        else
        {
            cout << "WTF" << endl;
        }
    }
    return 0;
}

void add_to_users(User user)
{
    users[user_count] = user;
    user_count++;
}

void add_to_products(Product product)
{
    products[product_count] = product;
    product_count++;
}

void seperator()
{
    cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void show_menu()
{
    cout << "Best Online Shop" << endl;
    cout << "1. show all products" << endl;
    cout << "2. login (entering availble user)" << endl;
    cout << "3. singup (new user)" << endl;
    cout << "4. exit" << endl;
    cout << "5. show all users" << endl;
    cout << endl;
    cout << "choose by number: ";
}

void exit_fun()
{
    cout << "Good bye" << endl;
    exit(0);
}

void show_all_products()
{
    seperator();
    cout << "All Products: " << endl;
    for (size_t i = 0; i < product_count; i++)
    {
        cout << "id: " << i << endl;
        products[i].print_product();
    }
}

User is_valid(string username, string password)
{
    User not_found_user(" ", " ");
    // check is admin?
    if (username == admin_username and password == admin_password)
    {
        return admin;
    }
    else // this is not admin
    {
        for (size_t i = 0; i < user_count; i++)
        {
            if (username == users[i].get_username() and password == users[i].get_password())
            {
                return users[i];
            }
        }
    }

    return not_found_user;
}

bool is_available_user(string username, string password)
{
    // check is admin?
    if (username == admin_username)
    {
        return true;
    }
    else // this is not admin
    {
        for (size_t i = 0; i < user_count; i++)
        {
            if (username == users[i].get_username())
            {
                return true;
            }
        }
    }

    return false;
}

void person_login()
{
    cout << endl
         << endl;
    cout << "Log In: " << endl;

    cout << "username: ";
    string username;
    getline(cin, username);
    getline(cin, username);

    cout << "password: ";
    string password;
    getline(cin, password);

    User user = is_valid(username, password);
    if (user.get_username() != " ")
    {
        current_user = user;
        cout << "You entered successfully!" << endl;
    }
    else
    {
        cout << "Not found Bro!" << endl;
    }
}

void show_all_users()
{
    seperator();
    cout << "all users: " << endl;
    for (size_t i = 0; i < user_count; i++)
    {
        users[i].print_user();
    }
}

void new_user()
{
    cout << endl
         << endl;
    cout << "Sign Up: " << endl;

    cout << "username: ";
    string username;
    getline(cin, username);
    getline(cin, username);

    cout << "password: ";
    string password;
    getline(cin, password);

    bool is_exist = is_available_user(username, password);
    if (is_exist)
    {
        cout << "sorry! This user name is already in used" << endl;
    }
    else
    {
        User new_user(username, password);
        add_to_users(new_user);
    }
}

bool is_admin(User user)
{
    return user.get_username() == admin_username;
}

void new_product()
{
    cout << endl
         << endl;
    cout << "New Product: " << endl;

    cout << "name: ";
    string name;
    getline(cin, name);
    getline(cin, name);

    cout << "price: ";
    float price;
    cin >> price;

    Product product(name, price);
    add_to_products(product);
}

void remove_product()
{
    cout << endl
         << endl;
    cout << "Remove Product: " << endl;

    cout << "id: ";
    int id;
    cin >> id;

    for (size_t i = id; i < product_count - 1; i++)
    {
        products[i] = products[i + 1];
    }

    // we don't remove the product data and just wait to adding in this index in 'products' array
    product_count -= 1;
    cout << "product remove successfully!";
}

void after_login_menu_admin()
{
    seperator();
    current_user.print_user();
    cout << "1. new product" << endl;
    cout << "2. remove product" << endl;
    cout << "3. add discount" << endl;
    cout << "4. show all products" << endl;
    cout << "5. log out" << endl;
    cout << "choose by number: ";
}

void after_login_loop_admin()
{
    while (true)
    {
        after_login_menu_admin();
        int x;
        cin >> x;

        if (x == 1)
        {
            new_product();
        }
        else if (x == 2)
        {
            remove_product();
        }
        else if (x == 3)
        {
        }
        else if (x == 4)
        {
            show_all_products();
        }
        else if (x == 5)
        {
            break;
        }
        else
        {
            cout << "WTF" << endl;
        }
    }
}

void after_login_menu_user()
{
    seperator();
    current_user.print_user();
    cout << "1. increase wallet" << endl;
    cout << "2. buy product" << endl;
    cout << "3. log out" << endl;
    cout << "choose by number: ";
}

void after_login_loop_user()
{
    while (true)
    {
        current_user.print_user();
        after_login_menu_user();
        int x;
        cin >> x;

        if (x == 1)
        {
            increasing_wallet();
        }
        else if (x == 2)
        {
        }
        else if (x == 3)
        {
            break;
        }
        else
        {
            cout << "WTF" << endl;
        }
    }
}

void increasing_wallet()
{
    cout << "Increasing wallet: " << endl;
    cout << "amount: ";
    float amount;
    cin >> amount;
    current_user.increase_wallet(amount);
    cout << "seccessfully increased!";
}
