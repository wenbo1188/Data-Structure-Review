#include <stdio.h>
#include "seqstack.h"

void push(seqstack *stack, int elem)
{
    if (!stack)
    {
        printf("Invalid parameter\n");
        return;
    }

    if (stack->top == MAXSIZE - 1)
    {
        printf("The stack is full\n");
        return;
    }

    stack->data[++stack->top] = elem;
    return;
}

int pop(seqstack *stack)
{
    if (!stack || isempty(*stack))
    {
        printf("Invalid parameter\n");
        return -1;
    }

    return stack->data[stack->top--];
}

int gettop(seqstack stack)
{
    if (isempty(stack))
    {
        printf("Invalid parameter\n");
        return -1;
    }

    return stack.data[stack.top];
}

int isempty(seqstack stack)
{
    return stack.top == -1;
}