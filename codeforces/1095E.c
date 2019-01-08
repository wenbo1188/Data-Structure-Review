#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int len = 0;
    char *str = NULL;
    int *pref_bal = NULL;
    int *suff_bal = NULL;
    int *pref_can = NULL;
    int *suff_can = NULL;
    scanf("%d", &len);
    str = (char *)malloc(sizeof(char) * (len + 1));
    pref_bal = (int *)malloc(sizeof(int) * len);
    suff_bal = (int *)malloc(sizeof(int) * len);
    pref_can = (int *)malloc(sizeof(int) * len);
    suff_can = (int *)malloc(sizeof(int) * len);
    memset(pref_bal, 0, sizeof(int) * len);
    memset(suff_bal, 0, sizeof(int) * len);
    memset(pref_can, 0, sizeof(int) * len);
    memset(suff_can, 0, sizeof(int) * len);
    scanf("%s", str);
    str[len] = '\0';
    // printf("%s", str);
    if (len == 1)
    {
        printf("%d\n", 0);
        return 0;
    }
    if (len == 2)
    {
        if (strcmp(str, "((") == 0 || strcmp(str, "))") == 0)
        {
            printf("%d\n", 1);
            return 0;
        }
        else
        {
            printf("%d\n", 0);
            return 0;
        }
    }
    int balance = 0;
    for (int i = 0;i < len;++i)
    {
        if (str[i] == '(')
        {
            ++balance;
        }
        else
        {
            --balance;
        }
        pref_bal[i] = balance;
    }
    balance = 0;
    for (int i = len - 1;i >= 0;--i)
    {
        if (str[i] == '(')
        {
            ++balance;
        }
        else
        {
            --balance;
        }
        suff_bal[i] = balance;
    }
    pref_can[0] = 1;
    suff_can[len - 1] = 1;
    for (int i = 1;i < len;++i)
    {
        if (pref_bal[i] >= 0 && pref_can[i - 1] == 1)
        {
            pref_can[i] = 1;
        }
    }
    for (int i = len - 2;i >= 0;--i)
    {
        if (suff_bal[i] <= 0 && suff_can[i + 1] == 1)
        {
            suff_can[i] = 1;
        }
    }
    for (int i = 0;i < len;++i)
    {
        printf("%d ", pref_bal[i]);
    }
    printf("\n");
    for (int i = 0;i < len;++i)
    {
        printf("%d ", pref_can[i]);
    }
    printf("\n");
    for (int i = 0;i < len;++i)
    {
        printf("%d ", suff_bal[i]);
    }
    printf("\n");
    for (int i = 0;i < len;++i)
    {
        printf("%d ", suff_can[i]);
    }
    printf("\n");

    int res = 0;
    if (str[0] == '(')
    {
        if (suff_can[1] && suff_bal[1] + 1 == 0)
        {
            ++res;
        }
    }
    else
    {
        if (suff_can[1] && suff_bal[1] - 1 == 0)
        {
            ++res;
        }
    }
    if (str[len - 1] == '(')
    {
        if (pref_can[len - 2] && pref_bal[len - 2] + 1 == 0)
        {
            ++res;
        }
    }
    else
    {
        if (pref_can[len - 2] && pref_bal[len - 2] - 1 == 0)
        {
            ++res;
        }
    }
    for (int i = 1;i < len - 1;++i)
    {
        if (pref_can[i - 1] && suff_can[i + 1])
        {
            if (str[i] == '(')
            {
                if (pref_bal[i - 1] - 1 + suff_bal[i + 1] == 0)
                {
                    ++res;
                }
            }
            else
            {
                if (pref_bal[i - 1] + 1 + suff_bal[i + 1] == 0)
                {
                    ++res;
                }
            }
        }
    }

    printf("%d\n", res);

    free(str);
    free(pref_bal);
    free(pref_can);
    free(suff_bal);
    free(suff_can);
    return 0;
}