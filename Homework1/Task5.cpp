/**
*
* Solution to homework task 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 5
* @compiler GCC
*
*/

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    double x, y; //coordinates

    cout << "Input x: ";
    cin >> x;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    cout << "Input y: ";
    cin >> y;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        return 0;
    }

    else if (x*x + y*y > 36.0)
    {
        cout << "Outside" << endl;
        return 0;
    }

    if (x*x + y*y == 0)
    {
        cout << "Undefined" << endl;
        return 0;
    }

    if (x*x + y*y == 36.0)
    {
        cout << "Undefined" << endl;
        return 0;
    }

    if (x <= 0.0 && y >= 0.0)
    {
        if (y >= 2.0 && y <= 4.0 && x >= -1.0)
        {
            y = y - 3.0;

            if (x*x + y*y == 1)
            {
                cout << "Undefined" << endl;
                return 0;
            }

            else
            {
                cout << "Black" << endl;
                return 0;
            }
        }

        if (x*x + y*y > 1 && x*x + y*y <36)
        {
            cout << "White" << endl;
            return 0;
        }
    }

    if (x >= 0.0 && y >= 0.0)
    {
        if (x <= 1.0 && y >= 2.0 && y <= 4.0)
        {
            y = y - 3.0;

            if (x*x + y*y == 1)
            {
                cout << "Undefined" << endl;
                return 0;
            }

            else
            {
                cout << "Black" << endl;
                return 0;
            }
        }

        if (x*x + y*y > 1)
        {
            if (x <= 3 && y <= 6)
            {
                y = y - 3.0;

                if (x*x + y*y == 9)
                {
                    cout << "Undefined" << endl;
                    return 0;
                }

                else
                {
                    cout << "White" << endl;
                    return 0;
                }
            }

            if (x*x + y*y > 9 && x*x + y*y <36)
            {
                cout << "Black" << endl;
                return 0;
            }
        }
    }

    if (x >= 0.0 && y <= 0.0)
    {
        if (x <= 1.0 && y <= -2.0 && y >= -4.0)
        {
            y = y + 3.0;

            if (x*x + y*y == 1)
            {
                cout << "Undefined" << endl;
                return 0;
            }

            else
            {
                cout << "White" << endl;
                return 0;
            }
        }

        if (x*x + y*y > 1 && x*x + y*y < 36)
        {
            cout << "Black" << endl;
            return 0;
        }
    }

    if (x <= 0 && y <= 0)
    {
        if (x >= -1 && y <= -2 && y >= -4)
        {
            y = y + 3.0;

            if (x*x + y*y == 1)
            {
                cout << "Undefined" << endl;
                return 0;
            }

            else
            {
                cout << "White" << endl;
                return 0;
            }
        }

        if (x*x + y*y > 1 && x*x + y*y < 36)
        {
            if (x >= -3 && y >= -6)
            {
                y = y + 3.0;
                if (x*x + y*y == 9)
                {
                    cout << "Undefined" << endl;
                    return 0;
                }

                else
                {
                    cout << "Black" << endl;
                    return 0;
                }
            }

            if (x*x + y*y > 9 && x*x + y*y < 36)
            {
                cout << "White" << endl;
                return 0;
            }
        }
    }
}
