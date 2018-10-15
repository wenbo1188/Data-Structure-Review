#include <stdio.h>
#include "sort.h"

void direct_insert_sort(int *array, int len)
{
    for (int i = 2;i < len;++i)
    {
        if (array[i] < array[i - 1])
        {
            array[0] = array[i];
            int j = 0;
            for (j = i - 1;array[j] > array[0];--j)
            {
                array[j + 1] = array[j];
            }
            array[j + 1] = array[0];
        }
    }

    return;
}

void half_insert_sort(int *array, int len)
{
    int i = 0;
    int j = 0;
    int low, high, mid = 0;

    for (i = 2;i <= len;++i)
    {
        array[0] = array[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (array[mid] > array[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (j = i - 1;j >= high + 1;--j)
        {
            array[j + 1] = array[j];
        }
        array[high + 1] = array[0];
    }

    return;
}

void shell_sort(int *array, int len)
{
    int d = 0;
    int i, j = 0;

    for (d = len / 2;d >= 1; d = d / 2)
    {
        for (i = d + 1;i <= len;++i)
        {
            if (array[i] < array[i - d])
            {
                array[0] = array[i];
                for (j = i - d;j > 0 && array[0] < array[j];j -= d)
                {
                    array[j + d] = array[j];
                }
                array[j + d] = array[0];
            }
        }
    }

    return;
}

int partition(int *array, int start, int end)
{
    int pivot = array[start];
    while (start < end)
    {
        while (start < end && array[end] >= pivot)
        {
            --end;
        }
        array[start] = array[end];
        while (start < end && array[start] <= pivot)
        {
            ++start;
        }
        array[end] = array[start];
    }
    array[start] = pivot;
    return start;
}

void quick_sort(int *array, int start, int end)
{
    if (start < end)
    {
        int mid = partition(array, start, end);
        quick_sort(array, start, mid - 1);
        quick_sort(array, mid + 1, end);
    }
    return;
}


void bubble_sort(int *array, int len)
{
    int flag = 0;
    for (int i = 0;i < len - 1;++i)
    {
        flag = 0;
        for (int j = 0;j < len - i - 1;++j)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = 1;
            }
        }
        if (!flag)
        {
            return;
        }
    }

    return;
}

int main(int argc, char const *argv[])
{
    int array[] = {0, 5, 4, 3, 2, 1};
    bubble_sort(array, 6);
    for (int i = 0;i < sizeof(array)/sizeof(int);++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
