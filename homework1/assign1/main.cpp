//Author:    Gregorics Tibor
//Date:      2017.08.08.
//Title:     Diagonal matrix

#include <iostream>
#include "diag.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE

//class of menu for diagonal matrix
class Menu
{
public:
    Menu() : a(0) { }
    void run();
private:
    Diag a;

    void menuWrite();
    void get() const;
    void set();
    void read();
    void write();
    void sum();
    void mul();
};

int main()
{
//    setlocale(LC_ALL,"Hun");
    Menu m;
    m.run();
}

void Menu::run()
{
    int n = 0;
    do
    {
        menuWrite();
        cout << endl << ">>>>" ;
        cin >> n;
        switch(n)
        {
        case 1:
            get();
            break;
        case 2:
            set();
            break;
        case 3:
            read();
            break;
        case 4:
            write();
            break;
        case 5:
            sum();
            break;
        case 6:
            mul();
            break;
        }
    }
    while(n!=0);
}

void Menu::menuWrite()
{
    cout << endl << endl;
    cout << " 0. - Quit" << endl;
    cout << " 1. - Get an element of the matrix" << endl;
    cout << " 2. - Overwrite an element of the matrix" << endl;
    cout << " 3. - Read matrix" << endl;
    cout << " 4. - Write matrix" << endl;
    cout << " 5. - Add matrices" << endl;
    cout << " 6. - Multiply matrices" << endl;
}

void Menu::get() const
{
    int i,j;
    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the column: ";
    cin >> j;
    try
    {
        cout << "a[" << i << "," << j << "]= " << a(i-1,j-1) << endl;
    }
    catch(Diag::Exceptions ex)
    {
        if(ex == Diag::OVERINDEXED)
            cout << "Overindexing!" << endl;
        else
            cout << "Unhandled ecxeption!" << endl;
    }
}

void Menu::set()
{
    int i,j,e;
    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the column: ";
    cin >> j;
    cout << "Give the value: ";
    cin >> e;
    try
    {
        a(i-1,j-1) = e;
    }
    catch(Diag::Exceptions ex)
    {
        if(ex == Diag::OVERINDEXED)
            cout << "Overindexing!" << endl;
        if (ex == Diag::NULLPART)
            cout << "These indexes do not point to the diagonal!" << endl;
    }
}

void Menu::read()
{
    try
    {
        cout << "Give the size and the items of the matrix: ";
        cin >> a;
    }
    catch(Diag::Exceptions ex)
    {
        if(ex == Diag::INVALID)
            cout << "Invalid size!" << endl;
        else
            cout << "Unhandled ecxeption!" << endl;
    }
}

void Menu::write()
{
    cout << a << endl;
}

void Menu::sum()
{
    try
    {
        Diag b;

        cout << "Give the size and the items of the second  matrix: " << endl;
        cin >> b;
        cout << "Sum of the matrices: " << endl;
        cout << a + b << endl;
    }
    catch(Diag::Exceptions ex)
    {
        if(ex == Diag::INVALID)
            cout << "Invalid size!" << endl;
        if(ex == Diag::DIFFERENT)
            cout << "Different sizes!" << endl;
    }
}

void Menu::mul()
{
    try
    {
        Diag b;

        cout << "Give the size and the items of the second  matrix: " << endl;
        cin >> b;
        cout << "Product of the matrices: " << endl;
        cout << a * b << endl;
    }
    catch(Diag::Exceptions ex)
    {
        if(ex == Diag::INVALID)
            cout << "Invalid size!" << endl;
        if(ex == Diag::DIFFERENT)
            cout << "Different sizes!" << endl;
    }
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("create", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag c;
    in >> c; // 3
    CHECK(c(0,0) == 3);
    CHECK(c(1,1) == 2);
    CHECK(c(2,2) == 1);

    Diag b;
    in >> b; // 2
    CHECK(b(0,0) == 2);
    CHECK(b(1,1) == 1);

    Diag a;
    in >> a; // 1
    CHECK(a(0,0)==1);
}

TEST_CASE("getting and changing an element of the matrix", "")
{
    Diag a( {1,1,1} );
    CHECK(a(0,0) == 1);
    a(0,0) = 0;
    CHECK(a(0,0) == 0);
}

TEST_CASE("copy constructor", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a;
    in >> a; // 3

    Diag b = a;

    CHECK(a(0,0) == b(0,0));
    CHECK(a(1,1) == b(1,1));
    CHECK(a(2,2) == b(2,2));
}

TEST_CASE("assignment operator", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a, b; // 3
    in >> a;

    b = a; // check every non-zero item
    CHECK(a(0,0) == b(0,0));
    CHECK(a(1,1) == b(1,1));
    CHECK(a(2,2) == b(2,2));

    Diag c; // 3
    c = b = a; // check every non-zero item
    CHECK(a(0,0) == c(0,0));
    CHECK(a(1,1) == c(1,1));
    CHECK(a(2,2) == c(2,2));

    a = a; // check every non-zero item
    CHECK(a(0,0) == 3);
    CHECK(a(1,1) == 2);
    CHECK(a(2,2) == 1);
}

TEST_CASE("add", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a, b, c, d, f, e, z; // 3
    in >> a >> b >> z >> e;

    c = a + b; // check every non-zero item
    CHECK(c(0,0) == 4);
    CHECK(c(1,1) == 5);
    CHECK(c(2,2) == 6);

    d = b + a; // check every non-zero item
    CHECK(c(0,0) == d(0,0));
    CHECK(c(1,1) == d(1,1));
    CHECK(c(2,2) == d(2,2));

    d = (a + b) + c;
    f = a + (b + c); // check every non-zero item
    CHECK(d(0,0) == f(0,0));
    CHECK(d(1,1) == f(1,1));
    CHECK(d(2,2) == f(2,2));

    c = a + z; // check every non-zero item
    CHECK(c(0,0) == a(0,0));
    CHECK(c(1,1) == a(1,1));
    CHECK(c(2,2) == a(2,2));
}

TEST_CASE("multiply", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a, b, c, d, f, e, z; // 3
    in >> a >> b >> z >> e;

    c = a * b;
    CHECK(c(0,0) == 3);
    CHECK(c(1,1) == 6);
    CHECK(c(2,2) == 9);

    d = b * a;
    CHECK(c(0,0) == d(0,0));
    CHECK(c(1,1) == d(1,1));
    CHECK(c(2,2) == d(2,2));

    d = (a * b) * c;
    f = a * (b * c);
    CHECK(d(0,0) == f(0,0));
    CHECK(d(1,1) == f(1,1));
    CHECK(d(2,2) == f(2,2));

    c = a * e;
    CHECK(c(0,0)== a(0,0));
    CHECK(c(1,1)== a(1,1));
    CHECK(c(2,2)== a(2,2));
}

TEST_CASE("exceptions", "")
{

    Diag a(3);

    try
    {
        a(3,3) = 4;
    }
    catch(Diag::Exceptions ex)
    {
        CHECK(ex == Diag::OVERINDEXED);
    }

    try
    {
        a(-1,4) = 4;
    }
    catch(Diag::Exceptions ex)
    {
        CHECK(ex == Diag::OVERINDEXED);
    }

    Diag b(2);
    Diag c(3);

    try
    {
        a = b;
    }
    catch(Diag::Exceptions ex)
    {
        CHECK(ex == Diag::DIFFERENT);
    }

    try
    {
        c = a + b;
    }
    catch(Diag::Exceptions ex)
    {
        CHECK(ex == Diag::DIFFERENT);
    }

    try
    {
        c = a * b;
    }
    catch(Diag::Exceptions ex)
    {
        CHECK(ex == Diag::DIFFERENT);
    }


    try
    {
        a(1,0) = 4;
    }
    catch(Diag::Exceptions ex)
    {
        CHECK(ex == Diag::NULLPART);
    }

    try
    {
        int  k = a(1,0);
    }
    catch(Diag::Exceptions ex)
    {
        CHECK(ex == Diag::NULLPART);
    }
}

#endif
