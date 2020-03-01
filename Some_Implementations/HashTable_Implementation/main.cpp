#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class HashTable
{
    const int CONST_SIZE = 10;
    int itemCount = 0;

    vector<list<int>> v;

    int hashFunction(int value, int length) const
    {
        return value%length;
    }

    double calculateLoadFactor() const
    {
        return double(itemCount)/v.size();
    }

    bool findIn(int index, int value) const
    {
        return find(v[index].begin(), v[index].end(), value) != v[index].end();
    }

    bool isGrowNeeded()
    {
        double loadFactor = calculateLoadFactor();
        return loadFactor > 0.65;
    }

    void growTable()
    {
        vector<list<int>> help(v.size()*2);
        int index = 0;

        for (auto element: v)
        {
            for (auto in: element)
            {
                index = hashFunction(in, help.size());
                help[index].push_back(in);
            }
        }

        v = help;
    }

    bool isSmallNeeded()
    {
        double loadFactor = calculateLoadFactor();
        return loadFactor < 0.3 && v.size() > 10;
    }

    void smallTable()
    {
        vector<list<int>> help(v.size()/2);
        int index = 0;

        for (auto element: v)
        {
            for (auto in: element)
            {
                index = hashFunction(in, help.size());
                help[index].push_back(in);
            }
        }

        v = help;
    }

public:
    HashTable()
    {
        v.resize(CONST_SIZE);
    }

    void add(int value)
    {
        int index = hashFunction(value, v.size());

        if (!findIn(index, value))
        {
            v[index].push_back(value);

            itemCount++;

            if (isGrowNeeded())
            {
                growTable();
            }
        }
    }

    void removeElement(int value)
    {
        int index = hashFunction(value, v.size());
        int oldListSize = v[index].size();

        if (findIn(index, value))
        {
            v[index].remove(value);

            if (v[index].size() != oldListSize)
            {
                itemCount--;
            }

            if (isSmallNeeded())
            {
                smallTable();
            }
        }
    }

    void print() const
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << i << ": ";
            for (auto in: v[i])
            {
                cout << in << "->";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable h;
    h.add(1);
    h.add(5);
    h.add(8);
    h.add(3);
    h.add(13);
    h.add(23);
    h.add(33);

    h.removeElement(33);
    h.removeElement(5);
    //h.add(0);
    //h.add(2);
    //h.add(4);
    //h.add(6);
    //h.add(7);

    h.print();

    return 0;
}
