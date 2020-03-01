#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Coordinates
{
    int x;
    int y;
};

int main()
{
    int N;
    int M;

    cin >> N;
    cin >> M;

    char c;

    char matrix[N][M];
    int answer[N][M];

    Coordinates start;
    Coordinates finally;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> c;
            matrix[i][j] = c;
            if (c == 'S')
            {
                start.x = i;
                start.y = j;
            }
            if (c == 'F')
            {
                finally.x = i;
                finally.y = j;
            }
            if (c == '#')
            {
                answer[i][j] = -2;
            }
            else
            {
                answer[i][j] = -1;
            }
        }
    }

    queue<pair<int, int>> distance;
    distance.push(make_pair(start.x, start.y));
    answer[start.x][start.y] = 0;

    int second = 0;
    int change = 1;
    int check = 0;

    while (!distance.empty())
    {
        int newX = distance.front().first;
        int newY = distance.front().second;

        second = answer[newX][newY];

        for (int i = newX-1; i >= 0; i--)
        {
            if (matrix[i][newY] == '#')
            {
                if (i != newX-1)
                {
                    if (answer[i+1][newY] == -1 || answer[i+1][newY] > second+1)
                    {
                        answer[i+1][newY] = second+1;
                        distance.push(make_pair(i+1, newY));
                        matrix[i+1][newY] = '-';
                    }
                }
                break;
            }
        }

        for (int i = newX+1; i < N; i++)
        {
            if (matrix[i][newY] == '#')
            {
                if (i != newX+1)
                {
                    if (answer[i-1][newY] == -1 || answer[i-1][newY] > second+1)
                    {
                        answer[i-1][newY] = second+1;
                        distance.push(make_pair(i-1, newY));
                        matrix[i-1][newY] = '-';
                    }
                }
                break;
            }
        }

        for (int i = newY-1; i >= 0; i--)
        {
            if (matrix[newX][i] == '#')
            {
                if (i != newY-1)
                {
                    if (answer[newX][i+1] == -1 || answer[newX][i+1] > second+1)
                    {
                        answer[newX][i+1] = second+1;
                        distance.push(make_pair(newX, i+1));
                        matrix[newX][i+1] = '-';
                    }
                }
                break;
            }
        }

        for (int i = newY+1; i < M; i++)
        {
            if (matrix[newX][i] == '#')
            {
                if (i != newY+1)
                {
                    if (answer[newX][i-1] == -1 || answer[newX][i-1] > second+1)
                    {
                        answer[newX][i-1] = second+1;
                        distance.push(make_pair(newX, i-1));
                        matrix[newX][i-1] = '-';
                    }
                }
                break;
            }
        }

        if (matrix[newX-1][newY] == '.' || matrix[newX-1][newY] == 'F') //up
        {
            if (answer[newX-1][newY] == -1 || (answer[newX-1][newY] < second+1 && answer[newX-1][newY] != -2))
            {
                answer[newX-1][newY] = second+1;
                distance.push(make_pair(newX-1, newY)); //this can be out of IF (same about other cases)
                matrix[newX-1][newY] = '-'; //this can be out of IF (same about other cases)
            }
        }
        if (matrix[newX+1][newY] == '.' || matrix[newX+1][newY] == 'F') //down
        {
            if (answer[newX+1][newY] == -1 || (answer[newX+1][newY] < second+1) && answer[newX+1][newY] != -2)
            {
                answer[newX+1][newY] = second+1;
                distance.push(make_pair(newX+1, newY));
                matrix[newX+1][newY] = '-';
            }
        }
        if (matrix[newX][newY-1] == '.' || matrix[newX][newY-1] == 'F') //left
        {
            if (answer[newX][newY-1] == -1 || (answer[newX][newY-1] < second+1) && answer[newX][newY-1] != -2)
            {
                answer[newX][newY-1] = second+1;
                distance.push(make_pair(newX, newY-1));
                matrix[newX][newY-1] = '-';
            }
        }
        if (matrix[newX][newY+1] == '.' || matrix[newX][newY+1] == 'F') //right
        {
            if (answer[newX][newY+1] == -1 || (answer[newX][newY+1] < second+1) && answer[newX][newY+1] != -2)
            {
                answer[newX][newY+1] = second+1;
                distance.push(make_pair(newX, newY+1));
                matrix[newX][newY+1] = '-';
            }
        }
        distance.pop();
    }

    cout << answer[finally.x][finally.y];

    return 0;
}
