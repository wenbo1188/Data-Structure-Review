#include <stdio.h>
#include <stdlib.h>
#include "circle_list.h"

void init_single_circle_list(single_circle_list head)
{
	head->ch = 0;
	head->next = head;
	return;
}

int insert_node_single_circle_list(single_circle_list head, single_circle_node *node)
{
	single_circle_list p = NULL;

	if (!head || !node)
	{
		printf("head or node is null\n");
		return -1;
	}

	p = head;
	while (p->next != head)
	{
		p = p->next;
	}

	p->next = node;
	node->next = head;

	return 0;
}

void traverse_single_circle_list(single_circle_list head)
{
	single_circle_list p = NULL;

	if (!head)
	{
		printf("head is null\n");
		return;
	}

	p = head->next;
	while (p != head)
	{
		printf("%c ", p->ch);
		p = p->next;
	}
	printf("\n");

	return;
}

void destroy_single_circle_list(single_circle_list head)
{
	if (head)
	{
		free(head);
	}

	return;
}
