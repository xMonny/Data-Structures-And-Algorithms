#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

struct Triple
{
    int value;
    int kilograms;
    int seconds;

    bool operator<(const Triple& t) const
    {
        return t.kilograms < this->kilograms;
    }
};

struct Node
{
    list<Triple> neighbours;

    void addNeighbour(int value, int kilograms, int seconds)
    {
        neighbours.push_back(Triple{value, kilograms, seconds});
    }
};

int getSeconds(int secondsOne, int secondsTwo)
{
    return secondsOne+secondsTwo;
}

struct compare
{
    bool operator()(const Triple& a, const Triple& b)
    {
        return a.kilograms > b.kilograms;
    }
};

class Graph
{
private:
    vector<Node> adj;

public:
    Graph(int length)
    {
        adj.resize(length+1);
    }

    void connect(int from, int to, int kilograms, int seconds)
    {
        adj[from].addNeighbour(to, kilograms, seconds);
    }

    int getMinimalWeight(const int N, const int K)
    {
        if (adj.size() < 1)
        {
            return 0;
        }

        vector<bool> visited(adj.size(), false);
        vector<int> weight(adj.size(), INT_MAX);
        vector<int> time(adj.size(), INT_MAX);

        priority_queue<Triple, vector<Triple>, compare> nextDist;

        nextDist.push({1, 0, 0});

        while(!nextDist.empty())
        {
            Triple current = nextDist.top();
            nextDist.pop();
            int currentTop = current.value;
            int currentKilograms = current.kilograms;
            int currentSeconds = current.seconds;

            if (visited[currentTop] == true)
            {
                if (currentSeconds >= time[currentTop])
                {
                    continue;
                }
            }

            visited[currentTop] = true;

            for (auto element: adj[currentTop].neighbours)
            {
                int calculatedSeconds = getSeconds(currentSeconds, element.seconds);
                if (calculatedSeconds <= K)
                {
                    int calculatedKilograms;
                    if (element.kilograms > currentKilograms)
                    {
                        calculatedKilograms = element.kilograms;
                    }
                    else
                    {
                        calculatedKilograms = currentKilograms;
                    }
                    if (calculatedKilograms < weight[element.value])
                    {
                        weight[element.value] = calculatedKilograms;
                    }
                    nextDist.push({element.value, calculatedKilograms, calculatedSeconds});
                }
            }
            time[currentTop] = currentSeconds;
        }

        if (weight[N] != INT_MAX)
        {
            return weight[N];
        }
        else
        {
            return -1;
        }
    }
};


int main() {
    int N;
    int M;
    int K;
    cin >> N;
    cin >> M;
    cin >> K;

    Graph g(N);

    int from;
    int to;
    int kilograms;
    int seconds;

    for (int i = 0; i < M; i++)
    {
        cin >> from;
        cin >> to;
        cin >> kilograms;
        cin >> seconds;

        g.connect(from, to, kilograms, seconds);
    }

    cout << g.getMinimalWeight(N, K);

    return 0;
}
