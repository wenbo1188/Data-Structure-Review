#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 0, radix = 0, trans_num = 0;
    cin >> num >> radix;
    stack<int> s;
    int shang = 0;
    int yu = 0;
    while (num != 0)
    {
        shang = num / radix;
        yu = num % radix;
        num = shang;
        s.push(yu);
    }
    queue<int> res;
    stack<int> c1;
    queue<int> c2;
    int flag = 1;
    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        res.push(tmp);
        c1.push(tmp);
        c2.push(tmp);
    }
    while (!(c1.empty() && c2.empty()))
    {
        int t1 = c1.top();
        c1.pop();
        int t2 = c2.front();
        c2.pop();
        if (t1 != t2)
        {
            printf("No\n");
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("Yes\n");
        printf("%d", res.front());
        res.pop();
        while (!res.empty())
        {
            printf(" %d", res.front());
            res.pop();
        }
    }
    else
    {
        printf("%d", res.front());
        res.pop();
        while (!res.empty())
        {
            printf(" %d", res.front());
            res.pop();
        }
    }

    return 0;
}