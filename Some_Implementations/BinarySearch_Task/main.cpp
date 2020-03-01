#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void binarySearch(long arr[], int l, int r, long element, vector<int>& tries, int& one, int& check)
{
    if (l <= r)
    {
        int mid = l+(r-l)/2;
        check++;
        if (arr[mid] == element)
        {
            cout << mid << " ";
            one++;
            tries.push_back(one);
            return;
        }
        else
        {
            one++;
            if (arr[mid] < element)
            {
                return binarySearch(arr, mid+1, r, element, tries, one, check);
            }
            if (arr[mid] > element)
            {
                return binarySearch(arr, l, mid-1, element, tries, one, check);
            }

        }
    }
    else
    {
        if (check > 0)
        {
            cout << -1 << " ";
            tries.push_back(one);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    long* arr = new long[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int K;
    cin >> K;

    long* elements = new long[K];

    for (int i = 0; i < K; i++)
    {
        cin >> elements[i];
    }

    vector<int> tries;
    for (int i = 0; i < K; i++)
    {
        int one = 0;
        int check = 0;
        binarySearch(arr, 0, N-1, elements[i], tries, one, check);
    }
    cout << endl;

    for (int i = 0; i < tries.size(); i++)
    {
        cout << tries[i] << " ";
    }

    return 0;
}
