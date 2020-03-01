#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void binarySearch(vector<long long>& numbers, int l, int r, long long element, vector<int>& positions, map<int, map<int, int>>& m, int& maximal, int& minimal)
{
    while (l <= r)
    {
        int mid = l+(r-l)/2;

        if (numbers[mid] == element)
        {
            minimal = mid;
            maximal = mid;
            if (m[element][element] > 1)
            {
                int i = mid-1;
                while (element == numbers[i])
                {
                    minimal = i;
                    i--;
                }
                i = mid+1;
                while (element == numbers[i])
                {
                    maximal = i;
                    i++;
                }
            }
            positions.push_back(minimal);
            positions.push_back(maximal);
            return;
        }
        if (numbers[mid] < element)
        {
            l = mid+1;
        }
        if (numbers[mid] > element)
        {
            r = mid-1;
        }
    }
}

void helpBinarySearch(vector<long long>& numbers, int l, int r, long long element)
{
    while (l <= r)
    {
        int mid = l+(r-l)/2;

        if (element > numbers[mid] && element < numbers[mid+1])
        {
            cout << mid+1 << endl;
            return;
        }
        else
        {
            if (numbers[mid] < element)
            {
                l = mid+1;
            }
            if (numbers[mid] > element)
            {
                r = mid-1;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<long long> numbers;
    long long element;

    map<int, map<int, int>> m;

    for (int i = 0; i < N; i++)
    {
        cin >> element;
        numbers.push_back(element);
        if (m[element][element] == 0)
        {
            m[element][element] = 1;
        }
        else
        {
            m[element][element]++;
        }
    }

    int Q;
    cin >> Q;

    long long searched;

    for (int i = 0; i < Q; i++)
    {
        cin >> searched;
        vector<int> positions;
        int maximal = 0;
        int minimal = 0;
        int remember = 0;
        if (m[searched][searched] >= 1)
        {
            binarySearch(numbers, 0, N-1, searched, positions, m, maximal, minimal);
            for (int i = 0; i < positions.size(); i++)
            {
                cout << positions[i] << " ";
            }
            cout << endl;
        }
        else
        {
            if (searched < numbers[0])
            {
                cout << 0 << endl;
            }
            if (searched > numbers[numbers.size()-1])
            {
                cout << numbers.size() << endl;
            }
            if (searched > numbers[0] && searched < numbers[numbers.size()-1])
            {
                helpBinarySearch(numbers, 0, N-1, searched);
            }
        }
    }

    return 0;
}
