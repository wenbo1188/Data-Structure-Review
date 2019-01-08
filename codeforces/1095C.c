#include <stdio.h>

int result[31] = {0};

int find(int *array, int len)
{
    for (int i = 1;i < len;++i)
    {
        if (array[i] != 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    unsigned int n, k = 0;
    int num = 0;
    scanf("%u %u", &n, &k);
    unsigned int array[31] = {0};
    for (int i = 0;i < 31;++i)
    {
        array[i] = 1 << i;
    }
    
    for (int i = 30;i >= 0;--i)
    {
        if (n >= array[i])
        {
            n -= array[i];
            result[i] = 1;
            ++num;
        }
    }
    // printf("%d\n", num);
    if (num > k)
    {
        printf("NO\n");
        return 0;
    }
    if (num == k)
    {
        printf("YES\n");
        
        for (int i = 0;i < 31;++i)
        {
            for (int j = 0;j < result[i];++j)
            {
                printf("%u ", array[i]);
            }
        }
        printf("\n");
        return 0;
    }


    // for (int i = 0;i < 31;++i)
    // {
    //     printf("%d\n", result[i]);
    // }
    int res = -1;
    while (num < k && (res = find(result, 31)) != -1)
    {
        result[res - 1] += 2;
        result[res]--;
        num++;
    }
    if (num < k)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        
        for (int i = 0;i < 31;++i)
        {
            for (int j = 0;j < result[i];++j)
            {
                printf("%u ", array[i]);
            }
        }
        printf("\n");
    }

    // for (int i = 0;i < 31;++i)
    // {
    //     printf("%d\n", result[i]);
    // }

    return 0;
}