#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef struct linknode
{
	int value;
	struct linknode *next;
} linknode, *linklist;

void init_linklist(linklist head);
void destroy_linklist(linklist head);
int insert_node(linklist head, linknode *node);
void linklist_traverse(linklist head);

#endif
