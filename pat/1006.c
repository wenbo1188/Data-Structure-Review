#include <stdio.h>

typedef struct
{
    int hour;
    int minute;
    int second;
}TIME;

typedef struct person
{
    char id[20];
    TIME signin;
    TIME signout;
}PERSON;

int main(int argc, char const *argv[])
{
    int num = 0;
    PERSON persons[10000] = {0};
    scanf("%d", &num);
    for (int i = 0;i < num;++i)
    {
        scanf("%s %d:%d:%d %d:%d:%d", persons[i].id, 
                &persons[i].signin.hour, &persons[i].signin.minute, &persons[i].signin.second,
                &persons[i].signout.hour, &persons[i].signout.minute, &persons[i].signout.second);
    }

    // for (int i = 0;i < num;++i)
    // {
    //     printf("%s %d:%d:%d %d:%d:%d\n", persons[i].id, 
    //             persons[i].signin.hour, persons[i].signin.minute, persons[i].signin.second,
    //             persons[i].signout.hour, persons[i].signout.minute, persons[i].signout.second);
    // }
    int earlest, latest = 0;
    TIME early = {65535, 65535, 65535};
    TIME late = {0};
    for (int i = 0;i < num;++i)
    {
        if ((persons[i].signin.hour < early.hour) ||
            (persons[i].signin.hour == early.hour && persons[i].signin.minute < early.minute) ||
            (persons[i].signin.hour == early.hour && persons[i].signin.minute == early.minute && persons[i].signin.second < early.second))
        {
            early.hour = persons[i].signin.hour;
            early.minute = persons[i].signin.minute;
            early.second = persons[i].signin.second;
            earlest = i;
        }

        if ((persons[i].signout.hour > late.hour) ||
            (persons[i].signout.hour == late.hour && persons[i].signout.minute > late.minute) ||
            (persons[i].signout.hour == late.hour && persons[i].signout.minute == late.minute && persons[i].signout.second > late.second))
        {
            late.hour = persons[i].signout.hour;
            late.minute = persons[i].signout.minute;
            late.second = persons[i].signout.second;
            latest = i;
        }
    }

    printf("%s %s\n", persons[earlest].id, persons[latest].id);

    return 0;
}
