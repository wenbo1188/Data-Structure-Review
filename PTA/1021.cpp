#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

typedef struct node
{
    int id;
    vector<int> edges;
    int deepest;
}Node;

vector<Node> graph(MAX);

int cmp(Node a, Node b)
{
    if (a.deepest > b.deepest)
    {
        return 1;
    }
    if (a.deepest == b.deepest)
    {
        return a.id < b.id;
    }
    else
    {
        return 0;
    }   
}

int dfs(int start, vector<int> &visit, int depth, int num)
{
    // printf("%d visited, depth: %d\n", start, depth);
    visit[start] = 1;
    // for (int i = 1;i <= num;++i)
    // {
    //     printf("%d\n", visit[i]);
    // }
    int deepest = depth;
    int deep = depth;
    for (int i = 0;i < graph[start].edges.size();++i)
    {
        if (visit[graph[start].edges[i]] != 1)
        {
            deep = dfs(graph[start].edges[i], visit, depth + 1, num);
            // printf("deep: %d deepest: %d\n", deep, deepest);
            if (deep > deepest)
            {
                deepest = deep;
            }
        }
    }
    // printf("deepest: %d\n", deepest);
    return deepest;
}

int check_visit(vector<int> &visit, int num)
{
    // printf("checking\n");
    // for (int i = 1;i <= num;++i)
    // {
    //     printf("%d\n", visit[i]);
    // }
    for (int i = 1;i <= num;++i)
    {
        if (visit[i] != 1)
        {
            return i;
        }
    }
    return -1;
}

int get_depth(int start, vector<int> &visit, int num, int *part)
{
    int depth = 0;
    int check = 0;
    int p = 1;
    depth = dfs(start, visit, 1, num);
    check = check_visit(visit, num);
    if (check == -1)
    {
        return depth;
    }
    else
    {
        while (check != -1)
        {
            ++p;
            dfs(check, visit, 1, num);
            check = check_visit(visit, num);
        }
    }
    *part = p;
    return -1;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int N = 0, from = 0, to = 0;
    scanf("%d", &N);
    for (int i = 1;i <= N;++i)
    {
        graph[i].id = i;
    }
    for (int i = 0;i < N - 1;++i)
    {
        scanf("%d %d", &from, &to);
        graph[from].edges.push_back(to);
        graph[to].edges.push_back(from);
    }

    vector<Node> depths;
    int depth = 0;
    int part = 0;
    int flag = 0;
    vector<int> visit(N + 1, 0);
    for (int i = 1;i <= N;++i)
    {
        for (int j = 1;j <= N;++j)
        {
            visit[j] = 0;
        }
        depth = get_depth(i, visit, N, &part);
        // printf("depth: %d\n", depth);
        if (depth == -1)
        {
            flag = 1;
            break;
        }
        graph[i].deepest = depth;
        depths.push_back(graph[i]);
    }
    if (flag)
    {
        printf("Error: %d components\n", part);
    }
    else
    {
        sort(depths.begin(), depths.end(), cmp);
        printf("%d\n", depths[0].id);
        for (int i = 1;i < N;++i)
        {
            if (depths[i].deepest == depths[i - 1].deepest)
            {
                printf("%d\n", depths[i].id);
            }
            else
            {
                break;
            }
        }
    }
    
    return 0;
}