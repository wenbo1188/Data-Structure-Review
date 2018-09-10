#include <stdio.h>
#include "linkstack.h"

void push(linkstack *stack, stacknode *elem)
{
    elem->next = *stack;
    *stack = elem;
    return;
}

int pop(linkstack *stack)
{
    stacknode *tmp = NULL;

    if (!stack)
    {
        printf("Invalid parameter\n");
        return -1;        
    }

    tmp = *stack;
    *stack = (*stack)->next;
    return tmp->value;
}

int gettop(linkstack stack)
{
    if (!stack)
    {
        printf("Invalid parameter\n");
        return -1;        
    }

    return stack->value;
}

int isempty(linkstack stack)
{
    return stack == NULL;
}