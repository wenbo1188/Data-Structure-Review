#include <bits/stdc++.h>
using namespace std;

typedef struct tester
{
    string id;
    int grade;
    int final_rank;
    int loc_num;
    int loc_rank;
}Tester;

int cmp1(Tester a, Tester b)
{
    return a.grade > b.grade;
}

int cmp2(Tester a, Tester b)
{
    if (a.final_rank < b.final_rank)
    {
        return 1;
    }
    if (a.final_rank == b.final_rank)
    {
        return a.id < b.id;
    }
    return 0;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int num_loc = 0;
    int num_test = 0;
    string id;
    int grade = 0;
    scanf("%d", &num_loc);
    vector<Tester> final;
    for (int i = 0;i < num_loc;++i)
    {
        scanf("%d", &num_test);
        vector<Tester> t;
        t.clear();
        for (int j = 0;j < num_test;++j)
        {
            Tester tester;
            cin >> id >> grade;
            tester.id = id;
            tester.grade = grade;
            tester.loc_num = i + 1;
            t.push_back(tester);
        }
        sort(t.begin(), t.end(), cmp1);
        for (int j = 0;j < t.size();++j)
        {
            if (j == 0)
            {
                t[j].loc_rank = 1;
            }
            else
            {
                if (t[j].grade == t[j - 1].grade)
                {
                    t[j].loc_rank = t[j - 1].loc_rank;
                }
                else
                {
                    t[j].loc_rank = j + 1;
                }
            }
            final.push_back(t[j]);
        }
    }

    sort(final.begin(), final.end(), cmp1);
    for (int i = 0;i < final.size();++i)
    {
        if (i == 0)
        {
            final[i].final_rank = 1;
        }
        else
        {
            if (final[i].grade == final[i - 1].grade)
            {
                final[i].final_rank = final[i - 1].final_rank;
            }
            else
            {
                final[i].final_rank = i + 1;
            }
        }
    }
    sort(final.begin(), final.end(), cmp2);
    printf("%d\n", final.size());
    for (int i = 0;i < final.size();++i)
    {
        printf("%s %d %d %d\n", final[i].id.c_str(), final[i].final_rank, final[i].loc_num, final[i].loc_rank);
    }
    
    return 0;
}