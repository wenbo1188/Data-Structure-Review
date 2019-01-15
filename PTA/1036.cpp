#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string name;
    string gen;
    string id;
    int grade;
}Student;

vector<Student> m;
vector<Student> f;

int cmp1(Student a, Student b)
{
    return a.grade < b.grade;
}

int cmp2(Student a, Student b)
{
    return a.grade > b.grade;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int N = 0;
    string name;
    string gen;
    string id;
    int grade = 0;
    Student tmp;
    scanf("%d", &N);
    for (int i = 0;i < N;++i)
    {
        cin >> name >> gen >> id >> grade;
        // cout << name << gen << id << grade;
        tmp.name = name;
        tmp.gen = gen;
        tmp.id = id;
        tmp.grade = grade;
        if (gen == "M")
        {
            m.push_back(tmp);
        }
        else
        {
            f.push_back(tmp);
        }
    }
    if (m.size() == 0)
    {
        sort(f.begin(), f.end(), cmp2);
        cout << f[0].name << " " << f[0].id << endl;
        printf("Absent\n");
        cout << "NA" << endl;
        return 0;
    }
    if (f.size() == 0)
    {
        printf("Absent\n");
        sort(m.begin(), m.end(), cmp1);
        cout << m[0].name << " " << m[0].id << endl;
        cout << "NA" << endl;
        return 0;
    }
    sort(m.begin(), m.end(), cmp1);
    sort(f.begin(), f.end(), cmp2);
    cout << f[0].name << " " << f[0].id << endl;
    cout << m[0].name << " " << m[0].id << endl;
    cout << f[0].grade - m[0].grade << endl;
    return 0;
}