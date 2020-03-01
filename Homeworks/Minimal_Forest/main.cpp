#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
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

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator<(const Edge& e)
    {
        return weight < e.weight;
    }
};

class Graph
{
private:
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

    vector<Edge> getAllEdges()
    {
        vector<Edge> edges;

        for (int i = 0; i < adj.size(); i++)
        {
            for (auto element: adj[i].neighbours)
            {
                if (i < element.to)
                {
                    edges.push_back({i, element.to, element.weight});
                }
            }
        }

        return edges;
    }

    int MST_value()
    {
        int answer = 0;

        vector<Edge> all = getAllEdges();
        sort(all.begin(), all.end());

        vector<int> components(adj.size());

        for (int i = 0; i < components.size(); i++)
        {
            components[i] = i;
        }

        for (int i = 0; i < all.size(); i++)
        {
            if (components[all[i].from] != components[all[i].to])
            {
                answer+=all[i].weight;

                int old = components[all[i].from];
                int now = components[all[i].to];

                for (int i = 0; i < components.size(); i++)
                {
                    if (components[i] == now)
                    {
                        components[i] = old;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
    int N;
    int M;
    cin >> N;
    cin >> M;

    Graph g(N);

    int A;
    int B;
    int W;

    for (int i = 0; i < M; i++)
    {
        cin >> A;
        cin >> B;
        cin >> W;
        g.connect(A, B, W);
    }

    cout << g.MST_value();

    return 0;
}
