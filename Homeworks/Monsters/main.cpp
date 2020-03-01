#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void mergeAll(int arr[], long l, long m, long r)
{
    long i, j, k;
    long n1 = m-l+1;
    long n2 = r-m;

    int* L = new int[n1];
    int* R = new int[n2];

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
        if (L[i] <= R[j])
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

    delete[] L;
    delete[] R;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long N;
    long found = 0;
    long x;

    long cnt = 0;

    cin >> N >> x;

    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    if (N == 1 )
    {
        cout << 1;
        return 0;
    }

    int* position = new int[N];

    for (long i = 0; i < N; i++)
    {
        cin >> position[i];
    }

    mergeSort(position, 0, N-1);

    long help = 0;

    for (long i = N-1; i >= 0;)
    {
        if (position[help] == position[i])
        {
            cnt++;
            break;
        }
        if (position[i]-x <= 0)
        {
            cnt++;
            break;
        }
        long g = i;
        if (position[g] == position[g-1])
        {
            while (position[g] == position[g-1])
            {
                N--;
                g--;
            }
            if (g == 0)
            {
                cnt++;
                break;
            }
        }
        N--;

        long j = N-1;
        while (position[j]-x >= 0 && j >= 0)
        {
            if (position[j]-x == 0)
            {
                help++;
            }
            else
            {
                position[j]-=x;
                j--;
                found++;
            }
        }
        if (found != 0)
        {
            cnt++;
            found = 0;
        }
        i = N-1;
    }

    cout << cnt;

    delete[] position;

    return 0;
}
