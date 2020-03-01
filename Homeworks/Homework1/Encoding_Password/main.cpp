#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int cnt = 1;

    for (int i = 0; i < str.length(); i++)
    {
        if (i == str.length() - 1)
        {
            cout << cnt << str.at(i);
        }
        else
        {
            if (str.at(i) == str.at(i+1))
            {
                cnt++;
            }
            else
            {
                cout << cnt << str.at(i);
                cnt = 1;
            }
        }
    }

    return 0;
}
