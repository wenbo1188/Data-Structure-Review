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

int insert_node_withhead(linklist head, linknode *node)
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

int insert_node_withouthead(linklist *head, linknode *node)
{
	linklist p = NULL;

	if (!node)
	{
		printf("node is null\n");
		return -1;
	}

	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		p = *head;
		while (p->next)
		{
			p = p->next;
		}

		p->next = node;
		node->next = NULL;
	}

	return 0;
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

int insert_node_order(linklist head, linknode *node)
{
	linklist p = NULL;

	if (!head || !node)
	{
		printf("head or node is null\n");
		return -1;
	}

	p = head;
	while (p->next && p->next->value < node->value)
	{
		p = p->next;
	}

	node->next = p->next;
	p->next = node;

	return 0;
}

int delete_between(linklist head, int mink, int maxk)
{
	linklist left = NULL;
	linklist right = NULL;

	if (!head)
	{
		printf("head is null\n");
		return -1;
	}

	left = head;
	right = head;

	while (left->next && left->next->value <= mink)
	{
		left = left->next;
	}

	while (right->next && right->next->value < maxk)
	{
		right = right->next;
	}

	left->next = right->next;

	return 0;
}

int delete_repeat_node(linklist head)
{
	linklist p = NULL;
	linklist q = NULL;

	if (!head)
	{
		printf("head is null\n");
		return -1;
	}

	p = head->next;
	q = p->next;
	
	while (p && q)
	{
		if (p->value != q->value)
		{
			p->next = q;
			p = q;
			q = q->next;
		}
		else
		{
			q = q->next;
		}
	}

	p->next = NULL;
	
	return 0;
}

int linklist_reverse(linklist *head)
{
	linklist phead = NULL;
	linklist left = NULL;
	linklist right = NULL;
	linklist tmp = NULL;

	phead = *head;
	if (!phead)
	{
		printf("head is null\n");
		return -1;
	}

	left = phead->next;
	if (!left)
	{
		printf("no node in linklist\n");
		return 0;
	}

	right = left->next;
	if (!right)
	{
		printf("only one node in linklist, no need to reverse\n");
		return 0;
	}

	left->next = NULL;
	while (right)
	{
		tmp = right->next;
		right->next = left;
		left = right;
		right = tmp;
	}

	phead->next = left;
	*head = phead;

	return 0;
}

int linklist_cross_merge(linklist head1, linklist head2, linklist head3)
{
	linklist p1 = NULL;
	linklist p2 = NULL;
	linklist p3 = NULL;

	if (!head1 || !head2 || !head3)
	{
		printf("head1, head2, or head3 is null\n");
		return -1;
	}

	p1 = head1->next;
	p2 = head2->next;
	p3 = head3;

	while (p1 && p2)
	{
		p3->next = p1;
		p1 = p1->next;
		p3->next->next = p2;
		p2 = p2->next;
		p3 = p3->next->next;
	}

	if (p1)
	{
		while (p1)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
	}

	if (p2)
	{
		while (p2)
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}

	return 0;
}

int linklist_dsec_merge(linklist head1, linklist head2, linklist head3)
{
	linklist p1 = NULL;
	linklist p2 = NULL;
	linklist tmp = NULL;

	if (!head1 || !head2 || !head3)
	{
		printf("head1, head2 or head3 is null\n");
		return -1;
	}

	p1 = head1->next;
	p2 = head2->next;

	while (p1 && p2)
	{
		if (p1->value <= p2->value)
		{
			tmp = p1;
			p1 = p1->next;
		}
		else
		{
			tmp = p2;
			p2 = p2->next;
		}

		tmp->next = head3->next;
		head3->next = tmp;
	}

	if (p1)
	{
		while (p1)
		{
			tmp = p1;
			p1 = p1->next;
			tmp->next = head3->next;
			head3->next = tmp;
		}
	}

	if (p2)
	{
		while (p2)
		{
			tmp = p2;
			p2 = p2->next;
			tmp->next = head3->next;
			head3->next = tmp;
		}
	}

	return 0;
}
