#include <iostream>
#include <limits>
#include "IntStack.h"
#include "IntStack.cpp"

using namespace std;

int main()
{
    IntStack trying;

    int setSize;
    int element;

    cout << "Set size of your stack: ";
    cin >> setSize;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! Set size of your stack: ";
        cin >> setSize;
    }

    cout << endl << "Set your elements: ";

    for (int i = 0; i < setSize; i++)
    {
        cin >> element;
        trying.push(element);
    }

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        return 0;
    }

    cout << endl << "Reversed stack: ";

    trying.printReversed();

    sortStack(trying);

    cout << endl << "Sorted stack: ";

    trying.printNormal();

    //Another test

    /*cout << endl << "Do you want to change any element?: ";
    char* c1 = new char[1];
    cin >> c1;

    if (c1[0] == 'y' || c1[0] == 'Y')
    {
        cout << endl << "Set position and new element: ";
        int position;
        int value;
        cin >> position;
        cin >> value;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input! Set position and new element: ";
            cin >> position;
            cin >> value;
        }

        trying.changeElement(position, value);
        trying.printNormal();
    }

    cout << endl << "Do you want to insert any element?: ";
    char* c2 = new char[1];
    cin >> c2;

    if (c2[0] == 'y' || c2[0] == 'Y')
    {
        cout << endl << "Set position and element: ";
        int position;
        int value;
        cin >> position;
        cin >> value;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input! Set position and element: ";
            cin >> position;
            cin >> value;
        }

        trying.insertElement(position, value);
        trying.printNormal();
    }

    cout << endl << "Do you want to remove any element?: ";
    char* c3 = new char[1];
    cin >> c3;

    if (c3[0] == 'y' || c3[0] == 'Y')
    {
        cout << endl << "Set position: ";
        int position;
        cin >> position;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input! Set position: ";
            cin >> position;
        }

        trying.removeElement(position);
        trying.printNormal();
    }

    cout << endl << "Do you want to get any element?: ";
    char* c4 = new char[1];
    cin >> c4;

    if (c4[0] == 'y' || c4[0] == 'Y')
    {
        cout << endl << "Set position: ";
        int position;
        cin >> position;
        cout << trying.getElement(position);
    }

    cout << endl << "Do you want to remove the last element?: ";
    char* c5 = new char[1];
    cin >> c5;

    if (c5[0] == 'y' || c5[0] == 'Y')
    {
        trying.pop();
        trying.printNormal();
    }

    cout << endl << "Do you want to get the first element?: ";
    char* c6 = new char[1];
    cin >> c6;

    if (c6[0] == 'y' || c6[0] == 'Y')
    {
        cout << trying.getBegin() << endl;
    }

    cout << endl << "Do you want to get the last element?: ";
    char* c7 = new char[1];
    cin >> c7;

    if (c7[0] == 'y' || c7[0] == 'Y')
    {
        cout << trying.getEnd() << endl;
    }*/

    return 0;
}
