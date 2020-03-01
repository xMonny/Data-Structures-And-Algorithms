#include <iostream>

using namespace std;

long upperBound(long sortedArr[], long n, long element)
{
    long l = 0;
    long r = n;
    while (l < r)
    {
        long middle = l+(r-l)/2;
        if (element >= sortedArr[middle])
        {
            l = middle+1;
        }
        else
        {
            r = middle;
        }
    }
    return l;
}

long lowerBound(long sortedArr[], long n, long element)
{
    long l = 0;
    long r = n;
    while (l < r)
    {
        long middle = l+(r-l)/2;
        if (element <= sortedArr[middle])
        {
            r = middle;
        }
        else
        {
            l = middle+1;
        }
    }
    return r;
}

int main()
{
    long N;
    cin >> N;

    long* cups = new long[N];

    for (long i = 0; i < N; i++)
    {
        cin >> cups[i];
    }

    long M;
    cin >> M;

    long* numbers = new long[M];

    for (long i = 0; i < M; i++)
    {
        cin >> numbers[i];
    }

    long* index = new long[N];

    for (long i = 0; i < N; i++)
    {
        if (i == 0)
        {
            index[i] = cups[i];
        }
        else
        {
            index[i] = index[i-1]+cups[i];
        }
    }

    for (long i = 0; i < M; i++)
    {
        cout << lowerBound(index, N, numbers[i])+1 << endl;
    }

    delete[] cups;
    delete[] numbers;
    delete[] index;

    return 0;
}


