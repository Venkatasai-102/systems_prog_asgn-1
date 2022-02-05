#ifndef LLIST_H
#define LLIST_H

typedef struct NODE
{
    int data;
    struct NODE *next;
} NODE;

typedef NODE* LLIST;

LLIST createList(); // Creates a new linked list
int searchList(LLIST H, int k); // Searches for a nodes with given value in the list
void printList(LLIST H); // Prints the elements of the list
LLIST insertAtFront(LLIST H, int k); // Inserts a node in front of list
LLIST insertAtEnd(LLIST H, int k); // Inserts a node at the end of list
LLIST deleteFromFront(LLIST H, int *k); // Delete a node at the front of list
LLIST deleteFromEnd(LLIST H, int *k); // Delete a node at the end of list
LLIST deleteList(LLIST H, int k); // Deletes the first occurance of node with value k

#endif