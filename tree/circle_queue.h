#ifndef __CIRCLE_QUEUE_H__
#define __CIRCLE_QUEUE_H__

#include "binarytree.h"

#define MAXSIZE 20
typedef pbtree btreeElemtype;

typedef struct circle_queue
{
    btreeElemtype data[MAXSIZE];
    int front, rear;
}circle_queue;

void init_queue(circle_queue *queue);
void enqueue(circle_queue *queue, btreeElemtype elem);
btreeElemtype dequeue(circle_queue *queue);
int isqueueempty(circle_queue queue);

#endif