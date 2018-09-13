#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef struct btree_node
{
    int value;
    struct btree_node *lchild;
    struct btree_node *rchild;
}btree_node, btree, *pbtree;

void create_tree(btree *tree, int num, int index);
void free_tree(btree *tree);
void recur_first_seq(btree *tree);
void recur_middle_seq(btree *tree);
void recur_last_seq(btree *tree);
void nonrecur_first_seq(btree *tree);
void nonrecur_middle_seq(btree *tree);
void nonrecur_last_seq(btree *tree);
void level_order(btree *tree);

/* BST tree */
pbtree create_bst_tree(int *array, int len);
pbtree bst_search(btree *tree, int elem);
void bst_delete(pbtree *tree, int elem);

#endif