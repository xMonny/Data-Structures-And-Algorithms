#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>

using namespace std;

struct Node
{
    list<int> neighbours;

    bool hasNeighbour(int value)
    {
        for (auto element: neighbours)
        {
            if (element == value)
            {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(int value)
    {
        neighbours.push_back(value);
    }
};

class Graph
{
    vector<Node> adj;

    void _DFS(int start, vector<bool>& visited)
    {
        visited[start] = true;
        cout << start << " ";

        for (auto element: adj[start].neighbours)
        {
            if (visited[element] == false)
            {
                _DFS(element, visited);
            }
        }
    }

    void _DFSStack(int start, vector<bool>& visited)
    {
        stack<int> s;
        s.push(start);

        while (!s.empty())
        {
            int current = s.top();

            if (visited[current] == true)
            {
                s.pop();
                continue;
            }

            cout << current << " ";

            visited[current] = true;

            for (auto element: adj[current].neighbours)
            {
                s.push(element);
            }
        }
    }

    void _BFS(int start, vector<bool>& visited)
    {
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            if (visited[current] == true)
            {
                continue;
            }

            cout << current << " ";

            visited[current] = true;

            for (auto element: adj[current].neighbours)
            {
                if (visited[element] == false)
                {
                    q.push(element);
                }
            }
        }
    }

public:
    Graph(int length)
    {
        adj.resize(length+1);
    }

    void connect(int from, int to)
    {
        if (adj[from].hasNeighbour(to) == false)
        {
            adj[from].addNeighbour(to);
            adj[to].addNeighbour(from);
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(adj.size(), false);

        _DFS(start, visited);
    }

    void DFSStack(int start)
    {
        vector<bool> visited(adj.size(), false);

        _DFSStack(start, visited);
    }

    void BFS(int start)
    {
        vector<bool> visited(adj.size(), false);

        _BFS(start, visited);
    }

    void print()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << ": ";
            for (auto element: adj[i].neighbours)
            {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.connect(1, 2);
    g.connect(1 ,3);
    g.connect(3, 5);
    g.connect(4, 5);
    g.connect(2, 4);

    g.print();

    g.DFS(1);
    cout << endl;
    g.BFS(1);
    cout << endl;
    g.DFSStack(1);

    return 0;
}
