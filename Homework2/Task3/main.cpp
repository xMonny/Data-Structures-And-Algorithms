#include <iostream>
#include "Guest.h"
#include "Guest.cpp"
#include "User.h"
#include "User.cpp"
#include "PowerUser.h"
#include "PowerUser.cpp"
#include "Vip.h"
#include "Vip.cpp"
#include "Admin.h"
#include "Admin.cpp"

using namespace std;

int main()
{
    Admin a1("123.456", "Simona", "1111", "Title");
    a1.print();
    Admin a2("999.821.430.211", "Monny", "1234", "New");

    a1.changePassword("1111", "123");

    a2.giveReputation(a1);

    a1.print();
    a2.print();

    a1.changePassword("111", "123");

    a2.setTitle("Go");
    a1.setUsername("Username");

    a1.print();

    a2.print();

    a1.giveReputation(a2);
    a2.print();

    Vip v1("192.333.245.140", "Ivan", "8976", "Caption");
    v1.print();
    v1.changePassword("8976", "1234");
    v1.setTitle("Changed");
    v1.print();

    PowerUser p("132.234.111.098", "Mimi", "43523", "Let's go");
    p.print();
    p.changePassword("43523", "1234");
    p.print();
    a1.giveReputation(p);
    p.print();

    p.giveReputation(a2);
    a2.print();

    a2.changeUsername(p, "Hey");
    p.print();

    a1.changeUsername(a1, "How are you");
    a1.print();
    a1.setUsername("Fine");
    a1.print();

    User u1("110.298.333.105", "Alex", "1092", "Another");
    u1.print();
    u1.changePassword("1092", "1187");
    u1.print();

    cout << endl;

    Guest g1("119.115.113.009");
    g1.print();

    return 0;
}
