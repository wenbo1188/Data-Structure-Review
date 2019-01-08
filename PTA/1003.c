#include <stdio.h>
#include <string.h>

#define MAX_CITY 500

typedef struct graph
{
    int team_num[MAX_CITY];
    int edges[MAX_CITY][MAX_CITY];
    int city_num;
}GRAPH;

void dijkstra(GRAPH graph, int start, int end)
{
    int s[MAX_CITY] = {0};
    int dist[MAX_CITY] = {0};
    int shortest_num[MAX_CITY] = {0};
    int team_max[MAX_CITY] = {0};
    s[start] = 1;
    dist[start] = 0;
    shortest_num[start] = 1;
    team_max[start] = graph.team_num[start];
    for (int i = 0;i < graph.city_num;++i)
    {
        if (i != start)
        {
            dist[i] = graph.edges[start][i];
            if (graph.edges[start][i] != 65535)
            {
                shortest_num[i] = 1;
                team_max[i] = team_max[start] + graph.team_num[i];
            }
        }
    }

    for (int i = 0;i < graph.city_num;++i)
    {
        int min = 65535;
        int k = 0;
        for (int j = 0;j < graph.city_num;++j)
        {
            if (s[j] != 1)
            {
                if (dist[j] < min)
                {
                    min = dist[j];
                    k = j;
                }
            }
        }
        s[k] = 1;
        for (int j = 0;j < graph.city_num;++j)
        {
            if (s[j] != 1 && dist[k] + graph.edges[k][j] < dist[j])
            {
                dist[j] = dist[k] + graph.edges[k][j];
                shortest_num[j] = shortest_num[k];
                team_max[j] = team_max[k] + graph.team_num[j];
            }
            else if (s[j] != 1 && dist[k] + graph.edges[k][j] == dist[j])
            {
                shortest_num[j] += shortest_num[k];
                if (team_max[j] < team_max[k] + graph.team_num[j])
                {
                    team_max[j] = team_max[k] + graph.team_num[j];
                }
            }
        }
    }

    printf("%d %d\n", shortest_num[end], team_max[end]);

    return;
}

int main(int argc, char const *argv[])
{
    GRAPH graph = {0};
    int city_num = 0;
    int road_num = 0;
    int start_city, end_city = 0;
    int team_num = 0;
    int from, to, dist = 0;
    scanf("%d %d %d %d", &city_num, &road_num, &start_city, &end_city);
    graph.city_num = city_num;
    for (int i = 0;i < city_num;++i)
    {
        scanf("%d", &team_num);
        graph.team_num[i] = team_num;
    }
    for (int i = 0;i < road_num;++i)
    {
        scanf("%d %d %d", &from, &to, &dist);
        graph.edges[from][to] = dist;
        graph.edges[to][from] = dist;
    }

    for (int i = 0;i < graph.city_num;++i)
    {
        for (int j = 0;j < graph.city_num;++j)
        if (i != j && graph.edges[i][j] == 0)
        {
            graph.edges[i][j] = 65535;
        }
    }

    dijkstra(graph, start_city, end_city);

    return 0;
}
