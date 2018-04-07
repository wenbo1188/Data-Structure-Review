#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

int create_table(sqlist *list)
{
	if (!list)
	{
		printf("list is null\n");
		return -1;
	}

	list->table = malloc(sizeof(int) * LIST_INIT_SIZE);
	if (!list->table)
	{
		printf("malloc failed\n");
		return -1;
	}

	list->volume = LIST_INIT_SIZE;
	list->cur_length = 0;

	return 0;
}

void destroy_table(sqlist *list)
{
	if (list && list->table)
	{
		free(list->table);
		list->table = NULL;
		list->cur_length = 0;
		list->volume = 0;
	}

	return;
}

static int copy_list(sqlist *dst, sqlist *src)
{
	int i = 0;

	if (dst->volume < src->cur_length)
	{
		return -1;
	}

	for (i = 0;i < src->cur_length;++i)
	{
		dst->table[i] = src->table[i];
	}
	dst->cur_length = src->cur_length;
	
	return 0;
}

static int realloc_list(sqlist *list)
{
	sqlist *tmp = NULL;
	int ret = 0;

	tmp = list;
	list->table = malloc((list->volume + LISTINCREMENT) * sizeof(int));
	if (!list->table)
	{
		printf("malloc failed\n");
		return -1;
	}

	list->volume += LISTINCREMENT;
	ret = copy_list(list, tmp);
	if (ret != 0)
	{
		return -1;
	}
	destroy_table(tmp);

	return 0;
}

int insert_elem(sqlist *list, int elem)
{
	sqlist *tmp = NULL;
	int ret = 0;

	if (!list)
	{
		printf("list is null\n");
		return -1;
	}
	
	/* relloc list */
	if (list->cur_length == list->volume)
	{
		ret = realloc_list(list);
		if (ret != 0)
		{
			printf("realloc list failed\n");
			return -1;
		}
	}

	list->table[list->cur_length] = elem;
	list->cur_length += 1;
	
	return 0;
}

int list_empty(sqlist *list)
{
	return list->cur_length ? 0 : 1;
}

int insert_elem_order(sqlist *list, int elem)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	if (!list)
	{
		printf("list is null\n");
		return -1;
	}

	/* relloc list */
	if (list->cur_length == list->volume)
	{
		ret = realloc_list(list);
		if (ret != 0)
		{
			printf("realloc list failed\n");
			return -1;
		}
	}

	if (list_empty(list))
	{
		list->table[list->cur_length] = elem;
		list->cur_length += 1;
	}
	else
	{
		/* insert elem */
		for (i = 0;i < list->cur_length;++i)
		{
			if (list->table[i] > elem)
			{
				break;
			}
		}

		for (j = list->cur_length;j >= i;--j)
		{
			list->table[j + 1] = list->table[j];
		}

		list->table[i] = elem;
		list->cur_length += 1;
	}

	return 0;
}

void sqlist_traverse(sqlist *list)
{
	int i = 0;

	if (!list)
	{
		printf("list is null\n");
		return;
	}

	for (i = 0;i < list->cur_length;++i)
	{
		printf("%d ", list->table[i]);
	}

	printf("\n");
	return;
}

int DeleteK(sqlist *list, int i, int k)
{
	int index = 0;

	if (!list)
	{
		printf("list is null\n");
		return -1;
	}

	if (k < 0 || i < 1 || list->cur_length < i || list->cur_length < i + k - 1)
	{
		printf("Invalid parameter\n");
		return -1;
	}

	for (index = i + k - 1;index < list->cur_length;++index)
	{
		list->table[index - k] = list->table[index];
	}

	list->cur_length -= k;

	return 0;
}

/* compare two sqlist 
 * Example:
 *    if A = [1, 2], B = [1, 2, 1] then A < B
 *    if A = [1, 2], B = [1, 3] then A < B
 *    if A = [1, 2], B = [1, 2] then A = B
 * Return: 1 if list1 > list2
 *         0 if list1 = list2
 *         -1 if list1 < list2
 */
int list_compare(sqlist *list1, sqlist *list2)
{
	int i = 0;
	int j = 0;
	
	if (!list1 || !list2)
	{
		printf("list is null\n");
		return 0;
	}

	if (list1->cur_length == 0 && list2->cur_length == 0)
	{
		return 0;
	}

	if (list1->cur_length == 0 && list2->cur_length > 0)
	{
		return -1;
	}

	if (list2->cur_length == 0 && list1->cur_length > 0)
	{
		return 1;
	}

	while (i < list1->cur_length && j < list2->cur_length)
	{
		if (list1->table[i] == list2->table[j])
		{
			++i;
			++j;
			continue;
		}

		if (list1->table[i] > list2->table[j])
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

	if (i == list1->cur_length && j == list2->cur_length)
	{
		return 0;
	}

	if (i < list1->cur_length && j == list2->cur_length)
	{
		return 1;
	}

	if (i == list1->cur_length && j < list2->cur_length)
	{
		return -1;
	}
}

int list_reverse(sqlist *list)
{
	int i = 0;
	int tmp = 0;
	int len = 0;

	if (!list)
	{
		printf("list is null\n");
		return -1;
	}

	len = list->cur_length;
	for (i = 0;i < len/2;++i)
	{
		tmp = list->table[i];
		list->table[i] = list->table[len - 1 - i];
		list->table[len - 1 - i] = tmp;
	}

	return 0;
}
