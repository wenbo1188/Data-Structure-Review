#ifndef __GRAPH_MATRIX_H__
#define __GRAPH_MATRIX_H__

typedef char VER_TYPE;
#define MAX_VERTEXS 10

typedef struct graph_matrix
{
    VER_TYPE vertexs[MAX_VERTEXS];
    int edges[MAX_VERTEXS][MAX_VERTEXS];
    int ver_num;
    int edge_num;
}GRAPH_MATRIX;

void add_vertex(GRAPH_MATRIX *matrix, VER_TYPE vertex);
void add_directed_edges(GRAPH_MATRIX *matrix, VER_TYPE from, VER_TYPE to);
void add_nondirected_edges(GRAPH_MATRIX *matrix, VER_TYPE first, VER_TYPE second);
void directed_traverse(GRAPH_MATRIX matrix);
void nondirected_traverse(GRAPH_MATRIX matrix);

#endif