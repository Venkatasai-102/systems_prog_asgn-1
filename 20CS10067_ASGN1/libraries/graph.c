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

    g->adj_matrx = (int **)malloc(sizeof(int *) * cnt_v);
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
    int *visited = (int *)malloc(sizeof(int) * cnt_v);
    for (int i = 0; i < cnt_v; i++)
    {
        visited[i] = 0;
    }

    printf("The DFS post order traversal of the graph is: ");
    // printf("The DFS pre order traversal of the graph is: ");

    STACK stk = createStack();
    stk = push(stk, 0);
    // printf("0 "); // for printing the preorder traversal of the graph

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
                // printf("%d ", i); // for printing the pre order traversal of the graph
                stk = push(stk, i);
                unvst_ngbr = 1;
                visited[i] = 1;
                break;
            }
        }
        if (!unvst_ngbr)
        {
            stk = pop(stk, k);
            printf("%d ", *k); // for printing the post order traversal of the graph
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
    printf("The BFS traversal of the graph is: ");

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
    edge *list_edges = (edge *)malloc(sizeof(edge) * e);
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

static void sort_edges(edge *edge_list, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (edge_list[j].weight < edge_list[j-1].weight)
            {
                edge temp = edge_list[j];
                edge_list[j] = edge_list[j-1];
                edge_list[j-1] = temp;
            }
        }
    }
}

void MST(GRAPH G) // Computes the MST of the graph using Kruskal's Algorithm.
{
    int e = G->cnt_edges;
    int n = G->cnt_vertices;

    edge *list_edges = make_edge_list(G->adj_matrx, n, e); // making the array of edges

    sort_edges(list_edges, e);

    int *vertices = (int *)malloc(sizeof(int)*n);
    
    for (int i = 0; i < n; i++)
    {
        vertices[i] = -1;
    }
    
    UNION_FIND set_nodes = createUF(n);
    
    int *k = (int *)malloc(sizeof(int));

    int weight = 0;

    printf("The edges included and their weights in the MST are:\n");
    for (int i = 0; i < e; i++)
    {
        int v1 = list_edges[i].v1;
        int v2 = list_edges[i].v2;
        
        if (vertices[v1] == -1)
        {
            set_nodes = makeSetUF(set_nodes, v1, k);
            vertices[v1] = *k;
        }
        
        if (vertices[v2] == -1)
        {
            set_nodes = makeSetUF(set_nodes, v2, k);
            vertices[v2] = *k;
        }
        
        NODE_PTR p1 = findUF(set_nodes, vertices[v1]);
        NODE_PTR p2 = findUF(set_nodes, vertices[v2]);

        if (p1->data != p2->data)
        {
            unionUF(set_nodes, vertices[v1], vertices[v2]);
            int wt = list_edges[i].weight;
            printf("%d, %d, %d\n", v1, v2, wt);
            weight += wt;
        }
        
        if (set_nodes->n == set_nodes->size)
        {
            break;
        }
    }
    free(k);
    free(vertices);
    free(list_edges);
    printf("The total weight of the MST of the given graph is: %d\n", weight);
}

// int main(int argc, char const *argv[])
// {
//     printf("Enter the name of text file: ");
//     char *pth = (char *)malloc(sizeof(char) * 30);
//     scanf("%s", pth);
//     GRAPH gr = readGraph(pth);
//     DFS(gr);
//     BFS(gr);
//     MST(gr);
//     return 0;
// }