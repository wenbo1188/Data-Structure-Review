#ifndef __CIRCLE_QUEUE_H__
#define __CIRCLE_QUEUE_H__

#define MAXSIZE 20

typedef struct circle_queue
{
    int data[MAXSIZE];
    int front, rear;
}circle_queue;

void init_queue(circle_queue *queue);
void enqueue(circle_queue *queue, int elem);
int dequeue(circle_queue *queue);
int isempty(circle_queue queue);

#endif