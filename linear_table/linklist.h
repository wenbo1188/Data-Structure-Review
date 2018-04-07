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

/* LOCATE */
int linklist_locate(linklist l, int x);

/* LENGTH */
int linklist_length(linklist l);

/* link two list as one */
int linklist_link_two_list(linklist ha, int la, linklist hb, int lb, linklist *hc);

#endif
