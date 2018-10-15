#include <stdio.h>

enum
{
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9
};

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

int main()
{
    char words[10][10] = {
        [ZERO] = "zero",
        [ONE] = "one",
        [TWO] = "two",
        [THREE] = "three",
        [FOUR] = "four",
        [FIVE] = "five",
        [SIX] = "six",
        [SEVEN] = "seven",
        [EIGHT] = "eight",
        [NINE] = "nine"
    };

    char strnum[150] = {0};
    int sum = 0;
    scanf("%s", &strnum);

    char *p = NULL;
    p = strnum;
    while (p[0] != '\0')
    {
        sum += p[0] - '0';
        ++p;
    }
    // printf("%d\n", sum);
    int k = 0;
    int j = 4;
    if (sum == 0)
    {
        printf("zero\n");
        return 0;
    }
    if (sum == 1)
    {
        printf("one\n");
        return 0;
    }
    while (sum <= power(10, j))
    {
        --j;
    }
    while (j >= 0)
    {
        k = sum / power(10, j);
        if (j != 0)
        {
            printf("%s ", words[k]);
        }
        else
        {
            printf("%s", words[k]);
        }
        sum = sum - k * power(10, j);
        --j;
    }

    printf("\n");
    return 0;
}