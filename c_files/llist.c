#include <stdio.h>
#include <stdlib.h>
#include "../headers/llist.h"

LLIST createList() // Creates a new linked list
{
    LLIST node = (LLIST)malloc(sizeof(LLIST));
    node->data = 0;
    node->next = NULL;
    return node;
}

int searchList(LLIST H, int k) // Searches for a nodes with given value in the list
{
    LLIST temp = H;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

LLIST insertAtFront(LLIST H, int k) // Inserts a node in front of list
{
    LLIST new_node = createList();
    new_node->data = k;
    new_node->next = H;
    return new_node;
}

LLIST insertAtEnd(LLIST H, int k) // Inserts a node at the end of list
{
    LLIST new_node = createList();
    new_node->data = k;
    LLIST temp = H;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = new_node;
    return H;
}

LLIST deleteFromFront(LLIST H, int *k) // Delete a node at the front of list
{
    LLIST temp = H->next;
    H->next = NULL;
    return temp;
}

LLIST deleteFromEnd(LLIST H, int *k) // Delete a node at the end of list
{
    LLIST temp = H;
    LLIST prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
    temp->next = NULL;
    return H;
}

LLIST deleteList(LLIST H, int k) // Deletes Deletes the first occurance of node with value k
{
    LLIST temp = H;
    LLIST prev;
    while (temp->next != NULL)
    {
        if (temp->data == k)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    temp->next = NULL;
    return H;
}