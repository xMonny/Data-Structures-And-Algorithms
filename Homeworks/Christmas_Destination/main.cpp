#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

stack<string> route;
string contains;
string start;

class Graph
{
    map<string, map<string, int>> destination;

public:
    void contain(string one)
    {
        for (auto element: destination)
        {
            if (isConnected(element.first, one))
            {
                contains = element.first;
            }
        }
    }

    bool isConnected(string one, string two)
    {
        return destination[one][two] == 1;
    }

    void add(string one, string two)
    {
        destination[one][two] = 1;
    }

    void BFS(string one, string two)
    {
        queue<string> help;
        map<string, string> view;

        view[one] = "0";
        help.push(one);

        while (!help.empty())
        {
            string memory = help.front();
            help.pop();
            if(memory == two)
            {
                string answer = memory;
                while (answer != one)
                {
                    route.push(answer);
                    answer = view[answer];
                }
                route.push(answer);
                return;
            }
            for(auto element: destination[memory])
            {
                if(isConnected(memory, element.first) && view[element.first] == "")
                {
                    help.push(element.first);
                    view[element.first] = memory;
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int number;
    cin >> N;
    cin >> number;

    string citySTART;
    string cityEND;

    Graph g;

    for (int i = 0; i < number; i++)
    {
        cin >> citySTART;
        cin >> cityEND;

        g.add(citySTART, cityEND);
    }

    cin >> start;
    g.contain(start);

    g.BFS(start, contains);

    if (route.empty())
    {
        cout << -1;
        return 0;
    }

    while(!route.empty())
    {
        cout << route.top() << " ";
        route.pop();
    }

    cout << start;

    return 0;
}
