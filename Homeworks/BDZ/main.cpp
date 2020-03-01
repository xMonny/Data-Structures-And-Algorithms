#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <algorithm>
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

public:
    Graph(int length)
    {
        adj.resize(length+1);
    }

    void connect(int from, int to)
    {
        if (adj[from].hasNeighbour(to) == false && adj[to].hasNeighbour(from) == false) //avoid cycles
        {
            adj[from].addNeighbour(to);
        }
    }

    void DFS(int start, int endd, vector<bool>& visited, vector<int>& parent, vector<long>& number)
    {
        for (auto element: adj[start].neighbours)
        {
            if (element == endd)
            {
                parent[element] = start; //remember the parent of endd

                auto help = element;
                while (parent[help] != 0) //change the value in all parents, connected to endd
                {
                    number[parent[help]] = number[parent[help]]+1;
                    number[parent[help]] = number[parent[help]]%1000000007; //because the value can be a big number
                    help = parent[help];
                }
            }
            else
            {
                if (visited[element] == false)
                {
                    visited[element] = true;
                    parent[element] = start; //remember the parent of our element
                    DFS(element, endd, visited, parent, number);
                }
                else
                {
                    if (number[element] > 0) //if the vertex is visited and we have been here before
                    {
                        parent[element] = start; //again remember the parent

                        auto help = element;
                        while (parent[help] != 0) //again change the value in vector number for the parents which are connected to our element
                        {
                            number[parent[help]] = number[parent[help]]+number[element];
                            number[parent[help]] = number[parent[help]]%1000000007; //because the value can be a big number
                            help = parent[help];
                        }
                    }
                }
            }
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int M;
    cin >> N;
    cin >> M;

    Graph g(N);

    int from;
    int to;

    for (int i = 0; i < M; i++)
    {
        cin >> from;
        cin >> to;
        g.connect(from, to);
    }

    int start;
    int endd;
    cin >> start;
    cin >> endd;

    if (start == endd)
    {
        cout << 0;
        return 0;
    }

    vector<bool> visited(N+1, false);
    vector<long> number(N+1, 0);
    vector<int> parent(N+1, 0);

    g.DFS(start, endd, visited, parent, number);

    long cnt = number[start]%1000000007;

    cout << cnt << endl;

    return 0;
}
