/**
*
* Solution to homework task 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 3
* @compiler GCC
*
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int first;
    int second;
    int operand;

    int func;

    cout << setw(50) << "4 BITS CALCULATOR" << endl << endl;

    cout << "Input first number between 0 and 15: ";
    cin >> first;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    if (first < 0 || first > 15)
    {
        cout << "Wrong input!" << endl;
        return 0;
    }

    cout << "Input second number between 0 and 15: ";
    cin >> second;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    if (second < 0 || second > 15)
    {
        cout << "Wrong input!" << endl;
        return 0;
    }

    cout << "Input operation between 0 and 3 (0 for ""'+'"", 1 for ""'-'"", 2 for ""'*'"" and 3 for ""'/'"": ";
    cin >> operand;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    if (operand < 0 || operand > 3)
    {
        cout << "Wrong operation!" << endl;
        return 0;
    }

    if (operand == 0)
    {
        func = first + second;

        if (func > 15)
        {
            func = func%16;
        }
    }

    if (operand == 1)
    {
        func = abs(first - second);

        if (func > 15)
        {
            func = func%16;
        }
    }

    if (operand == 2)
    {
        func = first * second;
        if (func > 15)
        {
            func = func%16;
        }
    }

    if (operand == 3)
    {
        if (second == 0)
        {
            cout << "You can't divide to 0!" << endl;
            return 0;
        }
        func = first / second;
    }

    cout << "Answer: " << func << endl;

    return 0;
}
