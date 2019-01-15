#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> m;

int nametoint(char *name)
{
    int sum = 0;
    for(int i=0;i<3;i++)
    {
        sum=sum*26+name[i]-'A';
    }
	sum=sum*10+name[3]-'0';
	return sum;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int query = 0;
    int course = 0;
    int course_id = 0;
    int num = 0;
    char name[20];
    scanf("%d %d", &query, &course);
    for (int i = 0;i < course;++i)
    {
        scanf("%d %d", &course_id, &num);
        for (int j = 0;j < num;++j)
        {
            scanf("%s", name);
            m[nametoint(name)].push_back(course_id);
        }
    }
    for (int i = 0;i < query;++i)
    {
        scanf("%s", name);
        printf("%s", name);
        int index = nametoint(name);
        printf(" %d", m[index].size());
        sort(m[index].begin(), m[index].end());
        for (int j = 0;j < m[index].size();++j)
        {
            printf(" %d", m[index][j]);
        }
        printf("\n");
    }
    return 0;
}