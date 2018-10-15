#include <stdio.h>

void max_sub_sum(int *array, int len)
{
    int max = -1;
    int max_i = 0;
    int max_j = len - 1;

    for (int i = 0;i < len;++i)
    {
        int sum = 0;
        for (int j = i;j < len;++j)
        {
            sum += array[j];
            if (sum > max)
            {
                max = sum;
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("%d %d %d\n", max, array[max_i], array[max_j]);
    return;
}

int main(int argc, char const *argv[])
{
    int array[20000] = {0};
    int total_num = 0;
    int num = 0;
    int flag = 0;
    scanf("%d", &total_num);
    for (int i = 0;i < total_num;++i)
    {
        scanf("%d", &num);
        if (num >= 0)
        {
            flag = 1;
        }
        array[i] = num;
    }
    if (!flag)
    {
        printf("%d %d %d\n", 0, array[0], array[total_num - 1]);
    }
    else
    {
        max_sub_sum(array, total_num);
    }

    return 0;
}
