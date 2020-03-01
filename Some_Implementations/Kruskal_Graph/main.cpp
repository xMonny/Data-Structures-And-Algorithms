#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int minimal = 0;

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator<(const Edge& e) const
    {
        return weight < e.weight;
    }
};

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
        adj.resize(length+1);
    }
    void connect(int from, int to, int weight)
    {
        adj[from].addNeighbour(to, weight);
        adj[to].addNeighbour(from, weight);
    }

    vector<Edge> getAllEdges() const
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

    list<Edge> MST()
    {
        if (adj.size() < 1)
        {
            return list<Edge>();
        }

        vector<Edge> edges = getAllEdges();
        sort(edges.begin(), edges.end());

        vector<int> components(adj.size());
        for (int i = 0; i < components.size(); i++)
        {
            components[i] = i;
        }

        list<Edge> answer;

        for (int i = 0; i < edges.size(); i++)
        {
            int from = edges[i].from;
            int to = edges[i].to;
            int weight = edges[i].weight;

            if (components[from] != components[to])
            {
                int now = components[from];
                int old = components[to];
                answer.push_back(edges[i]);
                minimal+=weight;
                for (int j = 0; j < components.size(); j++)
                {
                    if (components[j] == old)
                    {
                        components[j] = now;
                    }
                }
            }
        }

        return answer;
    }

    void print()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << ": ";
            for (auto element: adj[i].neighbours)
            {
                cout << " (" << element.to << "; " << element.weight << "), ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.connect(1, 3, 2);
    g.connect(2, 4, 5);
    g.connect(1, 2, 4);
    g.connect(3, 4, 2);
    g.connect(3, 2, 1);

    g.print();
    cout << endl;
    list<Edge> answer = g.MST();
    for (auto element: answer)
    {
        cout << element.from << " " << element.to << " " << element.weight << endl;
    }

    cout << minimal;

    return 0;
}
