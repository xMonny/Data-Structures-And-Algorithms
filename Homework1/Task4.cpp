/**
*
* Solution to homework task 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 4
* @compiler GCC
*
*/

#include<iostream>
#include <iomanip>
#include <math.h>
#include <limits>

using namespace std;

int main()
{
    int console_width = 80;
    int console_height = 25;
    int side;
    char sign;
    cout << "Choose side: ";

    cin >> side;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    if (side > (console_height/2)+1)
    {
        cout << "The square is out of screen!" << endl;
        return 0;
    }

    if (side <= 0)
    {
        cout << "Wrong input!" << endl;
        return 0;
    }

    cout << "Choose symbol: ";
    cin >> sign;

    int h = 0;

    while (h != ((console_height - (2*side - 1))/2))
    {
        cout << endl;
        h++;
    }

    int distance = 1;

    for (int rows = 1; rows <= side; rows++)
    {
        for (int cols = side; cols > rows; cols--)
        {
            cout << setw(console_width/2) << right << setw(2) << " ";
        }

        cout << setw(console_width/2) << right << sign;

        if (rows > 1)
        {
            for (int i = 1; i <= distance; i++)
            {
                cout << setw(console_width/2) << right << setw(2) << sign;
            }
            distance += 2;

            cout << setw(console_width/2) << right << setw(2) << sign;
        }

        cout << endl;
    }

    distance -= 4;

    for (int rows = 1; rows <= side-1; rows++)
    {
        for (int cols = 1; cols <= rows; cols++)
        {
            cout << setw(console_width/2) << right << setw(2) << " ";
        }

        cout << setw(console_width/2) << right << sign;

        for (int i = 1; i <= distance; i++)
        {
            cout << setw(console_width/2) << right << setw(2) << sign;
        }

        distance -= 2;

        if (rows != side-1)
        {
            cout << setw(console_width/2) << right << setw(2) << sign;
        }

    cout << endl;
  }

  return 0;
}

