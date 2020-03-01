#include <iostream>

using namespace std;

int main() {
    int T;
    int N, M;
    cin >> T;
    string arr[T];
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        if (N < 0 || M <= 0)
        {
            arr[i] = "no";
        }
        if (N == 0 && M == 1)
        {
            arr[i] = "yes";
        }
        if (M == N+1)
        {
            arr[i] = "yes";
        }
        if (M%2 == 0 && N%2 == 1)
        {
            if (M > N && M != N+1)
            {
                arr[i] = "no";
            }
            else
            {
                arr[i] = "yes";
            }
        }
        if (M%2 == 1 && N%2 == 0)
        {
            if (M > N && M != N+1)
            {
                arr[i] = "no";
            }
            else
            {
                arr[i] = "yes";
            }
        }
        if (M%2 == 1 && N%2 == 1)
        {
            arr[i] = "no";
        }
        if (M%2 == 0 && N%2 == 0)
        {
            arr[i] = "no";
        }
        if (N > 0 && M == 1)
        {
            arr[i] = "no";
        }
        if (N == 0 && M > 1)
        {
            arr[i] = "no";
        }
        if (N > 0 && M == 0)
        {
            arr[i] = "no";
        }
    }

    for (int i = 0; i < T; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
