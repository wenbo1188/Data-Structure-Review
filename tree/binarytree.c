#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"
#include "seqstack.h"
#include "circle_queue.h"

void create_tree(btree *tree, int num, int index)
{
    tree->value = index;
    tree->lchild = NULL;
    tree->rchild = NULL;
    index = 2 * tree->value;
    if (index > num)
    {
        return;
    }
    tree->lchild = (btree_node *)malloc(sizeof(btree_node));
    create_tree(tree->lchild, num, index);
    index = 2 * tree->value + 1;
    if (index > num)
    {
        return;
    }
    tree->rchild = (btree_node *)malloc(sizeof(btree_node));
    create_tree(tree->rchild, num, index);

    return;
}

void free_tree(btree *tree)
{
    if (!tree)
    {
        return;
    }

    if (tree->lchild)
    {
        free_tree(tree->lchild);
    }

    if (tree->rchild)
    {
        free_tree(tree->rchild);
    }

    free(tree);
    return;
}

void recur_first_seq(btree *tree)
{
    if (tree)
    {
        printf("%d\n", tree->value);
        recur_first_seq(tree->lchild);
        recur_first_seq(tree->rchild);
    }
    return;
}

void recur_middle_seq(btree *tree)
{
    if (tree)
    {
        recur_middle_seq(tree->lchild);
        printf("%d\n", tree->value);
        recur_middle_seq(tree->rchild);
    }
    return;
}

void recur_last_seq(btree *tree)
{
    if (tree)
    {
        recur_last_seq(tree->lchild);
        recur_last_seq(tree->rchild);
        printf("%d\n", tree->value);
    }
    return;
}

void nonrecur_first_seq(btree *tree)
{
    seqstack stack = {0};
    init_stack(&stack);
    btree *p = tree;
    while (p || !isstackempty(stack))
    {
        if (p)
        {
            printf("%d ", p->value);
            push(&stack, (Elemtype)p);
            p = p->lchild;
        }
        else
        {
            p = (btree *)pop(&stack);
            p = p->rchild;
        }
    }
    printf("\n");
    
    return;
}

void nonrecur_middle_seq(btree *tree)
{
    seqstack stack = {0};
    init_stack(&stack);
    btree *p = tree;
    while (p || !isstackempty(stack))
    {
        if (p)
        {
            push(&stack, (Elemtype)p);
            p = p->lchild;
        }
        else
        {
            p = (btree *)pop(&stack);
            printf("%d ", p->value);
            p = p->rchild;
        }
    }
    printf("\n");
    
    return;
}

void nonrecur_last_seq(btree *tree)
{
    seqstack stack = {0};
    init_stack(&stack);
    btree *p = tree;
    btree *r = NULL;

    while (p || !isstackempty(stack))
    {
        if (p)
        {
            push(&stack, (Elemtype)p);
            p = p->lchild;
        }
        else
        {
            p = (btree *)gettop(stack);
            if (p->rchild && r != p->rchild)
            {
                p = p->rchild;
            }
            else
            {
                p = (btree *)pop(&stack);
                printf("%d ", p->value);
                r = p;
                p = NULL;
            }
        }
    }
    printf("\n");

    return;
}

void level_order(btree *tree)
{
    circle_queue queue = {0};
    btree *p = NULL;
    init_queue(&queue);
    enqueue(&queue, tree);
    while (!isqueueempty(queue))
    {
        p = dequeue(&queue);
        printf("%d ", p->value);
        if (p->lchild)
        {
            enqueue(&queue, p->lchild);
        }
        if (p->rchild)
        {
            enqueue(&queue, p->rchild);
        }
    }
    printf("\n");

    return;
}

void bst_insert(pbtree *tree, int elem)
{
    if (!(*tree))
    {
        (*tree) = (btree_node *)malloc(sizeof(btree_node));
        (*tree)->value = elem;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
        return;
    }

    if (elem <= (*tree)->value)
    {
        bst_insert(&((*tree)->lchild), elem);
    }
    else
    {
        bst_insert(&((*tree)->rchild), elem);
    }

    return;
}

pbtree create_bst_tree(int *array, int len)
{
    pbtree tree = NULL;
    if (!array)
    {
        printf("Invalid parameter\n");
        return NULL;
    }

    for (int i = 0;i < len;++i)
    {
        bst_insert(&tree, array[i]);
    }

    return tree;
}

pbtree bst_search(btree *tree, int elem)
{
    pbtree p = tree;
    while (p && p->value != elem)
    {
        if (p->value < elem)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    
    return p;
}

void bst_delete(pbtree *tree, int elem)
{
    if (*tree == NULL)
    {
        return;
    }

    if ((*tree)->value > elem)
    {
        bst_delete(&((*tree)->lchild), elem);
    }
    else if ((*tree)->value < elem)
    {
        bst_delete(&((*tree)->rchild), elem);
    }
    else
    {
        if (!(*tree)->lchild)
        {
            pbtree tmp = *tree;
            *tree = (*tree)->rchild;
            free(tmp);
        }
        else if (!(*tree)->rchild)
        {
            pbtree tmp = *tree;
            *tree = (*tree)->lchild;
            free(tmp);
        }
        else
        {
            pbtree tmp = (*tree)->lchild;
            while (tmp->rchild)
            {
                tmp = tmp->rchild;
            }
            (*tree)->value = tmp->value;
            bst_delete(&((*tree)->lchild), tmp->value);
        }
    }

    return;
}