#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int q;

    cin >> n >> q;

    int start;
    int end;

    vector<pair<int,int>> v;

    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    vector<int> seconds;
    int second;

    for (int i = 0; i < q; i++)
    {
        cin >> second;
        seconds.push_back(second);
    }

    int cnt = 0;

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (seconds[i] >= v[j].first && seconds[i] <= v[j].second)
            {
                cnt++;
            }
        }
        cout << cnt << " ";
        cnt = 0;
    }

    return 0;
}
