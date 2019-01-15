#include <bits/stdc++.h>
using namespace std;

char c[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void transform(int num, char *m)
{
    int ratio = 0;
    int left = 0;
    int pos = 1;
    if (num == 0)
    {
        m[0] = '0';
        m[1] = '0';
        return;
    }
    while (num != 0)
    {
        ratio = num / 13;
        left = num % 13;
        num = ratio;
        m[pos--] = c[left];
    }
    if (pos == 0)
    {
        m[0] = '0';
    }
    return;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int R = 0, G = 0, B = 0;
    char Rm[3] = {0};
    char Gm[3] = {0};
    char Bm[3] = {0};
    cin >> R >> G >> B;
    transform(R, Rm);
    transform(G, Gm);
    transform(B, Bm);
    printf("#%s%s%s\n", Rm, Gm, Bm);
    return 0;
}