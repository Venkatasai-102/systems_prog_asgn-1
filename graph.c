#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

GRAPH readGraph(char *FName) // Forms a graph by reading the given file.
{
    GRAPH g;
    g = (GRAPH)malloc(sizeof(grph));
    FILE *f = fopen(FName, "r");

    int cnt_e, cnt_v;
    fscanf(f, "%d%d", &cnt_v, &cnt_e);
    g->cnt_vertices = cnt_v;
    g->cnt_edges = cnt_e;

    g->adj_matrx = (int **)malloc(sizeof(int*)*cnt_v);
    for (int i = 0; i < cnt_v; i++)
    {
        g->adj_matrx[i] = (int *)calloc(cnt_v, sizeof(int));
    }
    
    int v1, v2, w;
    for (int i = 0; i < cnt_e; i++)
    {
        fscanf(f, "%d%d%d", &v1, &v2, &w);
        g->adj_matrx[v1][v2] = w;
        g->adj_matrx[v2][v1] = w;
    }
    
    fclose(f);
    
    return g;
}

void DFS(GRAPH G) // Runs DFS on the given graph and prints the post order traversal of the graph
{
    int cnt_v = G->cnt_vertices;
    int *visited = (int *)malloc(sizeof(int)*cnt_v);
    for (int i = 0; i < cnt_v; i++)
    {
        visited[i] = 0;
    }

    STACK stk = createStack();
    stk = push(stk, 0);
    
    visited[0] = 1;

    int **adj_mtrx = G->adj_matrx;

    int *k = (int *)malloc(sizeof(int));

    while (isEmptyStack(stk) != 1)
    {
        int nd = top_stack(stk);
        int unvst_ngbr = 0;
        for (int i = 0; i < cnt_v; i++)
        {
            if (adj_mtrx[nd][i] != 0 && visited[i] != 1) // if there is an edge between the nd and other node and it is unvisited
            {
                stk = push(stk, i);
                unvst_ngbr = 1;
                visited[i] = 1;
                break;
            }
        }
        if (!unvst_ngbr)
        {
            stk = pop(stk, k);
            printf("%d ", *k);
        }
    }
    printf("\n");
    free(k);
    free(visited);
}

void BFS(GRAPH G) // Runs BFS on the given graph and prints preorder traversal
{
    int cnt_v = G->cnt_vertices;
    int *visited = (int *)malloc(sizeof(int) * cnt_v);
    for (int i = 0; i < cnt_v; i++)
    {
        visited[i] = 0;
    }
    
    QUEUE que = createQueue();
    visited[0] = 1;
    que = enqueue(que, 0);
    int **adj_mtrx = G->adj_matrx;

    int *frnt = (int *)malloc(sizeof(int));
    while (isEmptyQueue(que) != 1)
    {
        que = dequeue(que, frnt);
        printf("%d ", *frnt);
        for (int i = 0; i < cnt_v; i++)
        {
            if (adj_mtrx[*frnt][i] != 0 && visited[i] != 1)
            {
                que = enqueue(que, i);
                visited[i] = 1;
            }
        }
    }
    free(frnt);
    free(visited);
}

void MST(GRAPH G) // Computes the MST of the graph using Kruskal's Algorithm.
{
    
}

int main(int argc, char const *argv[])
{
    printf("Enter the name of text file: ");
    char *pth = (char *)malloc(sizeof(char)*30);
    scanf("%s", pth);
    GRAPH gr = readGraph(pth);
    DFS(gr);
    BFS(gr);
    return 0;
}