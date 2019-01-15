#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res[4] = {1, 1, 0, 2};
    long long n = 0ll;
    // freopen("in.txt", "r", stdin);
    scanf("%lld", &n);
    printf("%d\n", res[n % 4 - 1]);

    return 0;
}