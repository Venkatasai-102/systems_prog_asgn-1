#include <stdio.h>
#include <stdlib.h>
#include "../headers/queue.h"

QUEUE createQueue() // Creates an empty queue
{
    QUEUE new_que = (QUEUE)malloc(sizeof(QUEUE));
    new_que->size = 0;
    new_que->front->data = 0;
    new_que->front->next = NULL;
    new_que->back->data = 0;
    new_que->back->next = NULL;
    return new_que;
}

int isEmptyQueue(QUEUE Q) // Returns 1 if queue is empty
{
    if (Q->size == 0)
    {
        return 1;
    }
    return 0;
}

QUEUE enqueue(QUEUE Q, int k) // Adds a value to queue
{
    QUEUE temp = createQueue();
    temp->front->data = k;

    if (Q->size == 0)
    {
        temp->size = 1;
        return temp;
    }
    
    Q->size += 1;

}
QUEUE dequeue(QUEUE Q, int *k); // Removes a value from queue