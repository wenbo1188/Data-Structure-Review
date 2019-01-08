#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

typedef struct pair
{
    int num;
    int radix;
}PAIR;

int judge_prime(int num)
{
    if (num == 1)
    {
        return 0;
    }
    if (num == 2)
    {
        return 1;
    }
    for (int i = 2;i <= (int)sqrt(num);++i)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int get_reverse(PAIR p)
{
    int num = p.num;
    int radix = p.radix;
    int shang = 1;
    int yu = 0;
    
    int sum = 0;
    while (shang != 0)
    {
        sum *= radix;
        shang = num / radix;
        yu = num % radix;
        num = shang;
        sum += yu;
    }

    return sum;
}

int main()
{
    int N = 0, D = 0;
    PAIR p = {0};
    int count = 0;
    vector<PAIR> pairs(MAX);
    while (1)
    {
        scanf("%d", &N);
        if (N >= 0)
        {
            // printf("%d\n", N);
            scanf("%d", &D);
            p.num = N;
            p.radix = D;
            pairs[count] = p;
            ++count;
        }
        else
        {
            break;
        }
    }

    // printf("i am here\n");
    for (int i = 0;i < count;++i)
    {
        // printf("%d\n", pairs[i].num);
        if (!judge_prime(pairs[i].num))
        {
            printf("No\n");
        }
        else
        {
            int reverse = get_reverse(pairs[i]);
            // printf("%d\n", reverse);
            if (judge_prime(reverse))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}