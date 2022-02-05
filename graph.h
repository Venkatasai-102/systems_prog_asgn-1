#ifndef GRAPH_H
#define GRAPH_H

typedef struct grph
{
    int cnt_vertices;
    int cnt_edges;
    int **adj_matrx;
} grph;

typedef grph* GRAPH;

typedef struct
{
    int v1, v2;
    int weight;
} edge;

GRAPH readGraph(char *FName); // Forms a graph by reading the given file.
void DFS(GRAPH G); // Runs DFS on the given graph.
void BFS(GRAPH G); // Runs BFS on the given graph.
void MST(GRAPH G); // Computes the MST of the graph using Kruskal's Algorithm.

#endif