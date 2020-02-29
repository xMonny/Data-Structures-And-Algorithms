#include <iostream>
#include <limits>
#include "MagicBox.h"
#include "MagicBox.cpp"

using namespace std;

int main()
{
    MagicBox<int> magic;

    magic.insert(1);
    magic.insert(200);
    magic.insert(35);
    magic.insert(6);
    magic.insert(110);
    magic.insert(100);
    magic.insert(95);
    magic.insert(11);
    magic.insert(4);
    magic.insert(0);
    magic.push_in(2, 15);

    magic.change_element(10, 10);

    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    cout << endl;

    magic.pop();
    magic.list();

    return 0;
}
