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
