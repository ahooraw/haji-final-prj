#include <bits/stdc++.h>

using namespace std;

// todo:
// bugs:
//      - after log out and login again wallet go to zero :)
//

class Product;
class User;
class Factor;
class Discount;

// classes
class User
{
    string username;
    string password;
    float wallet;
    string basket[100]; // max is 100 product name
    int basket_count;

public:
    User(string u = "null", string p = "null", float w = 0)
    {
        username = u;
        password = p;
        wallet = w;
        basket_count = 0;
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

    float increase_or_decrease_wallet(float amount)
    { // amount can be negative(buy) or positive(charge)
        wallet += amount;
    }

    string get_basket_product(int i)
    {
        return basket[i];
    }

    int get_basket_count()
    {
        return basket_count;
    }

    void set_username(string u)
    {
        username = u;
    }

    void set_password(string p)
    {
        password = p;
    }

    void set_wallet(float w)
    {
        wallet = w;
    }

    void set_basket_count(int n)
    {
        basket_count = n;
    }

    void add_to_basket(string product_name)
    {
        basket[basket_count] = product_name;
        basket_count++;
    }

    void remove_from_basket(int id)
    {
        for (size_t i = id; i < basket_count - 1; i++)
        {
            basket[i] = basket[i + 1];
        }
        basket_count--;
    }

    void print_basket()
    {
        for (size_t i = 0; i < basket_count; i++)
        {
            cout << "id: " << i << endl;
            cout << "name: " << basket[i] << endl;
            cout << endl;
        }
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

public:
    float price;
    int boughts_count;
    string boughts[100]; // max is 100 product
    // todo: date here
    bool is_pay;
    Factor(float p = 0)
    {
        price = p;
        boughts_count = 0;
        is_pay = false;
    }

    float get_price()
    {
        return price;
    }

    string get_boughts(int i)
    {
        return boughts[i];
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

    void add_bought(string product_name)
    {
        boughts[boughts_count] = product_name;
        boughts_count++;
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
            cout << "name: " << boughts[i] << endl;
            cout << endl;
        }
    }
};

class Discount
{

public:
    string secret_code;
    float percent;  // between 0 and 1 ex. 0.2
    int start_date; // date is all days from chises
    int end_date;
    bool is_used;

    Discount(string s = "null", float p = 0, int sd = 0, int ed = 0)
    {
        secret_code = s;
        percent = p;
        start_date = sd;
        end_date = ed;
        is_used = false;
    }

    void print_disoucnt()
    {
        cout << "- Discount : " << endl;
        cout << "      code: " << secret_code << endl;
        cout << "      percent: " << percent << endl;
        cout << "      start_date: " << start_date << endl;
        cout << "      end_date: " << end_date << endl;
        cout << "      is_used: " << is_used << endl;
    }
};

// prototypes
void seperator();
void show_menu();
void exit_fun();
void show_all_products();
int is_valid(string, string);
bool person_login();
void show_all_users();
bool is_available_user(string, string);
void increasing_wallet();
bool is_admin(User);
void after_login_loop_user();
void after_login_loop_admin();
void add_to_factors(Factor);
void add_to_users(User);
void add_to_products(Product);
void add_to_discounts(string, float, int, int, bool);
bool new_user();
void new_product();
void new_to_basket();
void new_discount();
void remove_product();
void buy_your_basket();
Product get_product_by_name(string);
bool is_exist_product_by_name(string);
bool confirm_buying();
void show_all_discounts();
void show_all_factors();
void read_products_in_file();
void read_users_in_file();
void read_discounts_in_file();
void read_factors_in_file();
void write_products_in_file();
void write_users_in_file();
void write_discounts_in_file();
void write_factors_in_file();

// global variables
const int max_products_count = 100000;
Product products[max_products_count];
int products_count = 0;

string admin_username = "Admin";
string admin_password = "Admin@123456";

// all users except admin
const int max_users_count = 1000;
User users[max_users_count];
int user_count = 0;

const int max_discounts_count = 100;
Discount discounts[max_discounts_count];
int discount_count = 0;

const int max_factor_count = 100;
Factor factors[max_factor_count];
int factors_count = 0;

int current_user_index = -1;
User admin(admin_username, admin_password);

int main(int argc, char const *argv[])
{
    read_products_in_file();
    read_users_in_file();
    read_discounts_in_file();
    read_factors_in_file();

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
            bool is_login = person_login(); // current user set here
            if (is_login)
            {
                if (current_user_index == -2)
                {
                    after_login_loop_admin();
                }
                else
                {
                    after_login_loop_user();
                }
            }
        }
        else if (x == 3)
        {
            bool is_new_user = new_user(); // new_user = sign_up
            if (is_new_user)
            {
                after_login_loop_user();
                write_users_in_file();
            }
        }
        else if (x == 4)
        {
            exit_fun();
        }
        else if (x == 5)
        {
            show_all_users();
        }
        else if (x == 6)
        {
            show_all_factors();
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
    users[user_count].set_username(user.get_username());
    users[user_count].set_password(user.get_password());
    users[user_count].set_wallet(0);
    user_count++;
}

void add_to_products(Product product)
{
    products[products_count] = product;
    products_count++;
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
    cout << "6. show all factors" << endl;
    cout << endl;
    cout << "choose by number: ";
}

void exit_fun()
{
    cout << "Good bye" << endl;
    exit(0);
}

void show_all_factors()
{
    cout << "All factors: " << endl;
    for (size_t i = 0; i < factors_count; i++)
    {
        cout << "id: " << i << endl;
        factors[i].print_Factor();
    }
}

void show_all_products()
{
    seperator();
    cout << "All Products: " << endl;
    for (size_t i = 0; i < products_count; i++)
    {
        cout << "id: " << i << endl;
        products[i].print_product();
    }
}

int is_valid(string username, string password)
{
    User not_found_user(" ", " ");
    // check is admin?
    if (username == admin_username and password == admin_password)
    {
        return -2;
    }
    else // this is not admin
    {
        for (size_t i = 0; i < user_count; i++)
        {
            if (username == users[i].get_username() and password == users[i].get_password())
            {

                return i;
            }
        }
    }

    return -1;
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

bool person_login()
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

    int user_index = is_valid(username, password);
    if (user_index != -1)
    {
        current_user_index = user_index;
        cout << "You entered successfully!" << endl;
        return true;
    }
    else
    {
        cout << "User Not found Bro!" << endl;
        return false;
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

Product get_product_by_name(string product_name)
{
    for (size_t i = 0; i < products_count; i++)
    {
        if (product_name == products[i].get_name())
        {
            return products[i];
        }
    }
}

bool new_user()
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
        return false;
    }
    else
    {
        current_user_index = user_count;
        User user(username, password);
        add_to_users(user);
        return true;
    }
}

bool is_admin(User user)
{
    return user.get_username() == admin_username;
}

bool is_exist_product_by_name(string name)
{
    for (size_t i = 0; i < products_count; i++)
    {
        if (name == products[i].get_name())
        {
            return true;
        }
    }
    return false;
}

/////////////////// after login admin functions ///////////////////////
void after_login_menu_admin()
{
    seperator();
    cout << "You are admin bro" << endl;
    cout << "1. new product" << endl;
    cout << "2. remove product" << endl;
    cout << "3. add discount" << endl;
    cout << "4. show all products" << endl;
    cout << "5. log out" << endl;
    cout << "6. show discounts" << endl;
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
            new_discount();
        }
        else if (x == 4)
        {
            show_all_products();
        }
        else if (x == 5)
        {
            write_products_in_file();
            write_discounts_in_file();
            current_user_index = -1;
            break;
        }
        else if (x == 6)
        {
            show_all_discounts();
        }
        else
        {
            cout << "WTF" << endl;
        }
    }
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

    for (size_t i = id; i < products_count - 1; i++)
    {
        products[i] = products[i + 1];
    }

    // we don't remove the product data and just wait to adding in this index in 'products' array
    products_count -= 1;
    cout << "product remove successfully!";
}

void new_discount()
{
    cout << "New discount: " << endl;

    cout << "code: ";
    string code;
    getline(cin, code);
    getline(cin, code);

    cout << "percent(between 0 and 1): ";
    float percent;
    cin >> percent;

    cout << "start date(YYYY MM DD): ";
    int year, month, day;
    cin >> year >> month >> day;
    int start_date = year * 365 + month * 30 + day;

    cout << "end date(YYYY MM DD): ";
    cin >> year >> month >> day;
    int end_date = year * 365 + month * 30 + day;

    add_to_discounts(code, percent, start_date, end_date, 0);
    cout << "discount added!" << endl;
}

void add_to_discounts(string c, float p, int sd, int ed, bool iu)
{
    discounts[discount_count].secret_code = c;
    discounts[discount_count].percent = p;
    discounts[discount_count].start_date = sd;
    discounts[discount_count].end_date = ed;
    discounts[discount_count].is_used = iu;
    discount_count++;
}

void show_all_discounts()
{
    for (size_t i = 0; i < discount_count; i++)
    {
        discounts[i].print_disoucnt();
    }
}

/////////////////// after login user functions ///////////////////////
void after_login_menu_user()
{
    cout << "1. increase wallet" << endl;
    cout << "2. new to basket (buy product)" << endl;
    cout << "3. pay your basket" << endl;
    cout << "4. log out" << endl;
    cout << "choose by number: ";
}

void after_login_loop_user()
{
    while (true)
    {
        seperator();
        users[current_user_index].print_user();
        after_login_menu_user();
        int x;
        cin >> x;

        if (x == 1)
        {
            increasing_wallet();
        }
        else if (x == 2)
        {
            new_to_basket();
        }
        else if (x == 3)
        {
            buy_your_basket();
        }
        else if (x == 4)
        {
            write_users_in_file();
            write_factors_in_file();
            current_user_index = -1;
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
    users[current_user_index].increase_or_decrease_wallet(amount);
    cout << "seccessfully increased!" << endl;
}

int zaman()
{ // saal v mahe alan ro tabdil be rooz mikone barmigardoone
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int d = (((1900 + ltm->tm_year) * 365) + ((1 + ltm->tm_mon) + 30) + (ltm->tm_mday));
    return d;
}

int is_valid_discount(string code)
{
    for (size_t i = 0; i < discount_count; i++)
    {
        if (discounts[i].secret_code == code)
        {
            if (discounts[i].start_date <= zaman() and discounts[i].end_date >= zaman())
            {
                return i;
            }
        }
    }

    return -1;
}

void buy_your_basket()
{
    if (users[current_user_index].get_basket_count() == 0)
    {
        cout << "your basket is blank bro!" << endl;
        return;
    }

    // this piece of code is not very clean :)
    if (confirm_buying())
    {

        float price_sum = 0;
        for (size_t i = 0; i < users[current_user_index].get_basket_count(); i++)
        {
            Product product = get_product_by_name(users[current_user_index].get_basket_product(i));
            price_sum += product.get_price();
        }

        if (discount_count != 0)
        {
            cout << "have discount code? (1/0): ";
            string x;
            getline(cin, x);
            getline(cin, x);
            if (x == "1")
            {
                cout << "enter code discount: ";
                string code;
                getline(cin, code);
                int discount_index = is_valid_discount(code);
                if (discount_index != -1)
                {
                    price_sum *= (1 - discounts[discount_index].percent);
                    discounts[discount_index].is_used = true;
                    write_discounts_in_file();
                }
            }
        }

        if (price_sum > users[current_user_index].get_wallet())
        {
            cout << "You can't buy your basket, You need to charge your wallet!" << endl
                 << endl;
        }
        else
        {
            Factor factor(price_sum);
            for (size_t i = 0; i < users[current_user_index].get_basket_count(); i++)
            {
                factor.add_bought(users[current_user_index].get_basket_product(i));
            }

            add_to_factors(factor);

            // remove all basket products
            for (size_t i = 0; i < users[current_user_index].get_basket_count(); i++)
            {
                users[current_user_index].remove_from_basket(i);
            }

            users[current_user_index].increase_or_decrease_wallet(-price_sum);
            cout << "You buy your basket successfully!" << endl;
        }
    }
}

void add_to_factors(Factor factor)
{
    factors[factors_count] = factor;
    factors_count++;
}

bool confirm_buying()
{
    users[current_user_index].print_basket();
    cout << endl;
    cout << "are you sure? (1/0) ";
    int x;
    cin >> x;

    return x == 1;
}

void new_to_basket()
{
    cout << "New to basket: " << endl;
    cout << "product name: ";
    string product_name;
    getline(cin, product_name);
    getline(cin, product_name);

    bool is_exist = is_exist_product_by_name(product_name);

    if (is_exist)
    {
        users[current_user_index].add_to_basket(product_name);
        cout << "successfully added!" << endl
             << endl;
    }
    else
    {
        cout << "not found this product name bro!" << endl
             << endl;
    }
}

// file
void write_products_in_file()
{
    ofstream products_file("products.txt");
    for (size_t i = 0; i < products_count; i++)
    {
        products_file << products[i].get_name() << ' ';
        products_file << products[i].get_price() << ' ';
    }
}

void write_users_in_file()
{
    ofstream users_file("users.txt");
    for (size_t i = 0; i < user_count; i++)
    {
        users_file << users[i].get_username() << ' ';
        users_file << users[i].get_password() << ' ';
        users_file << users[i].get_wallet() << ' ';
        users_file << users[i].get_basket_count() << ' ';
        for (size_t j = 0; j < users[i].get_basket_count(); j++)
        {
            users_file << users[i].get_basket_product(j) << ' ';
        }
    }
}

void write_discounts_in_file()
{
    ofstream discounts_file("discounts.txt");
    for (size_t i = 0; i < discount_count; i++)
    {
        discounts_file << discounts[i].secret_code << ' ';
        discounts_file << discounts[i].percent << ' ';
        discounts_file << discounts[i].start_date << ' ';
        discounts_file << discounts[i].end_date << ' ';
        discounts_file << discounts[i].is_used << ' ';
    }
}

void write_factors_in_file()
{
    ofstream factors_file("factors.txt");
    for (size_t i = 0; i < factors_count; i++)
    {
        factors_file << factors[i].price << ' ';
        factors_file << factors[i].boughts_count << ' ';
        for (size_t j = 0; j < factors[i].boughts_count; j++)
        {
            factors_file << factors[i].boughts[j] << ' ';
        }
        factors_file << factors[i].is_pay << ' ';
    }
}

void read_products_in_file()
{
    ifstream products_file("products.txt");
    string name;
    float price;
    while (products_file >> name)
    {
        products_file >> price;
        Product product(name, price);
        add_to_products(product);
    }
}

void read_users_in_file()
{
    ifstream users_file("users.txt");
    string username;
    string password;
    float wallet;
    string basket[100];
    int basket_count;
    while (users_file >> username)
    {
        users_file >> password;
        users_file >> wallet;
        users_file >> basket_count;
        for (size_t i = 0; i < basket_count; i++)
        {
            users_file >> basket[i];
        }
        users[user_count].set_username(username);
        users[user_count].set_password(password);
        users[user_count].set_wallet(wallet);
        users[user_count].set_basket_count(basket_count);
        for (size_t i = 0; i < users[user_count].get_basket_count(); i++)
        {
            users[user_count].add_to_basket(basket[i]);
        }
        user_count++;
    }
}

void read_discounts_in_file()
{
    ifstream discounts_file("discounts.txt");
    string secret_code;
    float percent;
    int start_date;
    int end_date;
    bool is_used;
    while (discounts_file >> secret_code)
    {
        discounts_file >> percent;
        discounts_file >> start_date;
        discounts_file >> end_date;
        discounts_file >> is_used;
        add_to_discounts(secret_code, percent, start_date, end_date, is_used);
    }
}

void read_factors_in_file()
{
    ifstream factors_file("factors.txt");
    float price;
    int boughts_count;
    string boughts[100];
    bool is_pay;
    while (factors_file >> price)
    {
        factors_file >> boughts_count;
        for (size_t i = 0; i < boughts_count; i++)
        {
            factors_file >> boughts[i];
        }
        factors_file >> is_pay;

        factors[factors_count].price = price;
        for (size_t i = 0; i < boughts_count; i++)
        {
            factors[factors_count].add_bought(boughts[i]);
        }
        factors[factors_count].is_pay = is_pay;
    }
}
