#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair
{
    int to;
    int weight;
};

struct Node
{
    list<Pair> neighbours;

    void addNeighbour(int to, int weight)
    {
        neighbours.push_back(Pair{to, weight});
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

    void connect(int from, int to, int weight)
    {
        adj[from].addNeighbour(to, weight);
        adj[to].addNeighbour(from, weight);
    }

    int checkPath(vector<int>& path)
    {
        int sum = 0;

        int cnt = 0;

        queue<Pair> q;
        q.push({path[0], 0});

        int position = 1;

        int check = 0;
        cnt = 1;

        while (!q.empty())
        {
            Pair currentNode = q.front();
            q.pop();

            int current = currentNode.to;
            int currentWeight = currentNode.weight;

            for (auto element: adj[current].neighbours)
            {
                if (element.to == path[position])
                {
                    int newWeight = currentWeight+element.weight;
                    if (element.to == path[path.size()-1])
                    {
                        check++;
                        sum = newWeight;
                        break;
                    }
                    q.push({element.to, newWeight});
                    position++;
                    break;
                }
            }
            if (check > 0)
            {
                break;
            }
        }

        if (check > 0)
        {
            return sum;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int N;
    int M;
    cin >> N;
    cin >> M;

    Graph g(N);

    int from, to, weight;

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> weight;

        g.connect(from, to, weight);
    }

    int K;
    cin >> K;
    vector<int> path;
    int destination;
    for (int i = 0; i < K; i++)
    {
        cin >> destination;
        path.push_back(destination);
    }

    cout << g.checkPath(path);

    return 0;
}
