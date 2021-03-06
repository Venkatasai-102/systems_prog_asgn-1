#ifndef QUEUE_H
#define QUEUE_H

typedef struct _que
{
    LLIST front;
    LLIST end;
} QUE; // making a queue structure

typedef QUE* QUEUE;

QUEUE createQueue(); // Creates an empty queue
int isEmptyQueue(QUEUE Q); // Returns 1 if queue is empty
int front_que(QUEUE Q); // Returns the front value in the queue
QUEUE enqueue(QUEUE Q, int k); // Adds a value to queue
QUEUE dequeue(QUEUE Q, int *k); // Removes a value from queue

#endif