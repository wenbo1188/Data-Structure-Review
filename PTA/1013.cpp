#include <bits/stdc++.h>

using namespace std;

#define MAX 1010
int matrix[MAX][MAX] = {0};

int need_repair(int len, int city)
{
    queue<int> q;
    vector<int> flags(len + 1);
    for (int i = 1;i <= len;++i)
    {
        if (i != city)
        {
            flags[i] = 0;
        }
        else
        {
            flags[i] = 1;
        } 
    }

    int repair = 0;
    int flag = 1;
    int start = 1;
    for (start = 1;start <= len && start == city;++start);
    q.push(start);
    flags[start] = 1;
    while (flag)
    {
        while (!q.empty())
        {
            int tmp = q.front();
            for (int i = 1;i <= len;++i)
            {
                if (matrix[tmp][i] == 1 && flags[i] == 0)
                {
                    q.push(i);
                    flags[i] = 1;
                }
            }
            q.pop();
        }
        flag = 0;
        for (int i = start;i <= len;++i)
        {
            if (flags[i] != 1)
            {
                q.push(i);
                flags[i] = 1;
                flag = 1;
                start = i;
                ++repair;
                break;
            }
        }
    }

    return repair;
}

int main()
{
    int N = 0;
    int M = 0;
    int K = 0;
    int c1 = 0, c2 = 0;
    int repair = 0;

    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0;i < M;++i)
    {
        scanf("%d %d", &c1, &c2);
        matrix[c1][c2] = 1;
        matrix[c2][c1] = 1;
    }
    vector<int> check(K);
    for (int i = 0;i < K;++i)
    {
        scanf("%d", &check[i]);
    }

    for (int i = 0;i < K;++i)
    {
        repair = need_repair(N, check[i]);
        printf("%d\n", repair);
    }

    return 0;
}