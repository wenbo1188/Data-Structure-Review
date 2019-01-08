#include <stdio.h>

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }

    return a * power(a, b - 1);
}

void solution(int a, int b)
{
    int sum = 0;
    sum = a + b;
    if (sum < 0)
    {
        sum = -1 * sum;
        printf("-");
    }

    int i = 0;
    while (sum >= power(1000, i))
    {
        ++i;
    }
    --i;

    if (sum < 1000)
    {
        printf("%d\n", sum);
        return;
    }

    if (sum >= 1000)
    {
        printf("%d,", sum / power(1000, i));
        sum = sum - (sum / power(1000, i)) * power(1000, i);
        --i;
    }

    while (sum >= 1000 || i >= 1)
    {
        printf("%03d,", sum / power(1000, i));
        sum = sum - (sum / power(1000, i)) * power(1000, i);
        --i;
    }
    printf("%03d\n", sum);
    return;
}

int main(int argc, char const *argv[])
{
    // solution(245, 1000);
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    solution(a, b);
    // solution(1000000, -9);
    return 0;
}
