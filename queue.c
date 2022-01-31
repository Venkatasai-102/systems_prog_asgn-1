#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "llist.h"
#include "queue.h"

QUEUE createQueue() // Creates an empty queue
{
    QUEUE q;
    q = (QUEUE)malloc(sizeof(QUE));
    q->front = q->end = NULL;
    return q;
}

int isEmptyQueue(QUEUE Q) // Returns 1 if queue is empty
{
    if (Q->front == NULL)
    {
        return 1;
    }

    return 0;
}

int front_que(QUEUE Q) // Returns the front value in the queue
{
    if (isEmptyQueue(Q))
    {
        return INT_MIN;
    }
    return Q->front->data;
}

QUEUE enqueue(QUEUE Q, int k) // Adds a value to queue
{
    LLIST new_node = createList();
    new_node->data = k;
    if (isEmptyQueue(Q))
    {
        Q->front = Q->end = new_node;
        return Q;
    }
    
    Q->front->next = new_node;
    Q->front = new_node;
    return Q;
}

QUEUE dequeue(QUEUE Q, int *k) // Removes a value from queue
{
    if (isEmptyQueue(Q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    
    *k = Q->end->data;
    if (Q->front == Q->end)
    {
        LLIST temp = Q->front;
        Q->front = Q->end = NULL;
        free(temp);
        return Q;
    }
    
    LLIST temp = Q->end;
    Q->end = temp->next;
    free(temp);
    return Q;
}

// int main(int argc, char const *argv[])
// {
//     QUEUE que = createQueue();
//     if (isEmptyQueue(que))
//     {
//         printf("The queue is empty.\n");
//     }
//     int t = front_que(que);
//     if (t == INT_MIN)
//     {
//         printf("The queue is empty.\n");
//     }
    
//     int *k = (int *)malloc(sizeof(int));
//     que = enqueue(que, 10);
//     printf("%d ", front_que(que));
//     que = enqueue(que, 20);
//     printf("%d ", front_que(que));
//     que = enqueue(que, 30);
//     printf("%d\n", front_que(que));
//     que = dequeue(que, k);
//     printf("%d %d\n", front_que(que), *k);
//     que = dequeue(que, k);
//     printf("%d %d\n", front_que(que), *k);
//     que = dequeue(que, k);
//     printf("%d %d\n", front_que(que), *k);
//     return 0;
// }