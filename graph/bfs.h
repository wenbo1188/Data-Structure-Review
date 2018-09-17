#ifndef __BFS_H__
#define __BFS_H__

#include "graph_table.h"

#define MAXSIZE 20
typedef VERTEX Elemtype;

typedef struct circle_queue
{
    Elemtype data[MAXSIZE];
    int front, rear;
}circle_queue;

void init_queue(circle_queue *queue);
void enqueue(circle_queue *queue, Elemtype elem);
Elemtype dequeue(circle_queue *queue);
int isqueueempty(circle_queue queue);

void bfs_traverse(GRAPH_TABLE table, VER_TYPE start, int *visit);

#endif