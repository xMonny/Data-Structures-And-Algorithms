#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
    int* v;
    int length;
    int capacity;

    void doubleSize()
    {
        capacity *= 2;
        int* help = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            help[i] = v[i];
        }

        delete[] v;

        v = help;
    }

    void smallSize()
    {
        capacity /= 2;

        int* help = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            help[i] = v[i];
        }
        delete[] v;
        v = help;
    }

public:
    Vector()
    {
        length = 0;
        capacity = 10;
        v = new int[capacity];
    }

    Vector& operator=(const Vector& help)
    {
        if (this != &help)
        {
            delete[] v;

            length = help.length;
            capacity = help.capacity;

            v = new int[capacity];

            for (int i = 0; i < length; i++)
            {
                v[i] = help.v[i];
            }
        }
        return *this;
    }

    Vector(const Vector &help)
    {
        length = help.length;
        capacity = help.capacity;

        v = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            v[i] = help.v[i];
        }
    }

    ~Vector()
    {
        delete[] v;
    }

    void add(int element)
    {
        if (length == capacity)
        {
            doubleSize();
        }
        v[length] = element;
        length++;
    }

    void addAt(int element, int index)
    {
        if (index >= 0 && index <= length)
        {
            if (length == capacity)
            {
                doubleSize();
            }
            if (index == length)
            {
                add(element);
            }
            else
            {
                for (int i = length-1; i >= index; i--)
                {
                    v[i+1] = v[i];
                }
                v[index] = element;
                length++;
            }
        }
    }

    void pop()
    {
        if (length > 0)
        {
            if (length == capacity/2 && capacity > 10)
            {
                smallSize();
            }
            length--;
        }
    }

    void removeAt(int index)
    {
        if (index >= 0 && index < length)
        {
            if (length == capacity/2 && capacity > 10)
            {
                smallSize();
            }
            for (int i = index; i < length-1; i++)
            {
                v[i] = v[i+1];
            }
            length--;
        }
    }

    void replaceAt(int element, int index)
    {
        if (index >= 0 && index < length)
        {
            v[index] = element;
        }
    }

    void countingSort()
    {
        int minimal = 0;
        int maximal = 0;

        for (int i = 0; i < length; i++)
        {
            if (i == 0)
            {
                minimal = v[i];
                maximal = v[i];
            }
            else
            {
                if (v[i] < minimal)
                {
                    minimal = v[i];
                }
                if (v[i] > maximal)
                {
                    maximal = v[i];
                }
            }
        }

        int range = maximal-minimal+1;

        int* number = new int[range];
        for (int i = 0; i < range; i++)
        {
            number[i] = 0;
        }

        int position = 0;
        for (int i = 0; i < length; i++)
        {
            position = abs(v[i]-minimal);
            number[position]++;
        }

        for (int i = 1; i < range; i++)
        {
            number[i] += number[i-1];
        }

        int* finish = new int[length];
        int secondPosition = 0;

        for (int i = 0; i < length; i++)
        {
            position = abs(v[i]-minimal);
            secondPosition = number[position]-1;
            number[position]--;
            finish[secondPosition] = v[i];
        }

        for (int i = 0; i < length; i++)
        {
            v[i] = finish[i];
        }

        delete[] number;
        delete[] finish;
    }

    void print() const
    {
        for (int i = 0; i < length; i++)
        {
            cout << v[i] << " ";
        }
    }

    int getSize() const
    {
        return length;
    }
    int getCapacity() const
    {
        return capacity;
    }
};

int main()
{
    Vector v;
    v.add(-1);
    v.add(5);
    v.add(0);
    v.add(10);
    v.addAt(2, 0);
    v.pop();
    v.removeAt(4);
    v.replaceAt(-100, 2);

    v.print();

    cout << endl << "length: " << v.getSize() << " capacity: " << v.getCapacity();

    v.countingSort();
    cout << endl;
    v.print();

    Vector second(v);
    //second = v;
    cout << endl;
    second.print();

    return 0;
}
