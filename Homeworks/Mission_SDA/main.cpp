#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int help = 0;
    int ans = 0;
    int number = 0;
    cin >> N;
    cin >> M;
    int arr[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < M; i++)
    {
        if (arr[i] < 0)
        {
            number = arr[i];
            break;
        }
    }
    help = N - number;
    for (int i = 0; i < M; i++)
    {
        if (arr[i] > N)
        {
            if (arr[i] - N < help)
            {
                number+=arr[i]-N;
                arr[i]-=N;
            }
            else
            {
                while(number != N)
                {
                    arr[i]--;
                    number++;
                }
            }
        }
        if (number >= N)
        {
            cout << "yes";
            return 0;
        }
        if (i == M-1 && number < N)
        {
            cout << "no";
            return 0;
        }
    }
}
