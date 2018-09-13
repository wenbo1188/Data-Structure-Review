#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#define MAXSIZE 20
typedef int Elemtype;

typedef struct seqstack
{
    Elemtype data[MAXSIZE];
    Elemtype top;
}seqstack;

void init_stack(seqstack *stack);
void push(seqstack *stack, Elemtype elem);
Elemtype pop(seqstack *stack);
Elemtype gettop(seqstack stack);
int isstackempty(seqstack stack);

#endif