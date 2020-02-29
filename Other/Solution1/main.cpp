#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

int* seeDigits(int N)
{
    int cnt = 0;
    int help = abs(N);

    while (N != 0)
    {
        cnt++;
        N = N/10;
    }

    int* arr = new int[cnt];

    for (int i = cnt; i > 0; i--)
    {
        arr[i-1] = help%10;
        help /= 10;
    }

    return arr;
}

int main()
{
    int number = 0;

    while (number >= -65000 && number <=65000)
    {
        cout << "Type a number in [-65000; 65000]: ";
        cin >> number;
        int help = number;

        if (cin.fail())
        {
            std::cout << "Wrong input!" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return 0;
        }

        if (number >= -65000 && number <= 65000)
        {
            int lenght = 0;

            while (help != 0)
            {
                lenght++;
                help = help/10;
            }

            int* p = seeDigits(number);

            cout << "Digits: ";
            for (int i = 0; i < lenght; i++)
            {
                cout << p[i] << " ";
            }
            cout << endl;
            delete p;
        }
        else
        {
            cout << "Wrong number!" << endl;
            return 0;
        }
    }

    return 0;
}
