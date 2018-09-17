#include <stdio.h>
#include "bfs.h"

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

void enqueue(circle_queue *queue, Elemtype elem)
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

Elemtype dequeue(circle_queue *queue)
{
    Elemtype tmp = {0};
    if (!queue || isqueueempty(*queue))
    {
        printf("Invalid parameter\n");
        return tmp;
    }

    tmp = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return tmp;
}

int isqueueempty(circle_queue queue)
{
    return queue.front == queue.rear;
}

void bfs_traverse(GRAPH_TABLE table, VER_TYPE start, int *visit)
{
    int start_index = 0;
    int ver_index = 0;
    circle_queue queue = {0};
    VERTEX ver = {0};
    EDGE_NODE *p = NULL;

    if (!visit)
    {
        printf("Invalid parameter\n");
        return;
    }

    start_index = get_vertex_index(table, start);
    if (start_index == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    init_queue(&queue);
    printf("%c ", table.vertexs[start_index].vertex);
    visit[start_index] = 1;
    enqueue(&queue, table.vertexs[start_index]);
    while (!isqueueempty(queue))
    {
        ver = dequeue(&queue);
        p = ver.edge;
        while (p)
        {
            if (visit[p->ver_index] != 1)
            {
                printf("%c ", table.vertexs[p->ver_index].vertex);
                visit[p->ver_index] = 1;
                enqueue(&queue, table.vertexs[p->ver_index]);
            }
            p = p->next;
        }
    }

    printf("\n");
}