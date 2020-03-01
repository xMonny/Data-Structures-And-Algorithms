#include <iostream>

using namespace std;

void mergeAll(char arr[], long long l, long long m, long long r)
{
    long long i, j, k;
    long long n1 = m-l+1;
    long long n2 = r-m;

    char L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[i+l];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[j+m+1];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if ((int)L[i] <= (int)R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(char arr[], long long l, long long r)
{
    if (l < r)
    {
        long long m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        mergeAll(arr, l, m, r);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long N;
    cin >> N;
    if (N == 0)
    {
        cout << "yes";
        return 0;
    }
    char* word1 = new char[N];
    char* word2 = new char[N];

    long long cnt = 0;

    for (long long i = 0; i < N; i++)
    {
        cin >> word1[i];
    }

    for (long long i = 0; i < N; i++)
    {
        cin >> word2[i];
    }

    mergeSort(word1, 0, N-1);
    mergeSort(word2, 0, N-1);

    for (long long i = 0; i < N; i++)
    {
        if (word1[i] != word2[i])
        {
            cout << "no";
            delete[] word1;
            delete[] word2;
            return 0;
        }
    }

    cout << "yes";

    delete[] word1;
    delete[] word2;

    return 0;
}
