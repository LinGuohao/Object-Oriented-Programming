#include <iostream>
#include "Set.h"

using namespace std;

class Menu{
private:
    void menuWrite();
public:
    Menu(){};
    void run(Set s);
};

void Menu::menuWrite(){
    cout << endl << endl;
    cout << " 0. - Quit" << endl;
    cout << " 1. - Insert an element" << endl;
    cout << " 2. - Remove an element" << endl;
    cout << " 3. - Check if the set is empty" << endl;
    cout << " 4. - Check if the set contains an element" << endl;
    cout << " 5. - Return a random element without removing it from the set" << endl;
    cout << " 6. - Return the largest element of the set" << endl;
    cout << " 7. - Print the set" << endl;
}


void Menu::run(Set s)
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
            cout << endl;
            int a;
            cout << "Enter the element you want to add: ";
            cin >> a;
            cout << endl;
            if(s.IsContain(a)){
                cout << "You cannot add the element. Such element is already exists" << endl;
            }
            else{
            s.InsertElement(a);
            cout << "The element insertation was successfull! " << endl;
            }
            break;
        case 2:
            cout << endl;
            if(s.IsEmpty()){
                cout << "The set is empty, you can not remove element" << endl;
            }
            else{
            int b;
            cout << "Enter the number you want to delete" << endl;
            cin >> b;
            if(s.IsContain(b)){
            s.RemoveElement(b);
            cout << "The element deleted successfully" << endl;
            }
            else{
                cout << "There is no such element in set" << endl;
            }
            }
            break;
        case 3:
            cout << endl;
            if(s.IsEmpty()){
                cout << "The set is Empty" << endl;
            }
            else{
                cout << "The set is not Empty" << endl;
            }
            break;
        case 4:
            cout << endl;
            if(s.IsEmpty()){
                cout << "The set is empty, you can not remove element" << endl;
            }
            else{
            int c;
            cout << "Enter the number you want to search for" << endl;
            cin >> c;
            if(s.IsContain(c)){
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
            }
            break;
        case 5:
            cout << endl;
            if(s.IsEmpty()){
                cout << "The set is empty, you can not remove element" << endl;
            }
            else{
            cout << "The random element is: " << s.RandomElement();
            }
            break;
        case 6:
            cout << endl;
            if(s.IsEmpty()){
                cout << "The set is empty, you can not remove element" << endl;
            }
            else{
            cout << "The Largest element of set is: " << s.LargestElement()<< endl;
            }
            break;

        case 7:
            cout << endl;
            if(s.IsEmpty()){
                cout << "The set is empty" << endl;
            }
            else{
            s.Print();
            break;
            }
        }
        }

    while(n!=0);
}

int main()
{
    Set s;
    Menu m;
    m.run(s);

    return 0;
}
