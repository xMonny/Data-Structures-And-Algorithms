#include <iostream>

using namespace std;

void mergeAll(int arr[], int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid-l+1;
    int n2 = r-mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[i+l];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[j+mid+1];
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

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        mergeAll(arr, l, m, r);
    }
}

int main()
{
    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, N-1);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
