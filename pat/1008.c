#include <stdio.h>

#define UPCOST 6
#define DOWNCOST 4
#define STAYCOST 5

int main(int argc, char const *argv[])
{
    int num = 0;
    int curfloor = 0;
    int timecost = 0;
    int request[10000] = {0};

    scanf("%d", &num);
    for (int i = 0;i < num;++i)
    {
        scanf("%d", &request[i]);
    }

    for (int i = 0;i < num;++i)
    {
        if (curfloor == request[i])
        {
            timecost += STAYCOST;
        }
        else if (curfloor > request[i])
        {
            timecost += DOWNCOST * (curfloor - request[i]);
            timecost += STAYCOST;
            curfloor = request[i];
        }
        else
        {
            timecost += UPCOST * (request[i] - curfloor);
            timecost += STAYCOST;
            curfloor = request[i];
        }
    }

    printf("%d\n", timecost);
    return 0;
}
