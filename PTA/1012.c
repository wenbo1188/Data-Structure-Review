#include <stdio.h>
#include <string.h>

#define MAX 2010

typedef struct student
{
    char id[10];
    int C;
    int M;
    int E;
    int A;
}Students[MAX], Student;

int main()
{
    int N = 0;
    int M = 0;
    int c = 0;
    int m = 0;
    int e = 0;
    int a = 0;
    char str[10] = {0};
    char checkids[MAX][10] = {0};
    Students c_array = {0};
    Students m_array = {0};
    Students e_array = {0};
    Students a_array = {0};
    Student tmp = {0};

    scanf("%d %d", &N, &M);
    for (int i = 0;i < N;++i)
    {
        scanf("%s %d %d %d", str, &c, &m, &e);
        a = (c + m + e) / 3;
        strcpy(tmp.id, str);
        tmp.A = a;
        tmp.C = c;
        tmp.E = e;
        tmp.M = m;
        for (int j = 0;j < N;++j)
        {
            if (c > c_array[j].C)
            {
                c_array[j + 1] = c_array[j];
                c_array[j] = tmp;
                break;
            }
        }
        for (int j = 0;j < N;++j)
        {
            if (m > m_array[j].M)
            {
                m_array[j + 1] = m_array[j];
                m_array[j] = tmp;
                break;
            }
        }
        for (int j = 0;j < N;++j)
        {
            if (e > e_array[j].E)
            {
                e_array[j + 1] = e_array[j];
                e_array[j] = tmp;
                break;
            }
        }
        for (int j = 0;j < N;++j)
        {
            if (a > a_array[j].A)
            {
                a_array[j + 1] = a_array[j];
                a_array[j] = tmp;
                break;
            }
        }
    }

    for (int i = 0;i < M;++i)
    {
        scanf("%s", str);
        strcpy(checkids[i], str);
    }
    for (int i = 0;i < M;++i)
    {
        int best_rank = 65535;
        char best_course = 'A';
        int flag = 0;
        for (int j = 0;j < N;++j)
        {
            if (strcmp(a_array[j].id, checkids[i]) == 0)
            {
                int con_rank = j + 1;
                for (int k = j;k > 0;--k)
                {
                    if (a_array[k].A == a_array[k - 1].A)
                    {
                        --con_rank;
                    }
                }
                if (con_rank < best_rank)
                {
                    best_rank = con_rank;
                    best_course = 'A';
                    flag = 1;
                    break;
                }
            }
        }
        for (int j = 0;j < N;++j)
        {
            if (strcmp(c_array[j].id, checkids[i]) == 0)
            {
                int con_rank = j + 1;
                for (int k = j;k > 0;--k)
                {
                    if (c_array[k].C == c_array[k - 1].C)
                    {
                        --con_rank;
                    }
                }
                if (con_rank < best_rank)
                {
                    best_rank = con_rank;
                    best_course = 'C';
                    flag = 1;
                    break;
                }
            }
        }
        for (int j = 0;j < N;++j)
        {
            if (strcmp(m_array[j].id, checkids[i]) == 0)
            {
                int con_rank = j + 1;
                for (int k = j;k > 0;--k)
                {
                    if (m_array[k].M == m_array[k - 1].M)
                    {
                        --con_rank;
                    }
                }
                if (con_rank < best_rank)
                {
                    best_rank = con_rank;
                    best_course = 'M';
                    flag = 1;
                    break;
                }
            }
        }
        for (int j = 0;j < N;++j)
        {
            if (strcmp(e_array[j].id, checkids[i]) == 0)
            {
                int con_rank = j + 1;
                for (int k = j;k > 0;--k)
                {
                    if (e_array[k].E == e_array[k - 1].E)
                    {
                        --con_rank;
                    }
                }
                if (con_rank < best_rank)
                {
                    best_rank = con_rank;
                    best_course = 'E';
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            printf("N/A\n");
        }
        else
        {
            printf("%d %c\n", best_rank, best_course);
        }
    }
    return 0;
}