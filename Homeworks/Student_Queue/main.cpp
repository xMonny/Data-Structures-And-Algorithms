#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N; //number of students
    int M; //number of groups;

    cin >> N >> M;

    string name;
    int group;

    int position = 0;

    int time = 2;

    vector<queue<pair<string, long>>> que;
    queue<int> groups;

    que.resize(M+1);

    for (int i = 0; i < N; i++)
    {
        cin >> name;
        cin >> group;

        if (i == 0)
        {
            groups.push(group);
        }

        if (i != 0)
        {
           if (que[group].empty())
           {
               groups.push(group);
           }
        }

        que[group].push(make_pair(name, position));

        if (position%2 == 0 && position != 0)
        {
            cout << que[groups.front()].front().first << " " << que[groups.front()].front().second << " " << time << endl;
            que[groups.front()].pop();
            if (que[groups.front()].empty())
            {
                groups.pop();
            }
            time+=2;
        }
        position++;
    }

    while (!groups.empty())
    {
        cout << que[groups.front()].front().first << " " << que[groups.front()].front().second << " " << time << endl;
        que[groups.front()].pop();
        time+=2;

        if (que[groups.front()].empty())
        {
            groups.pop();
        }
    }

    return 0;
}
