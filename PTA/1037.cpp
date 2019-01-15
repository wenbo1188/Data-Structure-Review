#include <bits/stdc++.h>
using namespace std;

vector<long long> cp;
vector<long long> cn;
vector<long long> pp;
vector<long long> pn;

int main()
{
    // freopen("in.txt", "r", stdin);
    int nc = 0;
    int np = 0;
    cin >> nc;
    long long tmp;
    for (int i = 0;i < nc;++i)
    {
        cin >> tmp;
        if (tmp > 0)
        {
            cp.push_back(tmp);
        }
        else if (tmp < 0)
        {
            cn.push_back(tmp);
        }
    }
    cin >> np;
    for (int i = 0;i < np;++i)
    {
        cin >> tmp;
        if (tmp > 0)
        {
            pp.push_back(tmp);
        }
        else if (tmp < 0)
        {
            pn.push_back(tmp);
        }
    }
    long long max_value = 0ll;
    sort(cp.rbegin(), cp.rend());
    sort(pp.rbegin(), pp.rend());
    sort(cn.begin(), cn.end());
    sort(pn.begin(), pn.end());
    int i = 0;
    while (i < cp.size() && i < pp.size())
    {
        max_value += cp[i] * pp[i];
        ++i;
    }
    int j = 0;
    while (j < cn.size() && j < pn.size())
    {
        max_value += cn[j] * pn[j];
        ++j;
    }
    cout << max_value << endl;

    return 0;
}