/**
*
* Solution to homework task 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 1
* @compiler GCC
*
*/

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int number;
    int minimal = 0;
    int maximal = 0;
    int difference = 0;
    int cnt = 0;

    cout << "Input numbers between 0 and 65 535." << endl;

    while (number >= 0)
    {
        cin >> number;

        cnt++;

        if (cin.fail())
        {
            std::cout << "Wrong input!" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return 0;
        }

        if (number > 65535)
        {
            cout << "Wrong input!" << endl;
            return 0;
        }

        if (number < 0 && cnt == 1)
        {
            cout << "Input positive numbers!" << endl;
            return 0;
        }

        if (minimal == 0 && maximal == 0 && cnt == 1)
        {
            minimal = number;
            maximal = number;
        }

        if (number < minimal)
        {
            if (number < 0)
            {
                minimal != number;
            }
            else
            {
                minimal = number;
            }
        }

        if (number > maximal)
        {
            if (number < 0)
            {
                maximal != number;
            }
            else
            {
                maximal = number;
            }
        }
    }

    if (minimal == maximal && difference == 0 && cnt < 3)
    {
        cout << "Input at least 2 positive numbers!" << endl;
        return 0;
    }

    difference = maximal - minimal;

    cout << "MAX number: " << maximal << endl;
    cout << "MIN number: " << minimal << endl;

    cout << "The difference between MAX number and MIN number is: " << difference << endl;

    return 0;
}
