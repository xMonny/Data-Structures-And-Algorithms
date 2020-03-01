#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

double calculateDistance(long x, long y)
{
    return sqrt(x*x + y*y);
}

void swapDistance(pair<long, long>& one, pair<long, long>& two)
{
    pair<long, long> temp;

    temp.first = one.first;
    temp.second = one.second;

    one.first = two.first;
    one.second = two.second;

    two.first = temp.first;
    two.second = temp.second;
}

bool operator<(const pair<long, long>& one, const pair<long, long>& two)
{
    double distanceOne = calculateDistance(one.first, one.second);
    double distanceTwo = calculateDistance(two.first, two.second);

    if (distanceOne < distanceTwo)
    {
        return true;
    }
    else
    {
        if (distanceOne == distanceTwo)
        {
            if (one.first < two.first)
            {
                return true;
            }
            if (one.first == two.first)
            {
                if (one.second < two.second)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (one.first > two.first)
            {
                return false;
            }
        }
        if (distanceOne > distanceTwo)
        {
            return false;
        }
    }
    return true;
}

int K;
int cnt = 0;

class Max_Heap
{
private:
    vector<pair<long, long>> v;

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

        while (v[parent] < v[position])
        {
            swapDistance(v[position], v[parent]);

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

            swapDistance(v[position], v[swapWith]);
            siftDown(swapWith);
        }
        else
        {
            if (hasLeft && v[position] < v[getLeft(position)])
            {
                swapDistance(v[position], v[getLeft(position)]);
                siftDown(getLeft(position));
            }
        }
    }

public:
    bool isEmpty()
    {
        return v.size()==0;
    }
    void add(long x, long y)
    {
        v.push_back(make_pair(x,y));
        cnt++;
        if (!isEmpty())
        {
            if (cnt > K)
            {
                if (calculateDistance(v[v.size()-1].first, v[v.size()-1].second) < calculateDistance(v[0].first, v[0].second))
                {
                    popTop();
                }
                else
                {
                    v.pop_back();
                }
                cnt = K;
            }
            else
            {
                siftUp(v.size()-1);
            }
        }
    }
    void popTop()
    {
        if (isEmpty())
        {
            return;
        }
        swapDistance(v[0], v[v.size()-1]);
        v.pop_back();
        siftDown(0);
    }
    pair<long, long> peek()
    {
        return v[0];
    }
};

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr);

    long N;
    cin >> N >> K;

    long x;
    long y;

    Max_Heap h;

    int cnt = 0;

    vector<pair<long, long>> help;

    for (long i = 0; i < N; i++)
    {
        cin >> x >> y;
        h.add(x,y);
    }

    while (!h.isEmpty())
    {
        help.push_back(make_pair(h.peek().first, h.peek().second));
        h.popTop();
    }

    for (int i = K-1; i >= 0; i--)
    {
        cout << help[i].first << " " << help[i].second << endl;
    }

    return 0;
}
