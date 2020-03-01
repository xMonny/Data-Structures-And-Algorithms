#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int M;
    cin >> N;
    cin >> M;

    unordered_map<string, long> answer;
    unordered_map<string, long>:: iterator it;

    string town;
    long price;

    string search;

    long ans = 0;;

    for (int i = 0; i < N; i++)
    {
        cin >> town;
        cin >> price;
        answer.insert(make_pair(town, price));
    }
    for (int i = 0; i < M; i++)
    {
        cin >> search;
        it = answer.find(search);
        if (it != answer.end())
        {
            ans+=it->second;
        }
    }

    cout << ans;

    return 0;
}
