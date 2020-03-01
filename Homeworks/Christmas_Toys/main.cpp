#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int cnt = 0;
int seen = 0;
int maximum = 0;

vector<int> help;

class Graph
{
    map<int, map<int, int>> adj;

    void _DFS(int start, vector<bool>& visited)
    {
        visited[start] = true;
        seen++;

        for (auto element: adj[start])
        {
            if (adj[start][element.first] == 1 && visited[element.first] == false)
            {
                _DFS(element.first, visited);
            }
        }
    }

public:
    void connect(int from, int to)
    {
        adj[from][to] = 1;
        adj[to][from] = 1;
    }

    void components()
    {
        vector<bool> visited;
        visited.resize(maximum+1, false);

        for(int i = 0; i < help.size(); i++)
        {
            if (visited[help[i]] == false)
            {
                _DFS(help[i], visited);
                cnt++;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    view.resize(N+1, false);

    Graph g;

    for (int i = 0; i < M; i++)
    {
        cin >> first;
        if (first >= maximum)
        {
            maximum = first;
        }
        cin >> second;
        if (second >= maximum)
        {
            maximum = second;
        }
        if (view[first] == false)
        {
            view[first] = true;
            help.push_back(first);
        }
        if (view[second] == false)
        {
            view[second] = true;
            help.push_back(second);
        }

        g.connect(first, second);
    }

    g.components();

    cnt+=N-seen;
    cout << cnt;

    return 0;
}
