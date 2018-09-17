#include <stdio.h>
#include "graph_matrix.h"

void add_vertex(GRAPH_MATRIX *matrix, VER_TYPE vertex)
{
    if (!matrix || matrix->ver_num >= MAX_VERTEXS)
    {
        printf("Invalid parameter\n");
        return;
    }

    matrix->vertexs[matrix->ver_num++] = vertex;
    return;
}

static int get_vertex_index(GRAPH_MATRIX matrix, VER_TYPE vertex)
{
    int index = 0;
    for (index = 0;index < matrix.ver_num;++index)
    {
        if (matrix.vertexs[index] == vertex)
        {
            return index;
        }
    }

    return -1;
}

void add_directed_edges(GRAPH_MATRIX *matrix, VER_TYPE from, VER_TYPE to)
{
    int index_from = 0;
    int index_second = 0;

    if (!matrix)
    {
        printf("Invalid parameter\n");
        return;
    }

    index_from = get_vertex_index(*matrix, from);
    if (index_from == -1)
    {
        printf("Invalid vertex\n");
        return;
    }
    index_second = get_vertex_index(*matrix, to);
    if (index_second == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    matrix->edges[index_from][index_second] = 1;
    matrix->edge_num++;

    return;
}

void add_nondirected_edges(GRAPH_MATRIX *matrix, VER_TYPE first, VER_TYPE second)
{
    int index_first = 0;
    int index_second = 0;

    if (!matrix)
    {
        printf("Invalid parameter\n");
        return;
    }

    index_first = get_vertex_index(*matrix, first);
    if (index_first == -1)
    {
        printf("Invalid vertex\n");
        return;
    }
    index_second = get_vertex_index(*matrix, second);
    if (index_second == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    matrix->edges[index_first][index_second] = 1;
    matrix->edges[index_second][index_first] = 1;
    matrix->edge_num++;

    return;   
}

void directed_traverse(GRAPH_MATRIX matrix)
{
    for (int i = 0;i < matrix.ver_num;++i)
    {
        for (int j = 0;j < matrix.ver_num;++j)
        {
            if (matrix.edges[i][j] == 1)
            {
                printf("%c -> %c\n", matrix.vertexs[i], matrix.vertexs[j]);
            }
        }
    }
}

void nondirected_traverse(GRAPH_MATRIX matrix)
{
    for (int i = 0;i < matrix.ver_num;++i)
    {
        for (int j = 0;j < i;++j)
        {
            if (matrix.edges[i][j] == 1)
            {
                printf("%c <-> %c\n", matrix.vertexs[i], matrix.vertexs[j]);
            }
        }
    }
}