#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > table(5010);
vector<int> a;
vector<int> colors;

int main()
{
    // freopen("in.txt", "r", stdin);
    int num = 0;
    int color = 0;
    int tmp = 0;
    int c = 0;
    scanf("%d %d", &num, &color);
    for (int i = 0;i < num;++i)
    {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i = 0;i < num;++i)
    {
        if (table[a[i]] + 1 > color)
        {
            printf("NO\n");
            return 0;
        }
        c = ++table[a[i]];
        colors.push_back(c);
    }
    printf("YES\n");
    for (int i = 0;i < colors.size() - 1;++i)
    {
        printf("%d ", colors[i]);
    }
    printf("%d\n", colors[colors.size() - 1]);
    return 0;
}