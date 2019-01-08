#include <stdio.h>
#include <stdlib.h>

typedef struct offer
{
    int v1;
    int v2;
    int cost;
}offer;

int lowcost[200000] = {0};
int close_vertex[200000] = {0};

int check_offer(offer *offers, int num_offer, int v1, int v2, int min)
{
    for (int i = 0;i < num_offer;++i)
    {
        if ((offers[i].v1 == (v1 + 1) && offers[i].v2 == (v2 + 1)) || (offers[i].v1 == (v2 + 1) && offers[i].v2 == (v1 + 1)))
        {
            if (offers[i].cost < min)
            {
                return i;
            }
        }
    }
    return -1;
}

int Prim(int *vertexs, int num_vertex, offer *offers, int num_offer)
{
    int res = 0;
    for (int i = 1;i < num_vertex;++i)
    {
        lowcost[i] = vertexs[0] + vertexs[i];
        close_vertex[i] = 0;
    }

    for (int i = 0;i < num_vertex - 1;++i)
    {
        int min = 65535;
        int p = 0;
        int sp = 0;
        for (int j = 0;j < num_vertex;++j)
        {
            if (lowcost[j] != 0)
            {
                printf("j: %d, close_vertex[j]: %d, min: %d\n", j, close_vertex[j], min);
                sp = check_offer(offers, num_offer, j, close_vertex[j], min);
                if (sp != -1)
                {
                    min = offers[sp].cost;
                    p = j;
                    printf("min: %d\n", min);
                }
                if (lowcost[j] < min)
                {
                    min = lowcost[j];
                    p = j;
                    printf("min: %d\n", min);
                }
            }
        }
        lowcost[p] = 0;
        for (int j = 0;j < num_vertex;++j)
        {
            if (lowcost[j] != 0 && (vertexs[p] + vertexs[j]) < lowcost[j])
            {
                lowcost[j] = vertexs[p] + vertexs[j];
                close_vertex[j] = p;
            }
        }
        printf("final min: %d\n", min);
        res += min;
    }
    return res;
}

int main()
{
    int num_vertex, num_offer = 0;
    int min_cost = 0;
    scanf("%d %d", &num_vertex, &num_offer);
    int *vertexs = (int *)malloc(sizeof(int) * num_vertex);
    // int *flags = (int *)malloc(sizeof(int) * num_vertex);
    // int **matrix = (int **)malloc(sizeof(int *) * num_vertex);
    offer *offers = (offer *)malloc(sizeof(offer) * num_offer);
    for (int i = 0;i < num_vertex;++i)
    {
        scanf("%d", &vertexs[i]);
    }
    for (int i = 0;i < num_offer;++i)
    {
        scanf("%d %d %d", &offers[i].v1, &offers[i].v2, &offers[i].cost);
    }
    // for (int i = 0;i < num_vertex;++i)
    // {
    //     matrix[i] = (int *)malloc(sizeof(int) * num_vertex);
    // }
    // for (int i = 0;i < num_vertex;++i)
    // {
    //     for (int j = 0;j < num_vertex;++j)
    //     {
    //         if (i != j)
    //         {
    //             matrix[i][j] = vertexs[i] + vertexs[j];
    //         }
    //         else
    //         {
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }

    // flags[0] = 1;
    lowcost[0] = 0;
    min_cost = Prim(vertexs, num_vertex, offers, num_offer);
    printf("%d\n", min_cost);
    // for (int i = 0;i < num_vertex;++i)
    // {
    //     free(matrix[i]);
    // }
    // free(matrix);
    free(vertexs);
    // free(flags);
    free(offers);
    return 0;
}