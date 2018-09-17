#include <stdio.h>
#include "graph_matrix_weight.h"

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

void add_directed_edges(GRAPH_MATRIX *matrix, VER_TYPE from, VER_TYPE to, int weight)
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

    matrix->edges[index_from][index_second] = weight;
    matrix->edge_num++;

    return;
}

void add_nondirected_edges(GRAPH_MATRIX *matrix, VER_TYPE first, VER_TYPE second, int weight)
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

    matrix->edges[index_first][index_second] = weight;
    matrix->edges[index_second][index_first] = weight;
    matrix->edge_num++;

    return;   
}

void directed_traverse(GRAPH_MATRIX matrix)
{
    for (int i = 0;i < matrix.ver_num;++i)
    {
        for (int j = 0;j < matrix.ver_num;++j)
        {
            if (matrix.edges[i][j] != 0)
            {
                printf("%c -> %c: %d\n", matrix.vertexs[i], matrix.vertexs[j], matrix.edges[i][j]);
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
            if (matrix.edges[i][j] != 0)
            {
                printf("%c <-> %c: %d\n", matrix.vertexs[i], matrix.vertexs[j], matrix.edges[i][j]);
            }
        }
    }
}

void mini_span_tree_prim(GRAPH_MATRIX matrix, VER_TYPE vertex)
{
    closedge close[MAX_VERTEXS] = {0};
    int k = get_vertex_index(matrix, vertex);
    if (k == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    close[k].vertex = vertex;
    close[k].lowcost = 0;
    for (int i = 0;i < matrix.ver_num;++i)
    {
        if (i != k)
        {
            if (matrix.edges[k][i] != 0)
            {
                close[i].vertex = matrix.vertexs[k];
                close[i].lowcost = matrix.edges[k][i];
            }
            else
            {
                close[i].lowcost = 65535;
            }
        }
    }
    for (int i = 0;i < matrix.ver_num;++i)
    {
        for (int j = 0;j < matrix.ver_num;++j)
        {
            if (matrix.edges[i][j] == 0)
            {
                matrix.edges[i][j] = 65535;
            }
        }
    }

    for (int i = 1;i < matrix.ver_num;++i)
    {
        int min = 65535;
        for (int j = 0;j < matrix.ver_num;++j)
        {
            if (close[j].lowcost != 0 && close[j].lowcost < min)
            {
                min = close[j].lowcost;
                k = j;
            }
        }
        printf("%c -> %c\n", close[k].vertex, matrix.vertexs[k]);
        close[k].lowcost = 0;

        for (int j = 0;j < matrix.ver_num;++j)
        {
            if (matrix.edges[k][j] < close[j].lowcost)
            {
                close[j].lowcost = matrix.edges[k][j];
                close[j].vertex = matrix.vertexs[k];
            }
        }
    }

    return;
}

void dijkstra(GRAPH_MATRIX matrix, int *dist, int *path, VER_TYPE vertex)
{
    int s[MAX_VERTEXS] = {0};
    int start_index = 0;
    start_index = get_vertex_index(matrix, vertex);
    if (start_index == -1)
    {
        printf("Invalid vertex\n");
        return;
    }

    for(int i = 0;i < matrix.ver_num;++i)
    {
        for (int j = 0;j < matrix.ver_num;++j)
        {
            if (matrix.edges[i][j] == 0)
            {
                matrix.edges[i][j] = 65535;
            }
        }
    }

    for (int i = 0;i < matrix.ver_num;++i)
    {
        if (i != start_index)
        {
            if (matrix.edges[start_index][i] == 65535)
            {
                dist[i] = 65535;
                path[i] = -1;
            }
            else
            {
                dist[i] = matrix.edges[start_index][i];
                path[i] = start_index;
            }
        }
    }

    s[start_index] = 1;
    path[start_index] = -1;

    for (int j = 0;j < matrix.ver_num;++j)
    {
        int min = 65535;
        int k = 0;
        for (int i = 0;i < matrix.ver_num;++i)
        {
            if (s[i] != 1)
            {
                if (dist[i] < min)
                {
                    min = dist[i];
                    k = i;
                }
            }
        }
        s[k] = 1;
        for (int i = 0;i < matrix.ver_num;++i)
        {
            if (s[i] != 1 && dist[i] > (dist[k] + matrix.edges[k][i]))
            {
                dist[i] = dist[k] + matrix.edges[k][i];
                path[i] = k;
            }
        }
    }

    return;
}