#include <iostream>

using namespace std;

void mergeAll(long arr[], long l, long middle, long r)
{
    long i, j, k;
    long n1 = middle-l+1;
    long n2 = r-middle;

    long* L = new long[n1];
    long* R = new long[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[i+l];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[j+middle+1];
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

void mergeSort (long arr[], long l, long r)
{
    if (l < r)
    {
        long middle = l+(r-l)/2;
        mergeSort(arr, l, middle);
        mergeSort(arr, middle+1, r);

        mergeAll(arr, l, middle, r);
    }
}

long shacks, cows;

int checkCow(long number, long coordinates[])
{
    long ourCows = 1;
    long currentPosition = coordinates[0];

    for (long i = 1; i < shacks; i++)
    {
        if (coordinates[i]-currentPosition >= number)
        {
            currentPosition = coordinates[i];
            ourCows++;
            if (ourCows == cows)
            {
                return 1;
            }
        }
    }
    return 0;
}

long binarySearch(long sortedArr[])
{
    long l = 0;
    long r = sortedArr[shacks-1];
    long maximal = -1;

    while (l < r)
    {
        long middle = l+(r-l)/2;
        if (check(middle, sortedArr)==1)
        {
            if (middle > maximal)
            {
                maximal = middle;
            }
            l = middle+1;
        }
        else
        {
            r = middle;
        }
    }
    return maximal;
}

int main()
{
    cin >> shacks;
    cin >> cows;

    long* coordinates = new long[shacks];

    for (long i = 0; i < shacks; i++)
    {
        cin >> coordinates[i];
    }

    mergeSort(coordinates, 0, shacks-1);

    cout << binarySearch(coordinates);

    delete[] coordinates;

    return 0;
}
