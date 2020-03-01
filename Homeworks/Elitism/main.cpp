#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void swapElements(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

class Max_Heap
{
    vector<double> v;

    int getLeft(int position)
    {
        return 2*position+1;
    }
    int getRight(int position)
    {
        return 2*position+2;
    }
    int getParent(int position)
    {
        return (position-1)/2;
    }

    void siftUp(int position)
    {
        int parent = getParent(position);

        while (v[parent] < v[position])
        {
            swapElements(v[parent], v[position]);

            if (parent <= 0)
            {
                return;
            }

            parent = getParent(parent);
            position = getParent(position);
        }
    }

    void siftDown(int position)
    {
        bool hasLeft = getLeft(position) < v.size();
        bool hasRight = getRight(position) < v.size();

        if (hasRight && (v[position] < v[getLeft(position)] || v[position] < v[getRight(position)]))
        {
            int swapWith = v[getLeft(position)] < v[getRight(position)]?getRight(position):getLeft(position);

            swapElements(v[position], v[swapWith]);

            siftDown(swapWith);
        }
        else
        {
            if (hasLeft && v[position] < v[getLeft(position)])
            {
                swapElements(v[position], v[getLeft(position)]);

                siftDown(getLeft(position));
            }
        }
    }

public:
    bool isEmpty()
    {
        return v.size()==0;
    }

    void add(double value)
    {
        v.push_back(value);
        if (!isEmpty())
        {
            siftUp(v.size()-1);
        }
    }

    void popTop()
    {
        if (isEmpty())
        {
            return;
        }
        swapElements(v[0], v[v.size()-1]);
        v.pop_back();
        siftDown(0);
    }

    double median()
    {
        if(v.size()%2 != 0)
        {
            return v[(v.size()-1)/2];
        }
        return (v[(v.size())/2-1]+v[(v.size())/2])/2;
    }

    double peek()
    {
        return v[0];
    }

    long len_maxi()
    {
        return v.size();
    }
};

class Min_Heap
{
    vector<double> mini;

    int getParent(int position)
    {
        return (position-1)/2;
    }
    int getLeft(int position)
    {
        return 2*position+1;
    }
    int getRight(int position)
    {
        return 2*position+2;
    }

    void siftUp(int position)
    {
        int parent = getParent(position);

        while (mini[parent] > mini[position])
        {
            swapElements(mini[parent], mini[position]);

            if (parent <= 0)
            {
                return;
            }

            parent = getParent(parent);
            position = getParent(position);
        }
    }

    void siftDown(int position)
    {
        bool hasLeft = getLeft(position) < mini.size();
        bool hasRight = getRight(position) < mini.size();

        if (hasRight && (mini[position] > mini[getLeft(position)] || mini[position] > mini[getRight(position)]))
        {
            int swapWith = mini[getLeft(position)] < mini[getRight(position)] ? getLeft(position):getRight(position);
            swapElements(mini[position], mini[swapWith]);
            siftDown(swapWith);
        }
        else
        {
            if (hasLeft && mini[position] > mini[getLeft(position)])
            {
                swapElements(mini[position], mini[getLeft(position)]);
                siftDown(getLeft(position));
            }
        }
    }

public:
    bool isEmpty()
    {
        return mini.size() == 0;
    }

    void add(double value)
    {
        mini.push_back(value);
        if (!isEmpty())
        {
            siftUp(mini.size()-1);
        }
    }

    void popTop()
    {
        if (isEmpty())
        {
            return;
        }
        swapElements(mini[0], mini[mini.size()-1]);
        mini.pop_back();
        siftDown(0);
    }

    double peek()
    {
        return mini[0];
    }

    long len_mini()
    {
        return mini.size();
    }
};

void getMedian(double arr[], long N)
{
    Max_Heap maxi;
    Min_Heap mini;

    double median = arr[0];
    maxi.add(arr[0]);

    printf("%.1f \n", median);

    for (long i = 1; i < N; i++)
    {
        double number = arr[i];

        if (maxi.len_maxi() > mini.len_mini())
        {
            if (number < median)
            {
                mini.add(maxi.peek());
                maxi.popTop();
                maxi.add(number);
            }
            else
            {
                mini.add(number);
            }
            median = (maxi.peek() + mini.peek())/2;
        }

        else
        {
            if (maxi.len_maxi() == mini.len_mini())
            {
                if (number < median)
                {
                    maxi.add(number);
                    median = (double)maxi.peek();
                }
                else
                {
                    mini.add(number);
                    median = (double)mini.peek();
                }
            }
            else
            {
                if (number > median)
                {
                    maxi.add(mini.peek());
                    mini.popTop();
                    mini.add(number);
                }
                else
                {
                    maxi.add(number);
                }
                median = (maxi.peek() + mini.peek())/2;
            }
        }

        printf("%.1f \n", median);
    }
}

int main()
{
    long N;
    cin >> N;

    double* arr = new double[N];

    for (long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    getMedian(arr, N);

    delete[] arr;

    return 0;
}
