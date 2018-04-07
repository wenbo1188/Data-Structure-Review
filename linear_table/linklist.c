#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

void init_linklist(linklist head)
{
	if (!head)
	{
		printf("head is null\n");
		return;
	}

	head->value = 0;
	head->next = NULL;
	
	return;
}

void destroy_linklist(linklist head)
{
	if (head)
	{
		free(head);
	}

	return;
}

int insert_node(linklist head, linknode *node)
{
	linklist p = NULL;

	if (!head || !node)
	{
		printf("head or node is null\n");
		return -1;
	}

	p = head;
	while (p->next)
	{
		p = p->next;
	}

	p->next = node;
	node->next = NULL;
}

void linklist_traverse(linklist head)
{
	linklist p = NULL;

	if (!head)
	{
		printf("head is null\n");
		return;
	}

	p = head->next;
	while (p)
	{
		printf("%d ", p->value);
		p = p->next;
	}

	printf("\n");
}

int linklist_locate(linklist head, int elem)
{
	linklist p = NULL;
	int pos = 0;

	if (!head)
	{
		printf("head is null\n");
		return -1;
	}

	p = head->next;
	while (p)
	{
		pos++;

		if (p->value == elem)
		{
			return pos;
		}

		p = p->next;
	}

	return -1;
}

int linklist_length(linklist head)
{
	linklist p = NULL;
	int length = 0;

	if (!head)
	{
		printf("head is null\n");
		return 0;
	}

	p = head->next;
	while (p)
	{
		length++;
		p = p->next;
	}

	return length;
}

int linklist_link_two_list(linklist ha, int la, linklist hb, int lb, linklist *hc)
{
	linklist first = NULL;
	linklist second = NULL;
	linklist p = NULL;

	if (!ha || !hb)
	{
		printf("ha or hb is null\n");
		return -1;
	}

	if (la <= lb)
	{
		first = ha;
		second = hb;
	}
	else
	{
		first = hb;
		second = ha;
	}

	p = first;
	while (p->next)
	{
		p = p->next;
	}

	if (second->next)
	{
		p->next = second->next;
	}

	*hc = first;
	return 0;
}
