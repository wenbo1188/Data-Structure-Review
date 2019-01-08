#include <stdio.h>

#define MAX 2010

int main()
{
    float a[MAX] = {0.0};
    float b[MAX] = {0.0};
    int num = 0;
    int tmp = 0;
    scanf("%d", &num);
    for (int i = 0;i < num;++i)
    {
        scanf("%d", &tmp);
        scanf("%f", &a[tmp]);
    }
    scanf("%d", &num);
    for (int i = 0;i < num;++i)
    {
        scanf("%d", &tmp);
        scanf("%f", &b[tmp]);
    }

    float c[MAX] = {0.0};
    for (int i = 0;i < MAX;++i)
    {
        if (a[i] != 0.0)
        {
            for (int j = 0;j < MAX;++j)
            {
                if (b[j] != 0.0)
                {
                    // printf("%f %f\n", a[i], b[j]);
                    c[i + j] += a[i] * b[j];    
                }
            }
        }
    }

    int count = 0;
    for (int i = 0;i < MAX;++i)
    {
        if (c[i] != 0.0)
        {
            ++count;
        }
    }

    if (count == 0)
    {
        printf("%d\n", 0);
        return 0;
    }
    if (count == 1)
    {
        printf("%d ", count);
        for (int i = MAX - 1;i >= 0;--i)
        {
            if (c[i] != 0.0)
            {
                printf("%d %.1f", i, c[i]);
            }
        }
        return 0;
    }

    printf("%d", count);
    for (int i = MAX - 1;i >= 0;--i)
    {
        if (c[i] != 0.0)
        {
            printf(" %d %.1f", i, c[i]);
        }
    }

    return 0;
}