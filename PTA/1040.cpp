#include <bits/stdc++.h>
using namespace std;

#define MAX 10010
string s;
int p[MAX] = {0};

int deal(string str)
{
    int len = str.size();
    s.insert(s.begin(), '$');
    s.insert(s.begin() + 1, '#');
    int j = 2;
    for (int i = 0;i < len;++i)
    {
        s.insert(s.begin() + j, str[i]);
        ++j;
        s.insert(s.begin() + j, '#');
        ++j;
    }
    return j;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    string str;
    getline(cin, str);
    int len = deal(str);
    // cout << s << endl;
    int max_len = -1;

    int id;
    int mx = 0;

    for (int i = 1;i < len;++i)
    {
        if (i < mx)
        {
            p[i] = min(p[2 * id - i], mx - i);
        }
        else
        {
            p[i] = 1;
        }
        
        while (s[i - p[i]] == s[i + p[i]])
            p[i]++;

        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }

        max_len = max(max_len, p[i] - 1);
    }

    printf("%d\n", max_len);

    return 0;
}