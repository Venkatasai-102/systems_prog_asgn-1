#include "./llist.h"
typedef struct _que
{
    LLIST front;
    LLIST back;
    int size;
} QUE; // making a queue structure

typedef QUE* QUEUE;

QUEUE createQueue(); // Creates an empty queue
int isEmptyQueue(QUEUE Q); // Returns 1 if queue is empty
QUEUE enqueue(QUEUE Q, int k); // Adds a value to queue
QUEUE dequeue(QUEUE Q, int *k); // Removes a value from queue