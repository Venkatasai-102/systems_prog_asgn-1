#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP createHeap() // Creates an empty heap
{
    HEAP h = (HEAP) malloc(sizeof(HEAP));
    h->hp = (int*)malloc(sizeof(int)*101);
    h->size = 0;
    return h;
}

int findMin(HEAP H) // Returns the minimum value in the heap
{
    if (isEmptyHeap(H))
    {
        return INT_MAX;
    }
    return H->hp[1];
}

HEAP extractMin (HEAP H) // Deletes the minimum value in the heap and returns a modified heap
{
    if (isEmptyHeap(H))
    {
        return NULL;
    }
    
    int *arr = H->hp;
    arr[1] = arr[H->size --];
    int l = 2, r = 3, cur = 1;
    int sz = H->size;
    while (1)
    {
        if (l > sz)
        {
            break;
        }
        
    }
    
}
HEAP insertHeap(HEAP H, int k); // Inserts a new value in the heap and returns a modified heap

int isFullHeap(HEAP H) // Returns 1 if the heap is full
{
    if (H->size == 100)
    {
        return 1;
    }
    return 0;
}

int isEmptyHeap(HEAP H) // Returns 1 if the heap is empty
{
    if (H->size == 0)
    {
        return 1;
    }
    return 0;
}