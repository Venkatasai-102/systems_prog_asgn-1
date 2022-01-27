#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

GRAPH readGraph(char *FName) // Forms a graph by reading the given file.
{
    GRAPH g;
    g = (GRAPH)malloc(sizeof(grph));
    FILE *f = fopen(FName, "r");

    int cnt_e, cnt_v;
    fscanf(f, "%d%d", &cnt_v, &cnt_e);

    g->adj_matrx = (int **)malloc(sizeof(int*)*cnt_v);
    for (int i = 0; i < cnt_v; i++)
    {
        g->adj_matrx[i] = (int *)malloc(sizeof(int)*cnt_v);
        for (int j = 0; j < cnt_v; j++)
        {
            g->adj_matrx[i][j] = INT_MAX;
        }
    }
    
    int v1, v2, w;
    for (int i = 0; i < cnt_e; i++)
    {
        fscanf(g, "%d%d%d", &v1, &v2, &w);
        g->adj_matrx[v1][v2] = w;
        g->adj_matrx[v2][v1] = w;
    }
    
    fclose(f);
    
    return g;
}

void DFS(GRAPH G) // Runs DFS on the given graph.
{
    int cnt_v = G->cnt_vertices;
}
void BFS(GRAPH G); // Runs BFS on the given graph.
void MST(GRAPH G); // Computes the MST of the graph using Kruskal's Algorithm.