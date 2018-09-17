#include <stdio.h>
#include "dfs.h"

void dfs_traverse(GRAPH_TABLE table, VER_TYPE start, int *visit)
{
    int start_index = 0;
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

    printf("%c\n", table.vertexs[start_index].vertex);
    visit[start_index] = 1;
    p = table.vertexs[start_index].edge;
    while (p)
    {
        if (visit[p->ver_index] != 1)
        {
            dfs_traverse(table, table.vertexs[p->ver_index].vertex, visit);
        }
        p = p->next;
    }

    return;
}

