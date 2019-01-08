#include <stdio.h>

typedef struct kid
{
    int kid1;
    int kid2;
}kid;

kid kids[200000] = {0};
int flags[200000] = {0};
int result[200000] = {0};

int check(int kid, int other)
{
    if (kids[kid - 1].kid1 == other || kids[kid - 1].kid2 == other)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n = 0;
    int kid1 = 0;
    int kid2 = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;++i)
    {
        scanf("%d %d", &kids[i].kid1, &kids[i].kid2);
    }
    int num = n;
    
    int p = 0;
    result[p] = 1;
    flags[p] = 1;
    ++p;
    n--;
    while (n > 1)
    {
        kid1 = kids[result[p - 1] - 1].kid1;
        kid2 = kids[result[p - 1] - 1].kid2;
        // printf("kid1:%d kid2:%d\n", kid1, kid2);
        // printf("kid1's children:%d %d\n", kids[kid1 - 1].kid1, kids[kid1 - 1].kid2);
        if (check(kid1, kid2))
        {
            result[p++] = kid1;
            result[p++] = kid2;
            n -= 2;
            flags[kid1 - 1] = 1;
            flags[kid2 - 1] = 1;
        }
        else
        {
            result[p++] = kid2;
            result[p++] = kid1;
            n -= 2;
            flags[kid2 - 1] = 1;
            flags[kid1 - 1] = 1;
        }
    }
    if (n == 1)
    {
        for (int i = 0;i < num;++i)
        {
            if (flags[i] != 1)
            {
                result[p++] = i + 1;
            }
        }
    }
    for (int i = 0;i < num - 1;++i)
    {
        printf("%d ", result[i]);
    }
    printf("%d\n", result[num - 1]);

    return 0;
}