#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#define MAXSIZE 20

typedef struct seqstack
{
    int data[MAXSIZE];
    int top;
}seqstack;

void push(seqstack *stack, int elem);
int pop(seqstack *stack);
int gettop(seqstack stack);
int isempty(seqstack stack);

#endif