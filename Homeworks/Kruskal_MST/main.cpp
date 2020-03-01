#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> values;

void swap(int& one, int& two)
{
    int temp = one;
    one = two;
    two = temp;
}

void make_components(int index)
{
    parent[index] = index;
    values[index] = 0;
}

int find_parent(int index)
{
    if (index == parent[index])
    {
        return index;
    }
    return parent[index] = find_parent(parent[index]);
}

void union_components(int one, int two)
{
    one = find_parent(one);
    two = find_parent(two);

    if (one != two)
    {
        if (values[one] < values[two])
        {
            swap(one, two);
        }
        if (values[one] == values[two])
        {
            values[one]++;
        }
        parent[two] = one;
    }
}

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

int main()
{
    int N;
    int M;
    cin >> N;
    cin >> M;

    parent.resize(N+1);
    values.resize(N+1);

    for (int i = 0; i < N+1; i++)
    {
        make_components(i);
    }

    vector<Edge> edges(M);

    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    for (Edge element: edges)
    {
        if (find_parent(element.from) != find_parent(element.to))
        {
            cnt+=element.weight;
            union_components(element.from, element.to);
        }
    }

    cout << cnt;

    return 0;
}
