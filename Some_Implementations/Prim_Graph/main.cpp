#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int minimal = 0;

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator<(const Edge& e) const
    {
        return e.weight < weight;
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

    list<Edge> MST(int start)
    {
        if (adj.size() < 1)
        {
            return list<Edge>();
        }

        vector<bool> visited(adj.size(), false);

        priority_queue<Edge> q;
        q.push({-1, start, 0});

        list<Edge> answer;

        while (!q.empty())
        {
            Edge current = q.top();
            q.pop();

            int parent = current.from;
            int currentTo = current.to;
            int currentWeight = current.weight;

            if (visited[currentTo] == true)
            {
                continue;
            }

            visited[currentTo] = true;

            if (parent != -1)
            {
                answer.push_back({parent, currentTo, currentWeight});
                minimal+=currentWeight;
            }

            for (auto element: adj[currentTo].neighbours)
            {
                q.push({currentTo, element.to, element.weight});
            }
        }

        return answer;
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

    //g.print();
    //cout << endl;
    list<Edge> answer = g.MST(1);
    for (auto element: answer)
    {
        cout << element.from << " " << element.to << " " << element.weight << endl;
    }
    cout << minimal;

    return 0;
}
