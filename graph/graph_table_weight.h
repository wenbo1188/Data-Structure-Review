#ifndef __GRAPH_TABLE_WEIGHT_H__
#define __GRAPH_TABLE_WEIGHT_H__

#define MAX_VERTEXS 10

typedef char VER_TYPE;
typedef struct edge_node
{
    int ver_index;
    int weight;
    struct edge_node *next;
}EDGE_NODE;

typedef struct vertex
{
    VER_TYPE vertex;
    EDGE_NODE *edge;
}VERTEX;

typedef struct graph_table
{
    VERTEX vertexs[MAX_VERTEXS];
    int ver_num;
}GRAPH_TABLE;

typedef struct
{
    VER_TYPE vertex;
    int lowcost;
}closedge;

int get_vertex_index(GRAPH_TABLE table, VER_TYPE vertex);
void add_vertex(GRAPH_TABLE *table, VER_TYPE vertex);
void add_directed_edges(GRAPH_TABLE *table, VER_TYPE from, VER_TYPE to, int weight);
void add_nondirected_edges(GRAPH_TABLE *table, VER_TYPE first, VER_TYPE second, int weight);
void directed_traverse(GRAPH_TABLE table);
void nondirected_traverse(GRAPH_TABLE table);
void free_graph(GRAPH_TABLE *table);

void mini_span_tree_prim(GRAPH_TABLE table, VER_TYPE vertex);

#endif