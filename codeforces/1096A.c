#include <stdio.h>

typedef struct pair
{
    int low;
    int high;
}pair;

int main()
{
    int num = 0;
    scanf("%d", &num);
    pair bound[1000] = {0};
    for (int i = 0;i < num;++i)
    {
        scanf("%d %d", &bound[i].low, &bound[i].high);
    }
    for (int i = 0;i < num;++i)
    {
        printf("%d %d\n", bound[i].low, bound[i].low * 2);
    }
    return 0;
}