#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Pair
{
    int index;
    int weight;

    bool operator<(const Pair& e) const
    {
        return e.weight < weight;
    }
};

struct Node
{
    list<Pair> neighbours;

    void addNeighbour(int index, int weight)
    {
        neighbours.push_back(Pair{index, weight});
    }
};

class Graph
{
    vector<Node> adj;

public:
    Graph(int length)
    {
        adj.resize(length+1);
    }

    void connect(int from, int to, int weight)
    {
        adj[from].addNeighbour(to, weight);
        adj[to].addNeighbour(from, weight);
    }

    void shortPath(int start, vector<int>& answer)
    {
        vector<int> parent(adj.size(), -1);
        vector<int> distance(adj.size(), INT_MAX);
        vector<bool> visited(adj.size(), false);

        priority_queue<Pair> q;
        q.push({start, 0});
        distance[start] = 0;

        while (!q.empty())
        {
            Pair currentNode = q.top();
            q.pop();

            int current = currentNode.index;
            int weight = currentNode.weight;

            if (visited[current] == true)
            {
                continue;
            }

            visited[current] = true;

            for (auto element: adj[current].neighbours)
            {
                int newWeight = element.weight+weight;

                if (newWeight < distance[element.index])
                {
                    distance[element.index] = newWeight;
                    parent[element.index] = current;
                    q.push({element.index, newWeight});

                    if (newWeight < answer[element.index])
                    {
                        answer[element.index] = newWeight;
                    }
                }
            }
        }
    }
};

int main() {
    int N;
    int M;
    cin >> N;
    cin >> M;

    Graph g(N);

    vector<int> answer(N+1, INT_MAX);

    int from;
    int to;
    int weight;

    for (int i = 0; i < M; i++)
    {
        cin >> from;
        cin >> to;
        cin >> weight;

        g.connect(from, to, weight);
    }

    int start;
    cin >> start;

    g.shortPath(start, answer);

    for (int i = 1; i < answer.size(); i++)
    {
        if (i != start)
        {
            if (answer[i] == INT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << answer[i] << " ";
            }
        }
    }

    return 0;
}
