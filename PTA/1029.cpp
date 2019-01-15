#include <bits/stdc++.h>
using namespace std;

vector<int> a1;
#define MAX 200000

int main()
{
    // freopen("in.txt", "r", stdin);
    int l1 = 0;
    int l2 = 0;
    int tmp = 0;
    scanf("%d", &l1);
    for (int j = 0;j < l1;++j)
    {
        scanf("%d", &tmp);
        a1.push_back(tmp);
    }
    for (int j = l1;j < MAX;++j)
    {
        a1.push_back(INT_MAX);
    }
    scanf("%d", &l2);
    int target = (l1 + l2 - 1) / 2;
    int current = 0;
    int pos1 = 0;
    int pos2 = 0;
    int flag = 1;
    while (current != target)
    {
        if (pos2 <= l2 - 1)
        {
            if (flag)
            {
                scanf("%d", &tmp);
            }
            if (tmp < a1[pos1])
            {
                ++pos2;
                ++current;
                flag = 1;
            }
            else
            {
                ++pos1;
                ++current;
                flag = 0;
            }
        }
        else
        {
            break;
        }
    }
    if (pos2 <= l2 - 1)
    {
        scanf("%d", &tmp);
        printf("%d\n", tmp < a1[pos1] ? tmp : a1[pos1]);
    }
    else
    {
        while (current != target)
        {
            ++pos1;
            ++current;
        }
        printf("%d\n", a1[pos1]);
    }
    
    return 0;
}