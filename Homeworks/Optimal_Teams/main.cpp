#include <iostream>

using namespace std;

int main()
{
    long N;
    cin >> N;
    long k;
    cin >> k;

    long* arr = new long[N];

    for (long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long team = -1;
    long number = 0;
    long maximum = N;

    long player = k;

    long left = 0;
    long right = 0;

    long i = 0;

    while (i < N)
    {
        if (maximum <= 0)
        {
            break;
        }
        if (number == N-1 || number == N-2)
        {
            if (arr[i] > 0)
            {
                arr[i] = team;
                number++;
            }
        }
        else
        {
            if (arr[i] == maximum)
            {
                arr[i] = team;
                number++;
                left = i-1;
                right = i+1;

                player = k;

                while (player > 0 && left >= 0)
                {
                   if (arr[left] > 0)
                    {
                        arr[left] = team;
                        number++;
                        player--;
                    }
                    left--;
                }
                player = k;

                while (player > 0 && right < N)
                {
                   if (arr[right] > 0)
                    {
                        arr[right] = team;
                        number++;
                        player--;
                    }
                    right++;
                }

                if (team == -2)
                {
                team = -1;
                }
                else
                {
                   team = -2;
                }
                maximum--;
                i = -1;
            }
            else
            {
                if (i == N-1)
                {
                    maximum--;
                    i = -1;
                }
            }
        }

        if (number == N)
        {
            break;
        }
        i++;
    }

    for (long i = 0; i < N; i++)
    {
        cout << abs(arr[i]);
    }

    delete[] arr;

    return 0;
}

