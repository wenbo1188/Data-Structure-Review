#include <stdio.h>

void solution(float *a, float *b)
{
    float sum[1001] = {0.0};
    int num = 0;
    for (int i = 0;i < 1001;++i)
    {
        sum[i] = a[i] + b[i];
        if (sum[i])
        {
            num++;
        }
    }

    if (num)
    {
        printf("%d ", num);
    }
    else
    {
        printf("%d\n", num);
        return;
    }

    for (int i = 1000;i >= 0;--i)
    {
        if (sum[i])
        {
            if (num > 1)
            {
                printf("%d %.1f ", i, sum[i]);
                --num;
            }
            else
            {
                printf("%d %.1f\n", i, sum[i]);
            }
        }
    }

    return;
}

int main(int argc, char const *argv[])
{
    int num1 = 0;
    int num2 = 0;
    float a[1001] = {0.0};
    float b[1001] = {0.0};
    float k = 0;
    int m = 0;
    scanf("%d ", &num1);
    for (int i = 0;i < num1 - 1;++i)
    {
        scanf("%d %f ", &m, &k);
        a[m] = k;
    }
    scanf("%d %f", &m, &k);
    a[m] = k;

    scanf("%d ", &num2);
    for (int i = 0;i < num2 - 1;++i)
    {
        scanf("%d %f ", &m, &k);
        b[m] = k;
    }
    scanf("%d %f", &m, &k);
    b[m] = k;

    // for (int i = 0;i < 10;++i)
    // {
    //     if (a[i] != 0)
    //     {
    //         printf("%d %f\n", i, a[i]);
    //     }
    // }

    // for (int i = 0;i < 10;++i)
    // {
    //     if (b[i] != 0)
    //     {
    //         printf("%d %f\n", i, b[i]);
    //     }
    // }
    solution(a, b);
    return 0;
}
