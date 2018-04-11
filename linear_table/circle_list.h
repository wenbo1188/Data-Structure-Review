#ifndef __CIRCLE_LIST_H__
#define __CIRCLE_LIST_H__

typedef struct single_circle_node
{
	char ch;
	struct single_circle_node *next;
} *single_circle_list, single_circle_node;

void init_single_circle_list(single_circle_list head);
int insert_node_single_circle_list(single_circle_list head, single_circle_node *node);
void traverse_single_circle_list(single_circle_list head);
void destroy_single_circle_list(single_circle_list head);

#endif
