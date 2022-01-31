#include <stdio.h>
#include <limits.h>
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
        printf("The heap is empty\n");
        return H;
    }
    
    int *arr = H->hp;
    arr[1] = arr[H->size --];
    int l, r, cur = 1;
    int sz = H->size;

    while (1)
    {
        l = 2*cur;
        r = l+1;
        if (l > sz)
        {
            break;
        }
        if (r > sz)
        {
            int temp = arr[cur];
            arr[cur] = arr[l];
            arr[l] = temp;
            break;
        }
        if (arr[l] >= arr[r])
        {
            if (arr[r] >= arr[cur])
            {
                break;
            }
            else
            {
                int temp = arr[cur];
                arr[cur] = arr[r];
                arr[r] = temp;
                cur = r;
            }
        }
        else
        {
            if (arr[l] >= arr[cur])
            {
                break;
            }
            else
            {
                int temp = arr[cur];
                arr[cur] = arr[l];
                arr[l] = temp;
                cur = l;
            }
        }
    }
    
    return H;
}

HEAP insertHeap(HEAP H, int k) // Inserts a new value in the heap and returns a modified heap
{
    if (isFullHeap(H))
    {
        printf("The heap is full and this number can't be added to the heap\n");
        return H;
    }
    
    H->size ++;
    int *arr = H->hp;
    arr[H->size] = k;
    int p, cur = H->size;
    while (1)
    {
        p = cur/2;
        if (p == 0)
        {
            break;
        }
        if (arr[p] <= arr[cur])
        {
            break;
        }
        else
        {
            int temp = arr[cur];
            arr[cur] = arr[p];
            arr[p] = temp;
            cur = p;
        }
    }
    
    return H;
}

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

// int main(int argc, char const *argv[])
// {
//     HEAP h = createHeap();
//     h = extractMin(h);
//     printf("%d\n", findMin(h));
//     insertHeap(h, 10);
//     printf("%d\n", findMin(h));
//     insertHeap(h, 15);
//     insertHeap(h, 40);
//     insertHeap(h, 1);
//     printf("%d\n", findMin(h));
//     h = extractMin(h);
//     printf("%d\n", findMin(h));
//     printf("%d\n", h->size);
//     h = extractMin(h);
//     printf("%d\n", findMin(h));
//     printf("%d\n", h->size);
//     h = extractMin(h);
//     printf("%d\n", findMin(h));
//     printf("%d\n", h->size);
//     h = extractMin(h);
//     printf("%d\n", findMin(h));
//     printf("%d\n", h->size);
//     // for (int i = 1; i <= h->size; i++)
//     // {
//     //     printf("%d ", h->hp[i]);
//     // }
    
//     return 0;
// }