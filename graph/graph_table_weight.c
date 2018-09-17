#include <stdio.h>
#include <stdlib.h>
#include "graph_table_weight.h"

void add_vertex(GRAPH_TABLE *table, VER_TYPE vertex)
{
    if (!table || table->ver_num >= MAX_VERTEXS)
    {
        printf("Invalid parameter\n");
        return;
    }

    table->vertexs[table->ver_num++].vertex = vertex;
    return;
}

int get_vertex_index(GRAPH_TABLE table, VER_TYPE vertex)
{
    int index = 0;
    for (index = 0;index < table.ver_num;++index)
    {
        if (table.vertexs[index].vertex == vertex)
        {
            return index;
        }
    }

    return -1;
}

void add_directed_edges(GRAPH_TABLE *table, VER_TYPE from, VER_TYPE to, int weight)
{
    int index_first = 0;
    int index_second = 0;
    EDGE_NODE *node = NULL;
    EDGE_NODE *p = NULL;

    if (!table)
    {
        printf("Invalid parameter\n");
        return;
    }

    index_first = get_vertex_index(*table, from);
    if (index_first == -1)
    {
        printf("Invalid vertex\n");
        return;
    }
    index_second = get_vertex_index(*table, to);
    if (index_second == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    node = (EDGE_NODE *)malloc(sizeof(EDGE_NODE));
    node->next = NULL;
    node->ver_index = index_second;
    node->weight = weight;

    if (table->vertexs[index_first].edge == NULL)
    {
        table->vertexs[index_first].edge = node;
    }
    else
    {
        p = table->vertexs[index_first].edge;
        while (p->next)
        {
            p = p->next;
        }
        p->next = node;
    }

    return;
}

void add_nondirected_edges(GRAPH_TABLE *table, VER_TYPE first, VER_TYPE second, int weight)
{
    int index_first = 0;
    int index_second = 0;
    EDGE_NODE *node = NULL;
    EDGE_NODE *p = NULL;

    if (!table)
    {
        printf("Invalid parameter\n");
        return;
    }

    index_first = get_vertex_index(*table, first);
    if (index_first == -1)
    {
        printf("Invalid vertex\n");
        return;
    }
    index_second = get_vertex_index(*table, second);
    if (index_second == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    node = (EDGE_NODE *)malloc(sizeof(EDGE_NODE));
    node->next = NULL;
    node->ver_index = index_second;
    node->weight = weight;

    if (table->vertexs[index_first].edge == NULL)
    {
        table->vertexs[index_first].edge = node;
    }
    else
    {
        p = table->vertexs[index_first].edge;
        while (p->next)
        {
            p = p->next;
        }
        p->next = node;
    }

    node = (EDGE_NODE *)malloc(sizeof(EDGE_NODE));
    node->next = NULL;
    node->ver_index = index_first;
    node->weight = weight;

    if (table->vertexs[index_second].edge == NULL)
    {
        table->vertexs[index_second].edge = node;
    }
    else
    {
        p = table->vertexs[index_second].edge;
        while (p->next)
        {
            p = p->next;
        }
        p->next = node;
    }

    return;
}

void directed_traverse(GRAPH_TABLE table)
{
    EDGE_NODE *p = NULL;
    for (int i = 0;i < table.ver_num;++i)
    {
        if (table.vertexs[i].edge)
        {
            p = table.vertexs[i].edge;
            while (p)
            {
                printf("%c -> %c: %d\n", table.vertexs[i].vertex, table.vertexs[p->ver_index].vertex, p->weight);
                p = p->next;
            }
        }
    }

    return;
}

void nondirected_traverse(GRAPH_TABLE table)
{
    EDGE_NODE *p = NULL;
    for (int i = 0;i < table.ver_num;++i)
    {
        if (table.vertexs[i].edge)
        {
            p = table.vertexs[i].edge;
            while (p)
            {
                printf("%c <-> %c: %d\n", table.vertexs[i].vertex, table.vertexs[p->ver_index].vertex, p->weight);
                p = p->next;
            }
        }
    }
}

void free_graph(GRAPH_TABLE *table)
{
    EDGE_NODE *p = NULL;
    EDGE_NODE *tmp = NULL;

    if (!table)
    {
        return;
    }

    for (int i = 0;i < table->ver_num;++i)
    {
        p = table->vertexs[i].edge;
        while (p)
        {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }

    return;
}

void mini_span_tree_prim(GRAPH_TABLE table, VER_TYPE vertex)
{
    closedge close[MAX_VERTEXS] = {0};
    EDGE_NODE *p = NULL;
    int k = get_vertex_index(table, vertex);
    if (k == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    /* init supporting array close */
    p = table.vertexs[k].edge;
    while (p)
    {
        close[p->ver_index].vertex = vertex;
        close[p->ver_index].lowcost = p->weight;
        p = p->next;
    }
    for (int i = 0;i < table.ver_num;++i)
    {
        if (i != k && close[i].lowcost == 0)
        {
            close[i].lowcost = 65535;
        }
    }

    for (int i = 1;i < table.ver_num;++i)
    {
        /* find the least cost edge */
        int min = 65535;
        for (int j = 0;j < table.ver_num;++j)
        {
            if (close[j].lowcost != 0 && close[j].lowcost < min)
            {
                min = close[j].lowcost;
                k = j;
            }
        }
        printf("%c -> %c\n", close[k].vertex, table.vertexs[k].vertex);
        close[k].lowcost = 0;

        /* update lowcost after new insert */
        p = table.vertexs[k].edge;
        while (p)
        {
            if (p->weight < close[p->ver_index].lowcost)
            {
                close[p->ver_index].lowcost = p->weight;
                close[p->ver_index].vertex = table.vertexs[k].vertex;
            }
            p = p->next;
        }
    }

    return;
}