#include <bits/stdc++.h>
using namespace std;

int cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    vector<string> parts;
    string tmp;
    string new_string = "";
    int N = 0;
    scanf("%d", &N);
    for (int i = 0;i < N;++i)
    {
        cin >> tmp;
        parts.push_back(tmp);
    }
    sort(parts.begin(), parts.end(), cmp);
    for (int i = 0;i < parts.size();++i)
    {
        new_string += parts[i];
    }
    int pos = 0;
    int flag = 0;
    for (int i = 0;i < new_string.size();++i)
    {
        if (new_string[i] != '0')
        {
            pos = i;
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("0\n");
    }
    else
    {
        for (int i = pos;i < new_string.size();++i)
        {
            printf("%c", new_string[i]);
        }
    }
    
    return 0;
}