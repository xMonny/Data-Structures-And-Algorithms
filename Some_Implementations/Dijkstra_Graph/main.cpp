#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

struct Pair
{
    int to;
    int weight;

    bool operator<(const Pair& p) const
    {
        return p.weight < weight;
    }
};

struct Node
{
    list<Pair> neighbours;

    void addNeighbour(int value, int weight)
    {
        neighbours.push_back(Pair{value, weight});
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

    void shortPath(int start, int endd, vector<int>& answer)
    {
        vector<bool> visited(adj.size(), false);
        vector<int> distance(adj.size(), INT_MAX);
        vector<int> parent(adj.size(), -1);

        priority_queue<Pair> q;
        q.push({start, 0});
        distance[start] = 0;

        while (!q.empty())
        {
            Pair currentNode = q.top();
            q.pop();

            int currentTo = currentNode.to;
            int currentWeight = currentNode.weight;

            if (visited[currentTo] == true)
            {
                continue;
            }

            visited[currentTo] = true;

            for (auto element: adj[currentTo].neighbours)
            {
                int newWeight = currentWeight+element.weight;
                if (newWeight < distance[element.to])
                {
                    distance[element.to] = newWeight;
                    parent[element.to] = currentTo;
                    q.push({element.to, newWeight});
                }
                if (newWeight < answer[element.to])
                {
                    answer[element.to] = newWeight;
                }
            }
        }

        int index = endd;
        stack<int> s;
        while (parent[index] != -1)
        {
            s.push(index);
            index = parent[index];
        }
        s.push(index);

        cout << "Path from " << start << " to " << endd << " is: ";
        while (!s.empty())
        {
            cout << s.top() << " - ";
            s.pop();
        }
        cout << " = " << answer[endd];
    }
};

int main()
{
    Graph g(4);
    g.connect(1, 3, 2);
    g.connect(1, 2, 4);
    g.connect(3, 2, 1);
    g.connect(2, 4, 5);
    g.connect(3, 4, 2);

    vector<int> answer(5, INT_MAX);

    g.shortPath(1, 4, answer);

    /*for (int i = 2; i <= 4; i++)
    {
        cout << "1-" << i << ": " << answer[i] << endl;
    }*/

    return 0;
}
