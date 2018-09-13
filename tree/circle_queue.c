#include <stdio.h>
#include "circle_queue.h"

void init_queue(circle_queue *queue)
{
    if (!queue)
    {
        printf("Invalid parameter\n");
        return;
    }

    queue->front = 0;
    queue->rear = 0;
    return;
}

void enqueue(circle_queue *queue, btreeElemtype elem)
{
    if (!queue)
    {
        printf("Invalid parameter\n");
        return;
    }

    if ((queue->rear + 1) % MAXSIZE == queue->front)
    {
        printf("The queue is full\n");
        return;
    }

    queue->data[queue->rear] = elem;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return;
}

btreeElemtype dequeue(circle_queue *queue)
{
    btreeElemtype tmp = NULL;
    if (!queue || isqueueempty(*queue))
    {
        printf("Invalid parameter\n");
        return NULL;
    }

    tmp = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return tmp;
}

int isqueueempty(circle_queue queue)
{
    return queue.front == queue.rear;
}