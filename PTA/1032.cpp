#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int address;
    char data;
    int next;
}Node;

stack<Node> s1;
stack<Node> s2;
vector<Node> maps(100020);

int main()
{
    // freopen("in.txt", "r", stdin);
    int start1 = 0;
    int start2 = 0;
    int N = 0;
    Node tmp = {0};
    int address = 0;
    char data = 0;
    int next = 0;
    scanf("%d %d %d", &start1, &start2, &N);
    for (int i = 0;i < N;++i)
    {
        scanf("%d %c %d", &address, &data, &next);
        tmp.address = address;
        tmp.data = data;
        tmp.next = next;
        maps[address] = tmp;
    }

    while (start1 != -1)
    {
        // printf("%d\n", start1);
        s1.push(maps[start1]);
        start1 = maps[start1].next;
    }
    while (start2 != -1)
    {
        s2.push(maps[start2]);
        start2 = maps[start2].next;
    }

    int recent_common = 0;
    if (s1.empty() || s2.empty())
    {
        printf("-1\n");
        return 0;
    }
    Node c1 = {0};
    Node c2 = {0};
    c1 = s1.top();
    c2 = s2.top();
    if (c1.data != c2.data)
    {
        printf("-1\n");
        return 0;
    }
    while (!s1.empty() && !s2.empty())
    {
        c1 = s1.top();
        c2 = s2.top();
        if (c1.data == c2.data)
        {
            s1.pop();
            s2.pop();
            recent_common = c1.address;
        }
        else
        {
            break;
        }
    }
    printf("%05d\n", recent_common);

    return 0;
}