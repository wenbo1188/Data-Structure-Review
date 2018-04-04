#ifndef __SQLIST_H__
#define __SQLIST_H__

#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

typedef struct
{
	int *table;
	int cur_length;
	int volume;
}sqlist;

int create_table(sqlist *list);
void destroy_table(sqlist *list);
int list_empty(sqlist *list);
int insert_elem(sqlist *list, int elem);
int insert_elem_order(sqlist *list, int elem);
void traverse(sqlist *list);

/* delete k numbers after pos i(including i) */
int DeleteK(sqlist *list, int i, int k);

#endif
