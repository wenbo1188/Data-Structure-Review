#include <stdio.h>

int main()
{
    char str[100] = {0};
    char res[100] = {0};
    int num = 0;
    scanf("%d", &num);
    scanf("%s", str);
    int sum = 0;
    int i = 0;
    for (i = 0;sum < num;++i)
    {
        sum += i;
        res[i] = str[sum];
    }
    res[i] = '\0';
    printf("%s\n", res);

    return 0;
}