#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long rooms;
    cin >> rooms;
    long* keys = new long[rooms-1];
    long* doors = new long[rooms-1];

    int number = 0;

    for (long i = 0; i < rooms-1; i++)
    {
        cin >> keys[i];
    }
    for (long i = 0; i < rooms-1; i++)
    {
        cin >> doors[i];
    }

    unordered_map<long, long> m;
    unordered_map<long, long>::iterator it;

    m.insert(make_pair(keys[0], 1));

    for (long i = 0; i < rooms-1; i++)
    {
        if (i != 0)
        {
            it = m.find(keys[i]);
            if (it == m.end())
            {
                m.insert(make_pair(keys[i], 1));
            }
            else
            {
                it->second++;
            }
        }
        it = m.find(doors[i]);
        if (it == m.end())
        {
            number++;
        }
        else
        {
            it->second--;
            if (it->second == 0)
            {
                m.erase(it);
            }
        }

    }

    cout << number;

    delete[] keys;
    delete[] doors;

    return 0;
}
