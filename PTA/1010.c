#include <stdio.h>
#include <string.h>

#define isdigit(d) ('0' <= d && d <= '9')
#define MAX 10000

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
    else
    {
        return a * power(a, b - 1);
    }
}

int get_low(char *str, int len)
{
    int max = 0;
    for (int i = 0;i < len;++i)
    {
        if (isdigit(str[i]))
        {
            if (str[i] - '0' > max)
            {
                max = str[i] - '0';
            }
        }
        else
        {
            if (str[i] - 'a' + 10 > max)
            {
                max = str[i] - 'a' + 10;
            }
        }
    }
    return max + 1;
}

int main()
{
    char str1[MAX] = {0};
    char str2[MAX] = {0};
    int N1 = 0, N2 = 0, tag = 0, radix = 0;
    scanf("%s %s %d %d", str1, str2, &tag, &radix);
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int left = 0;
    int right = 0;

    if (tag == 1)
    {
        for (int i = l1 - 1;i >= 0;--i)
        {
            if (isdigit(str1[i]))
            {
                N1 += (str1[i] - '0') * power(radix, l1 - 1 - i);
            }
            else
            {
                N1 += (str1[i] - 'a' + 10) * power(radix, l1 - 1 - i);
            }
        }
        // printf("%d\n", N1);
        left = get_low(str2, l2);
        right = left > N1 + 1 ? left : N1 + 1;
        for (int i = left;i <= right;++i)
        {
            N2 = 0;
            for (int j = l2 - 1;j >= 0;--j)
            {
                if (isdigit(str2[j]))
                {
                    N2 += (str2[j] - '0') * power(i, l2 - 1 - j);
                }
                else
                {
                    N2 += (str2[j] - 'a' + 10) * power(i, l2 - 1 - j);
                }
            }
            // printf("%d\n", N2);
            if (N2 == N1)
            {
                printf("%d\n", i);
                return 0;
            }
        }
        printf("Impossible\n");
    }
    else
    {
        for (int i = l2 - 1;i >= 0;--i)
        {
            // printf("%d\n", N2);
            // printf("%d %c\n", i, str2[i]);
            if (isdigit(str2[i]))
            {
                N2 += (str2[i] - '0') * power(radix, l2 - 1 - i);
            }
            else
            {
                N2 += (str2[i] - 'a' + 10) * power(radix, l2 - 1 - i);
            }
        }
        // printf("%d\n", N2);
        left = get_low(str1, l1);
        right = left > N2 + 1 ? left : N2 + 1;
        for (int i = left;i <= right;++i)
        {
            N1 = 0;
            for (int j = l1 - 1;j >= 0;--j)
            {
                if (isdigit(str1[j]))
                {
                    N1 += (str1[j] - '0') * power(i, l1 - 1 - j);
                }
                else
                {
                    N1 += (str1[j] - 'a' + 10) * power(i, l1 - 1 - j);
                }
            }
            // printf("%d\n", N1);
            if (N2 == N1)
            {
                printf("%d\n", i);
                return 0;
            }
        }
        printf("Impossible\n");
    }
    
    return 0;
}