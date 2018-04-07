#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef struct linknode
{
	int value;
	struct linknode *next;
} linknode, *linklist;

void init_linklist(linklist head);
void destroy_linklist(linklist head);
int insert_node_withhead(linklist head, linknode *node);
int insert_node_withouthead(linklist *head, linknode *node);
void linklist_traverse(linklist head);

/* LOCATE */
int linklist_locate(linklist l, int x);

/* LENGTH */
int linklist_length(linklist l);

/* link two list as one */
int linklist_link_two_list(linklist ha, int la, linklist hb, int lb, linklist *hc);

/* insert node in order */
int insert_node_order(linklist head, linknode *node);

/* delete between mink and maxk */
int delete_between(linklist head, int mink, int maxk);

/* delete repeat node */
int delete_repeat_node(linklist head);

/* reverse the linklist */
int linklist_reverse(linklist *head);

/* merge two lists in this way:
 * A = [a1, a2, ..., am]
 * B = [b1, b2, ..., bn]
 * then 
 * C = [a1, b1, a2, b2, ..., am, bm, bm+1, ..., bn] if n >= m
 * C = [a1, b1, a2, b2, ..., an, bn, an+1, ..., am] if n < m
 */
int linklist_cross_merge(linklist head1, linklist head2, linklist head3);

/* merge two lists in dsec order */
int linklist_dsec_merge(linklist head1, linklist head2, linklist head3);

#endif
