#include <stdio.h>

void sort(int *array, int index1, int index2)
{
    int tmp = 0;
    for (int i = 0;i < index2 - index1;++i)
    {
        for (int index = index1;index < index2 - i;++index)
        {
            if (array[index] > array[index + 1])
            {
                tmp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = tmp;
            }
        }
    }

    return;
}

int main()
{
    int num = 0;
    int array[100000] = {0};
    int result = 0;
    scanf("%d", &num);
    for (int i = 0;i < num;++i)
    {
        scanf("%d", &array[i]);
    }
    if (num == 2)
    {
        printf("%d\n", 0);
        return 0;
    }

    if (num == 3)
    {
        int a = array[2] - array[1] > 0 ? array[2] - array[1] : array[1] - array[2];
        int b = array[2] - array[0] > 0 ? array[2] - array[0] : array[0] - array[2];
        int c = array[1] - array[0] > 0 ? array[1] - array[0] : array[0] - array[1];
        // printf("%d %d %d\n", a, b, c);
        if (a < b)
        {
            result = a > c ? c : a;
        }
        else
        {
            result = b > c ? c : b;
        }
        printf("%d\n", result);
    }

    if (num >= 4)
    {
        int min1 = 0;
        int min2 = 0;
        int max1 = 0;
        int max2 = 0;

        sort(array, 0, 3);
        min1 = array[0];
        min2 = array[1];
        max1 = array[2];
        max2 = array[3];
        // printf("%d %d %d %d\n", min1, min2, max1, max2);

        for (int i = 4;i < num;++i)
        {
            if (array[i] <= min1)
            {
                min2 = min1;
                min1 = array[i];
                continue;
            }

            if (array[i] > min1 && array[i] < min2)
            {
                min2 = array[i];
                continue;
            }
            
            if (array[i] > max1 && array[i] < max2)
            {
                max1 = array[i];
                continue;
            }

            if (array[i] >= max2)
            {
                max1 = max2;
                max2 = array[i];
                continue;
            }
        }

        printf("%d\n", max2 - min2 > max1 - min1 ? max1 - min1 : max2 - min2);
    }

    return 0;
}