#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> answer;
list<int> cities;
int check = 0;

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

    void _BFS(int value, int search, vector<bool>& visited)
    {
        visited[value] = true;
        queue<int> next;
        next.push(value);
        answer.push_back(0);

        int pos = 0;

        while(!next.empty())
        {
            int current = next.front();
            if (answer[pos] == search)
            {
                cities.push_back(current);
                check++;
            }
            next.pop();

            for(auto element: adj[current].neighbours)
            {
                if (visited[element] == false)
                {
                    visited[element] = true;
                    next.push(element);
                    answer.push_back(answer[pos]+1);
                }
            }
            pos++;
        }
    }

public:
    Graph(int length)
    {
        adj.resize(length);
    }

    void connect(int from, int to)
    {
        if(adj[from].hasNeighbour(to) == false)
        {
            adj[from].addNeighbour(to);
            adj[to].addNeighbour(from);
        }
    }

    void BFS(int value, int search)
    {
        vector<bool> visited;
        visited.resize(adj.size(), false);

        _BFS(value, search, visited);
    }
};


int main() {
    int N;
    int M;
    int K;

    cin >> N;
    cin >> M;
    cin >> K;

    int first;
    int second;

    Graph g(N+1);

    for (int i = 0; i < M; i++)
    {
        cin >> first >> second;
        g.connect(first, second);
    }

    g.BFS(N, K);

    if (check == 0)
    {
        cout << "-1";
    }
    else
    {
        cities.sort();
        for (auto element: cities)
        {
            cout << element << " ";
        }
    }

    return 0;
}
