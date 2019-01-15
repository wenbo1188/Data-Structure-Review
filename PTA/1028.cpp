#include <bits/stdc++.h>
using namespace std;

typedef struct student
{
    int id;
    char name[10];
    int grade;
}Student;

int cmp1(Student a, Student b)
{
    return a.id < b.id;
}

int cmp2(Student a, Student b)
{
    if (strcmp(a.name, b.name) < 0)
    {
        return 1;
    }
    if (strcmp(a.name, b.name) == 0)
    {
        return a.id < b.id;
    }
    return 0;
}

int cmp3(Student a, Student b)
{
    if (a.grade < b.grade)
    {
        return 1;
    }
    if (a.grade == b.grade)
    {
        return a.id < b.id;
    }
    return 0;
}

vector<Student> students;

int main()
{
    // freopen("in.txt", "r", stdin);
    int N = 0, C = 0;
    Student s;
    cin >> N >> C;
    for (int i = 0;i < N;++i)
    {
        scanf("%d %s %d", &s.id, s.name, &s.grade);
        students.push_back(s);
    }
    if (C == 1)
    {
        sort(students.begin(), students.end(), cmp1);
    }
    else
    {
        if (C == 2)
        {
            sort(students.begin(), students.end(), cmp2);
        }
        else
        {
            sort(students.begin(), students.end(), cmp3);
        }
    }
    for (int i = 0;i < students.size();++i)
    {
        printf("%06d %s %d\n", students[i].id, students[i].name, students[i].grade);
    }
    
    return 0;
}