#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__

typedef struct dlinknode
{
    int data;
    struct dlinknode *prev;
    struct dlinknode *next;
}dlinknode;

typedef struct dlinklist
{
    dlinknode head;
    dlinknode tail;
}dlinklist;

void list_head_insert(dlinklist *list, dlinknode *node);
void list_tail_insert(dlinklist *list, dlinknode *node);
void list_front_insert(dlinklist *list, int index, dlinknode *node);
void list_delete(dlinklist *list, int index);
dlinknode *get_elem(dlinklist list, int index);
void head_traverse(dlinklist list);
void tail_traverse(dlinklist list);

#endif