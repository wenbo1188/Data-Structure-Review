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

void enqueue(circle_queue *queue, int elem)
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

int dequeue(circle_queue *queue)
{
    int tmp = 0;
    if (!queue || isempty(*queue))
    {
        printf("Invalid parameter\n");
        return -1;
    }

    tmp = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return tmp;
}

int isempty(circle_queue queue)
{
    return queue.front == queue.rear;
}