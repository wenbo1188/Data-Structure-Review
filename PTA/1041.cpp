#include <bits/stdc++.h>
using namespace std;

#define MAX 10010

vector<int> bets(MAX, 0);
vector<int> b;

int main()
{
    // freopen("in.txt", "r", stdin);
    int num = 0;
    int bet = 0;
    scanf("%d", &num);
    for (int i = 0;i < num;++i)
    {
        scanf("%d", &bet);
        b.push_back(bet);
        bets[bet]++;
    }
    int flag = 0;
    for (int i = 0;i < b.size();++i)
    {
        if (bets[b[i]] == 1)
        {
            flag = 1;
            printf("%d\n", b[i]);
            break;
        }
    }
    if (flag == 0)
    {
        printf("None\n");
    }
    return 0;
}