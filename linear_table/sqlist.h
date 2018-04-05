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
void sqlist_traverse(sqlist *list);

/* delete k numbers after pos i(including i) */
int DeleteK(sqlist *list, int i, int k);

/* compare two sqlist 
 * Example:
 *    if A = [1, 2], B = [1, 2, 1] then A < B
 *    if A = [1, 2], B = [1, 3] then A < B
 *    if A = [1, 2], B = [1, 2] then A = B
 */
int list_compare(sqlist *list1, sqlist *list2);

#endif
