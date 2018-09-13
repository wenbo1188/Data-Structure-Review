#include <stdio.h>
#include "seqstack.h"

void init_stack(seqstack *stack)
{
    stack->top = -1;
}

void push(seqstack *stack, Elemtype elem)
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

Elemtype pop(seqstack *stack)
{
    if (!stack || isstackempty(*stack))
    {
        printf("Invalid parameter\n");
        return -1;
    }

    return stack->data[stack->top--];
}

Elemtype gettop(seqstack stack)
{
    if (isstackempty(stack))
    {
        printf("Invalid parameter\n");
        return -1;
    }

    return stack.data[stack.top];
}

int isstackempty(seqstack stack)
{
    return stack.top == -1;
}