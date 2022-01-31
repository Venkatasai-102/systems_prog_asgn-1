#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "llist.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "union_find.h"

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
    printf("\n");
    free(frnt);
    free(visited);
}

static edge *make_edge_list(int **adj_mtrx, int n, int e) // using as a static function to avoid it being used outside this file
{
    edge *list_edges = (edge *)malloc(sizeof(edge)*e);
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (adj_mtrx[i][j] != 0)
            {
                list_edges[pos].v1 = i;
                list_edges[pos].v2 = j;
                list_edges[pos++].weight = adj_mtrx[i][j];
            }
        }
    }
    
    return list_edges;
}

static int partition_edges(edge *list_edges, int start, int end) // using as a static function to avoid it being used outside this file
{
    int item = list_edges[start].weight;
    int i = start + 1;
    int j = end;
    while (i < j)
    {
        while (i <= j && list_edges[i].weight < item)
        {
            i ++;
        }
        while (j > start && list_edges[i].weight > item)
        {
            j --;
        }
        edge temp = list_edges[i];
        list_edges[i] = list_edges[j];
        list_edges[j] = temp;
    }

    edge temp = list_edges[start];
    list_edges[start] = list_edges[i];
    list_edges[i] = temp;
    return i;
}

static void sort_partitions(edge *list_edges, int start, int end) // using as a static function to avoid it being used outside this file
{
    if (start >= end)
    {
        return;
    }
    
    int index = partition_edges(list_edges, start, end);
    sort_partitions(list_edges, start, index-1);
    sort_partitions(list_edges + index, index+1, end);
}

void MST(GRAPH G) // Computes the MST of the graph using Kruskal's Algorithm.
{
    int e = G->cnt_edges;
    int n = G->cnt_vertices;

    edge *list_edges = make_edge_list(G->adj_matrx, n, e); // making the array of edges

    sort_partitions(list_edges, 0, n-1); // sorting the edges to apply kruskal's algorithm

    UNION_FIND set_nodes = createUF(n);
    int *k = (int *)malloc(sizeof(int));

    int weight = 0;

    for (int i = 0; i < e; i++)
    {
        int v1 = list_edges[i].v1;
        int v2 = list_edges[i].v2;
        if (set_nodes->set_uf[v1]->next == NULL)
        {
            set_nodes = makeSetUF(set_nodes, v1, k);
        }
        
        if (set_nodes->set_uf[v2] == NULL)
        {
            set_nodes = makeSetUF(set_nodes, v2, k);
        }
        
        NODE_PTR p1 = findUF(set_nodes, v1);
        NODE_PTR p2 = findUF(set_nodes, v2);

        if (p1->data != p2->data)
        {
            unionUF(set_nodes, v1, v2);
            int wt = list_edges[i].weight;
            printf("%d %d %d", v1, v2, wt);
            weight += wt;
        }
        
        if (set_nodes->n == n-1)
        {
            break;
        }
    }
    printf("The total weight of the MST of the given graph is: %d", weight);
}

int main(int argc, char const *argv[])
{
    printf("Enter the name of text file: ");
    char *pth = (char *)malloc(sizeof(char)*30);
    scanf("%s", pth);
    GRAPH gr = readGraph(pth);
    DFS(gr);
    BFS(gr);
    MST(gr);
    return 0;
}