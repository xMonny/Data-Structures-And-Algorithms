#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<pair<int,int>> que;

    int N; //height
    int M; //length
    int T; //days

    int apples = 0;

    int appleN;
    int appleM;

    cin >> N >> M >> T;

    int matrix[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = -1;
        }
    }

    while (cin >> appleN >> appleM)
    {
        que.push(make_pair(appleN, appleM));
        matrix[N-appleN][appleM-1] = 0;
        apples++;
    }

    int height;
    int length;

    int all = N*M;
    int result = 0;
    int day = 0;

    pair<int, int> my;

    while(!que.empty())
    {
        my = que.front();
        height = N-my.first;
        length = my.second-1;
        if (matrix[height][length] != day)
        {
            day++;
        }
        if (matrix[height][length] != T)
        {
            if (matrix[height+1][length] < 0 && (height+1 >= 0 && height+1 < N && length >= 0 && length < M))
            {
                matrix[height+1][length] = day+1;
                apples++;
                que.push(make_pair(N-height-1, length+1));
            }
            if (matrix[height-1][length] < 0 && (height-1 >= 0 && height-1 < N && length >= 0 && length < M))
            {
                matrix[height-1][length] = day+1;
                apples++;
                que.push(make_pair(N-height+1, length+1));
            }
            if (matrix[height][length+1] < 0 && (height >= 0 && height < N && length+1 >= 0 && length+1 < M))
            {
                matrix[height][length+1] = day+1;
                apples++;
                que.push(make_pair(N-height, length+2));
            }
            if (matrix[height][length-1] < 0 && (height >= 0 && height < N && length-1 >= 0 && length-1 < M))
            {
                matrix[height][length-1] = day+1;
                apples++;
                que.push(make_pair(N-height, length));
            }
        }
        que.pop();
    }

    result = all-apples;

    cout << result;

    return 0;
}
