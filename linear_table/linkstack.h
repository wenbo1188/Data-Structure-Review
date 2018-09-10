#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

typedef struct stacknode
{
    int value;
    struct stacknode *next;
}*linkstack, stacknode;

void push(linkstack *stack, stacknode *elem);
int pop(linkstack *stack);
int gettop(linkstack stack);
int isempty(linkstack stack);

#endif