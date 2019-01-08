#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#define UPCOST 6
#define DOWNCOST 4
#define STAYCOST 5

int myprintf(const char *format, ...)
{
    va_list va;
    int cnt;

    va_start(va, format);
    cnt = vprintf(format, va);
    va_end(va);

    return cnt;
}

int main(int argc, char const *argv[])
{
    int value = 1;
    char *str = "test123";
    bool flag = true;
    myprintf("value is %d, str is %s\n", value, str);
    if (true)
    {
        printf("bool is ok\n");
    }

    return 0;
    // int num = 0;
    // int curfloor = 0;
    // int timecost = 0;
    // int request[10000] = {0};

    // scanf("%d", &num);
    // for (int i = 0;i < num;++i)
    // {
    //     scanf("%d", &request[i]);
    // }

    // for (int i = 0;i < num;++i)
    // {
    //     if (curfloor == request[i])
    //     {
    //         timecost += STAYCOST;
    //     }
    //     else if (curfloor > request[i])
    //     {
    //         timecost += DOWNCOST * (curfloor - request[i]);
    //         timecost += STAYCOST;
    //         curfloor = request[i];
    //     }
    //     else
    //     {
    //         timecost += UPCOST * (request[i] - curfloor);
    //         timecost += STAYCOST;
    //         curfloor = request[i];
    //     }
    // }

    // printf("%d\n", timecost);
    // return 0;
}
