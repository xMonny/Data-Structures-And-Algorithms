/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 2
* @compiler GCC
*
*/

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    long long int number;
    int digit;
    int k = 0;
    int cnt = 0;

    cout << "Input number between -4 294 967 296 and 4 294 967 295: ";
    cin >> number;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    if (number < -4294967296 || number > 4294967295)
    {
        cout << "Wrong input!" << endl;
        return 0;
    }

    if (number == 0)
    {
        cout << "Wrong input!" << endl;
        return 0;
    }

    if (number < 0)
    {
        number = -number;
    }

    cout << "Type digit: ";
    cin >> digit;

    if (digit < 0 || digit > 9)
    {
        cout << "Digit can be between 0 and 9!" << endl;
        return 0;
    }

    for (int i = 0; i <= 10; i++)
    {
        if (cin.fail())
        {
            std::cout << "Wrong input!" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return 0;
        }

        k = number%10;
        number = number/10;

        if (k == digit)
        {
            cnt++;
        }

        if (number == 0)
        {
            break;
        }
    }

    if (cnt == 1)
    {
        cout << "Repeat: " << cnt << " time" << endl;
    }

    if (cnt > 1 || cnt == 0)
    {
        cout << "Repeat: " << cnt << " times" << endl;
    }

    return 0;
}
