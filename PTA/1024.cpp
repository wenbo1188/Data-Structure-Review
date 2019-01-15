#include <bits/stdc++.h>
using namespace std;

string add(string &num1, string &num2)
{
    int l1 = num1.size();
    int l2 = num2.size();
    int s = 0;
    int c = 0;
    string res;
    if (l1 <= l2)
    {
        for (int i = 0;i < l1;++i)
        {
            s = (c + (num1[l1 - 1 - i] - '0') + (num2[l2 - 1- i] - '0')) % 10;
            res.insert(res.begin(), s + '0');
            c = (c + (num1[l1 - 1 - i] - '0') + (num2[l2 - 1- i] - '0')) / 10;
        }
        for (int i = l1;i < l2;++i)
        {
            s = (c + (num2[l2 - 1 - i] - '0')) % 10;
            res.insert(res.begin(), s + '0');
            c = (c + (num2[l2 - 1 - i] - '0')) / 10;
        }
        if (c != 0)
        {
            res.insert(res.begin(), c + '0');
        }
    }
    else
    {
        for (int i = 0;i < l2;++i)
        {
            s = (c + (num1[l1 - 1 - i] - '0') + (num2[l2 - 1- i] - '0')) % 10;
            res.insert(res.begin(), s + '0');
            c = (c + (num1[l1 - 1 - i] - '0') + (num2[l2 - 1- i] - '0')) / 10;
        }
        for (int i = l2;i < l1;++i)
        {
            s = (c + (num1[l1 - 1 - i] - '0')) % 10;
            res.insert(res.begin(), s + '0');
            c = (c + (num1[l1 - 1 - i] - '0')) / 10;
        }
        if (c != 0)
        {
            res.insert(res.begin(), c + '0');
        }
    }
    // for (int i = res.size() - 1;i >= 0;--i)
    // {
    //     reverse.push_back(res[i]);
    // }
    return res;
}

string get_reverse(string &num)
{
    string s;
    for (int i = num.size() - 1;i >= 0;--i)
    {
        s.push_back(num[i]);
    }

    return s;
}

int judge(string &num)
{
    for (int i = 0;i < num.size();++i)
    {
        if (num[i] != num[num.size() - 1 - i])
        {
            return -1;
        }
    }
    return 1;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    string N;
    string reverse;
    int K = 0;
    cin >> N >> K;
    int step = 0;
    while (judge(N) != 1 && step < K)
    {
        reverse = get_reverse(N);
        N = add(N, reverse);
        // cout << N << endl;
        ++step;
        // printf("%d steps now\n", step);
    }
    cout << N << endl;
    cout << step << endl;
    
    return 0;
}