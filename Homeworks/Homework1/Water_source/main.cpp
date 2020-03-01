#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int S = 0;
    int height = 0;
    int length = 0;
    int pos = 0;
    int j = 1;

    for (int i = j; i <= N-1; i++)
    {
        if (arr[pos] < arr[i])
        {
            height = arr[pos];
        }
        else
        {
            height = arr[i];
        }
        length = abs(pos-i);
        if (height*length > S)
        {
            S = height*length;
        }
        if (i == N - 1)
        {
            j++;
            i=j;
            i--;
            pos++;
        }
    }
    cout << S;

    return 0;
}
