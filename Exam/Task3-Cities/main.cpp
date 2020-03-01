#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int cnt = 0;

struct Node
{
    list<int> neighbours;

    void addNeighbour(int to)
    {
        neighbours.push_back(to);
    }
};

class Graph
{
    vector<Node> adj;

    void _DFS(int start, vector<bool>& visited)
    {
        visited[start] = true;

        for (auto element: adj[start].neighbours)
        {
            if (visited[element] == false)
            {
                _DFS(element, visited);
            }
        }
    }

public:
    Graph(int length)
    {
        adj.resize(length);
    }

    void connect(int from, int to)
    {
        adj[from].addNeighbour(to);
        adj[to].addNeighbour(from);
    }

    void components()
    {
        vector<bool> visited;
        visited.resize(N, false);

        for(int i = 0; i < N; i++)
        {
            if (visited[i] == false)
            {
                _DFS(i, visited);
                cnt++;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cin >> M;

        if (M == 0)
        {
            cout << N;
            return 0;
        }

        if (M == 1)
        {
            cout << N-M;
            return 0;
        }

        int first;
        int second;

        vector<bool> view;
        view.resize(N, false);

        Graph g(N);

        vector<int> help;

        for (int i = 0; i < M; i++)
        {
            cin >> first;
            cin >> second;
            g.connect(first, second);
        }

        g.components();

        cout << cnt << " ";
        cnt = 0;
    }

    return 0;
}
