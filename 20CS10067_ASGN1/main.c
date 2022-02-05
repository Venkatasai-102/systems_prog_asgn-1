#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(int argc, char const *argv[])
{
    printf("Enter the name of text file: ");
    char *pth = (char *)malloc(sizeof(char) * 30);
    scanf("%s", pth);
    GRAPH gr = readGraph(pth);
    DFS(gr);
    BFS(gr);
    MST(gr);
    return 0;
}
