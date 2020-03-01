#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Pair
{
    int index;
    int distance;

    bool operator<(const Pair& p) const
    {
        return p.distance < distance;
    }
};

struct Node
{
    list<Pair> neighbours;

    bool hasNeighbour(int index)
    {
        for (auto element: neighbours)
        {
            if (element.index == index)
            {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(int index, int distance)
    {
        Pair newNeighbour;
        newNeighbour.index = index;
        newNeighbour.distance = distance;
        neighbours.push_back(newNeighbour);
    }
};

struct compare
{
    bool operator()(const Pair& a, const Pair& b)
    {
        return a.distance > b.distance;
    }
};

class Graph
{
    vector<Node> adj;

public:
    Graph(int length)
    {
        adj.resize(length);
    }

    void connect(int from, int to, int distance)
    {
        adj[from].addNeighbour(to, distance);
        adj[to].addNeighbour(from, distance);
    }

    void shortPath(vector<int>& disco, vector<int>& answer)
    {
        if (adj.size() < 1)
        {
            return;
        }

        vector<int> parent(adj.size(), -1);
        vector<int> distance(adj.size(), INT_MAX);
        vector<bool> visited(adj.size(), false);

        priority_queue<Pair, vector<Pair>, compare> nextDist;
        for (int i = 0; i < disco.size(); i++)
        {
            distance[disco[i]] = 0;
            nextDist.push({disco[i], 0});
        }

        while(!nextDist.empty())
        {
            Pair currentNode = nextDist.top();
            nextDist.pop();
            int currentIndex = currentNode.index;
            int currentDistance = distance[currentIndex];

            if (visited[currentIndex] == true)
            {
                continue;
            }

            visited[currentIndex] = true;
            for (auto element: adj[currentIndex].neighbours)
            {
                int newDistance = currentDistance+element.distance;
                if (newDistance < distance[element.index])
                {
                    distance[element.index] = newDistance;
                    parent[element.index] = currentIndex;
                    nextDist.push({element.index, newDistance});
                    if (distance[element.index] < answer[element.index])
                    {
                        answer[element.index] = distance[element.index];
                    }
                }
            }
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int M;
    cin >> N;
    cin >> M;

    Graph g(N);

    int from;
    int to;
    int distance;

    for (int i = 0; i < M; i++)
    {
        cin >> from;
        cin >> to;
        cin >> distance;
        g.connect(from, to, distance);
    }

    int K;
    cin >> K;

    vector<int> disco;
    vector<int> blocks;

    vector<bool> visited(N, false);

    int object;

    for (int i = 0; i < K; i++)
    {
        cin >> object;
        disco.push_back(object);
        visited[object] = true;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false)
        {
            blocks.push_back(i);
        }
    }

    vector<int> answer(N, INT_MAX);

    g.shortPath(disco, answer);

    int Q;
    cin >> Q;
    int query;
    vector<int> queries;

    for (int i = 0; i < Q; i++)
    {
        cin >> query;
        queries.push_back(query);
    }

    for (int i = 0; i < queries.size(); i++)
    {
       cout << answer[queries[i]] << endl;
    }

    return 0;
}
