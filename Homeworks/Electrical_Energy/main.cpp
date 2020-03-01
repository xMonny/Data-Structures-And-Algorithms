#include <iostream>

using namespace std;

long cnt = 0;

void mergeAll(int arr[], long l, long m, long r)
{
    long i, j, k;
    long n1 = m-l+1;
    long n2 = r-m;

    int L[n1], R[n2];

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

    /*while (L[n1-1] > R[j] && j < n2)
    {
        for (long g = n1-1; g >= 0; g--)
        {
            if (L[g] > R[j])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        j++;
    }*/

    //i = 0;
    //j = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            cnt+=n1-i;
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

void mergeSort(int arr[], long l, long r)
{
    if (l < r)
    {
        long m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        mergeAll(arr, l, m, r);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long N;
    cin >> N;
    int* arr = new int[N];
    for (long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, N-1);
    cout << cnt;
    delete[] arr;
    return 0;
}

