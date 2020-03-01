#include <iostream>

using namespace std;

void countingSort(int arr[], int N, int minimal, int maximal)
{
    int length = maximal-minimal+1;
    /*int* index = new int[length];

    for (int i = 0; i < length; i++)
    {
        index[i] = i+minimal;
    }*/

    int* number = new int[length];
    for (int i = 0; i < length; i++)
    {
        number[i] = 0;
    }

    int position = 0;
    for (int i = 0; i < N; i++)
    {
        position = arr[i]-minimal;
        number[position]++;
    }

    int* sumNumber = new int[length];

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            sumNumber[i] = number[i];
        }
        else
        {
            sumNumber[i] = number[i]+sumNumber[i-1];
        }
    }

    int* finish = new int[N];
    int secondPosition = 0;

    for (int i = 0; i < N; i++)
    {
        position = arr[i]-minimal;
        secondPosition = sumNumber[position];
        sumNumber[position]--;
        finish[secondPosition-1] = arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] = finish[i];
    }

    //delete[] index;
    delete[] number;
    delete[] sumNumber;
    delete[] finish;
}

int main()
{
    int N;
    cin >> N;

    int arr[N];

    int minimal = 0;
    int maximal = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (i == 0)
        {
            minimal = arr[i];
            maximal = arr[i];
        }
        else
        {
            if (arr[i] < minimal)
            {
                minimal = arr[i];
            }
            if (arr[i] > maximal)
            {
                maximal = arr[i];
            }
        }
    }

    countingSort(arr, N, minimal, maximal);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
