#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class MinHeap
{
    vector<int> v;

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

        while (v[position] < v[parent])
        {
            swap(v[position], v[parent]);

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

        if (hasRight && (v[getLeft(position)] < v[position] || v[getRight(position)] < v[position]))
        {
            int swapWith;
            if (v[getLeft(position)] < v[getRight(position)])
            {
                swapWith = getLeft(position);
            }
            else
            {
                swapWith = getRight(position);
            }
            swap(v[position], v[swapWith]);
            siftDown(swapWith);
        }
        else
        {
            if (hasLeft && v[getLeft(position)] < v[position])
            {
                int swapWith;
                swapWith = getLeft(position);
                swap(v[position], v[swapWith]);
                siftDown(swapWith);
            }
        }
    }

public:
    bool isEmpty()
    {
        return v.size() == 0;
    }

    void add(int element)
    {
        v.push_back(element);
        siftUp(v.size()-1);
    }

    void pop()
    {
        if (!isEmpty())
        {
            swap(v[0], v[v.size()-1]);
            v.pop_back();
            siftDown(0);
        }
        else
        {
            return;
        }
    }

    int peek() const
    {
        return v[0];
    }
};

class MaxHeap
{
    vector<int> v;

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

        while (v[position] > v[parent])
        {
            swap(v[position], v[parent]);

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

        if (hasRight && (v[getLeft(position)] > v[position] || v[getRight(position)] > v[position]))
        {
            int swapWith;
            if (v[getLeft(position)] > v[getRight(position)])
            {
                swapWith = getLeft(position);
            }
            else
            {
                swapWith = getRight(position);
            }
            swap(v[position], v[swapWith]);
            siftDown(swapWith);
        }
        else
        {
            if (hasLeft && v[getLeft(position)] > v[position])
            {
                int swapWith;
                swapWith = getLeft(position);
                swap(v[position], v[swapWith]);
                siftDown(swapWith);
            }
        }
    }

public:
    bool isEmpty()
    {
        return v.size()==0;
    }
    void add(int element)
    {
        v.push_back(element);
        siftUp(v.size()-1);
    }
    void pop()
    {
        if (!isEmpty())
        {
            swap(v[0], v[v.size()-1]);
            v.pop_back();
            siftDown(0);
        }
        else
        {
            return;
        }
    }
    int peek()
    {
        return v[0];
    }
};

int main()
{
    MaxHeap m;
    m.add(10);
    m.add(1);
    m.add(8);
    m.add(11);
    m.add(7);
    m.add(0);

    while (!m.isEmpty())
    {
        cout << m.peek() << " ";
        m.pop();
    }

    return 0;
}
