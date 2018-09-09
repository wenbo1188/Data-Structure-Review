#include <stdio.h>
#include <stdlib.h>
#include "dlinklist.h"

void list_head_insert(dlinklist *list, dlinknode *node)
{
    dlinknode *h = &list->head;

    if (!list || !node)
    {
        printf("Invalid parameter\n");
        return;
    }

    node->next = h->next;
    h->next->prev = node;
    h->next = node;
    node->prev = h;
    return;
}

void list_tail_insert(dlinklist *list, dlinknode *node)
{
    dlinknode *t = &list->tail;

    if (!list || !node)
    {
        printf("Invalid parameter\n");
        return;
    }

    node->prev = t->prev;
    t->prev->next = node;
    node->next = t;
    t->prev = node;
    return;
}

void head_traverse(dlinklist list)
{
    dlinknode *node = list.head.next;

    while (node->next)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");

    return;
}

void tail_traverse(dlinklist list)
{
    dlinknode *node = list.tail.prev;

    while (node->prev)
    {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");

    return;
}

dlinknode *get_elem(dlinklist list, int index)
{
    dlinknode *node = list.head.next;
    int i = 1;
    if (index <= 0)
    {
        printf("Invalid parameter\n");
        return NULL;
    }

    while (node->next)
    {
        if (i != index)
        {
            node = node->next;
            ++i;
        }
        else
        {
            return node;
        }
    }

    return NULL;
}

void list_front_insert(dlinklist *list, int index, dlinknode *node)
{
    if (index <= 0)
    {
        printf("Invalid parameter\n");
        return;
    }

    dlinknode *tmp = get_elem(*list, index);
    if (!tmp)
    {
        printf("Invalid paramter\n");
        return;
    }

    tmp->prev->next = node;
    node->prev = tmp->prev;
    node->next = tmp;
    tmp->prev = node;
    return;
}

void list_delete(dlinklist *list, int index)
{
    if (index <= 0)
    {
        printf("Invalid parameter\n");
        return;        
    }

    dlinknode *tmp = get_elem(*list, index);
    if (!tmp)
    {
        printf("Invalid paramter\n");
        return;
    }

    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    return;
}