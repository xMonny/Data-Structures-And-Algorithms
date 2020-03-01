#include <iostream>

using namespace std;

int main()
{
    int N;
    int cnt = 0;
    cin >> N;

    int arr[63];

    for (int i = 0; i < 63; i++)
    {
        if (i < 20)
        {
            arr[i] = i+1;
        }
        if (i >= 20 && i < 40)
        {
            arr[i] = arr[i-20]*2;
        }
        if (i >= 40 && i < 60)
        {
            arr[i] = arr[i-40]*3;
        }
        if (i == 60)
        {
            arr[i] = 25;
        }
        if (i == 61)
        {
            arr[i] = 50;
        }
        if (i == 62)
        {
            arr[i] = 0;
        }
    }

    for (int i = 20; i < 40; i++)
    {
        if (i == 20 && N == 50)
        {
            cnt++;
        }
        if (N == arr[i])
        {
            cnt++;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        if (N == arr[i]+50)
        {
            cnt++;
        }
        if (N == arr[i]+25+50 || N == arr[i]+0+50)
        {
            cnt+=2;
        }
        if (N == arr[i]+50+50)
        {
            cnt+=2;
        }
    }

    for (int i = 40; i < 60; i++)
    {
        if (N == arr[i]+50)
        {
            cnt++;
        }
        if (N == arr[i]+25+50 || N == arr[i]+0+50)
        {
            cnt+=2;
        }
        if (N == arr[i]+50+50)
        {
            cnt+=2;
        }
    }

    for (int i = 20; i < 40; i++)
    {
        if (N == arr[i]+25 || N == arr[i]+0)
        {
            cnt++;
        }
        if (N == arr[i]+50)
        {
            cnt+=2;
        }
        if (N == arr[i]+25+0)
        {
            cnt+=2;
        }
        if (N == arr[i]+25+25 || N == arr[i]+0+0)
        {
            cnt++;
        }
        if (N == arr[i]+25+50 || N == arr[i]+0+50)
        {
            cnt+=4;
        }
        if (N == arr[i]+50+50)
        {
            cnt+=3;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            if (N == arr[i]+arr[j])
            {
                cnt++;
            }
        }
    }

    for (int i = 40; i < 60; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            if (N == arr[i]+arr[j])
            {
                cnt++;
            }
        }
    }

    for (int i = 20; i < 40; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            if (N == arr[i]+arr[j])
            {
                cnt++;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            if (N == arr[i]+arr[j]+25 || N == arr[i]+arr[j]+0)
            {
                cnt+=2;
            }
            if (N == arr[i]+arr[j]+50)
            {
                cnt+=4;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 40; j < 60; j++)
        {
            if (N == arr[i]+arr[j]+50)
            {
                if (arr[i]%3!=0)
                {
                    cnt+=2;
                }
                else
                {
                    if (arr[j] < 20)
                    {
                        cnt++;
                    }
                    else
                    {
                        cnt+=2;
                    }
                }
            }
        }
    }

    for (int i = 40; i < 60; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            if (N == arr[i]+arr[j]+25 || N == arr[i]+arr[j]+0)
            {
                cnt+=2;
            }
            if (N == arr[i]+arr[j]+50)
            {
                cnt+=4;
            }
        }
    }

    for (int i = 20; i < 40; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            if (N == arr[i]+arr[j]+25 || N == arr[i]+arr[j]+0)
            {
                cnt+=2;
            }
            if (N == arr[i]+arr[j]+50)
            {
                cnt+=3;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (N == arr[i]+arr[j]+50)
            {
                cnt++;
            }
        }
    }

    for (int i = 40; i < 60; i++)
    {
        for (int j = 40; j < 60; j++)
        {
            if (N == arr[i]+arr[j]+50)
            {
                cnt++;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            for (int m = 40; m < 60; m++)
            {
                if (N == arr[i]+arr[j]+arr[m])
                {
                    cnt+=2;
                }
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            for (int m = 0; m < 20; m++)
            {
                if (N == arr[i]+arr[j]+arr[m])
                {
                    cnt++;
                }
            }
        }
    }

    for (int i = 40; i < 60; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            for (int m = 40; m < 60; m++)
            {
                if (N == arr[i]+arr[j]+arr[m])
                {
                    cnt++;
                }
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            for (int m = 20; m < 40; m++)
            {
                if (N == arr[i]+arr[j]+arr[m])
                {
                    cnt+=2;
                }
            }
        }
    }

    for (int i = 40; i < 60; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            for (int m = 20; m < 40; m++)
            {
                if (N == arr[i]+arr[j]+arr[m])
                {
                    cnt+=2;
                }
            }
        }
    }

    for (int i = 20; i < 40; i++)
    {
        for (int j = 20; j < 40; j++)
        {
            for (int m = 20; m < 40; m++)
            {
                if (N == arr[i]+arr[j]+arr[m])
                {
                    cnt++;
                }
            }
        }
    }

    if (N == 25+50 || N == 0+50)
    {
        cnt++;
    }

    if (N == 25+50+0)
    {
        cnt+=2;
    }

    if (N == 25+25+50 || N == 0+0+50)
    {
        cnt++;
    }

    if (N == 50+50+25 || N == 50+50+0)
    {
        cnt+=2;
    }

    if (N == 50+50+50)
    {
        cnt++;
    }

    cout << cnt;

    return 0;
}
