#include <iostream>
#include <vector>

using namespace std;

void swapElements(long& a, long& b)
{
    long temp = a;
    a = b;
    b = temp;
}

class Min_Heap
{
    vector<long> v;

    long getParent(long position)
    {
        return (position-1)/2;
    }

    long getLeft(long position)
    {
        return 2*position+1;
    }

    long getRight(long position)
    {
        return 2*position+2;
    }

    void siftUp(long position)
    {
        long parent = getParent(position);

        while (v[parent] > v[position])
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

    void siftDown(long position)
    {
        bool hasLeft = getLeft(position) < v.size();
        bool hasRight = getRight(position) < v.size();

        if (hasRight && (v[position] > v[getLeft(position)] || v[position] > v[getRight(position)]))
        {
            long index = v[getLeft(position)] < v[getRight(position)]?getLeft(position):getRight(position);

            swapElements(v[position], v[index]);
            siftDown(index);
        }
        else
        {
            if (hasLeft && v[position] > v[getLeft(position)])
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

    void add(long value)
    {
        v.push_back(value);

        if (!v.empty())
        {
            siftUp(v.size()-1);
        }
    }

    void popTop()
    {
        if (!v.empty())
        {
            swapElements(v[0], v[v.size()-1]);
            v.pop_back();
            siftDown(0);
        }
    }

    long peek()
    {
        return v[0];
    }
};


int main() {
    long N;
    cin >> N;
    long number;

    Min_Heap h;

    for (long i = 0; i < N; i++)
    {
        cin >> number;
        if (number == -1 && h.isEmpty() == true)
        {

        }
        else
        {
            if (number != -1)
            {
                h.add(number);
            }
            if (number == -1)
            {
                cout << h.peek() << " ";
                h.popTop();
            }
        }

    }

    return 0;
}
