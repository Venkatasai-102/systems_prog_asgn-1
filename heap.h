#ifndef HEAP_H
#define HEAP_H

typedef struct _heap
{
    int *hp;
    int size;
} _hp;

typedef _hp* HEAP; // making a heap structure

HEAP createHeap(); // Creates an empty heap
int findMin(HEAP H); // Returns the minimum value in the heap
HEAP extractMin (HEAP H); // Deletes the minimum value in the heap and returns a modified heap
HEAP insertHeap(HEAP H, int k); // Inserts a new value in the heap and returns a modified heap
int isFullHeap(HEAP H); // Returns 1 if the heap is full
int isEmptyHeap(HEAP H); // Returns 1 if the heap is empty

#endif