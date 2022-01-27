#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

LLIST createList() // Creates a new linked list
{
    LLIST node = (LLIST)malloc(sizeof(NODE));
    node->data = INT_MIN;
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

void printList(LLIST H) // Prints the elements of the list
{
    LLIST temp = H;
    if (temp == NULL || temp->data == INT_MIN)
    {
        printf("List is empty\n");
        return;
    }
    
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

LLIST insertAtFront(LLIST H, int k) // Inserts a node in front of list
{
    LLIST new_node = createList();
    new_node->data = k;
    if (H == NULL || H->data == INT_MIN)
    {
        return new_node;
    }
    
    new_node->next = H;
    return new_node;
}

LLIST insertAtEnd(LLIST H, int k) // Inserts a node at the end of list
{
    LLIST new_node = createList();
    new_node->data = k;

    if (H == NULL || H->data == INT_MIN)
    {
        return new_node;
    }
    
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
    if (H == NULL || H->data == INT_MIN)
    {
        printf("List is empty\n");
        return NULL;
    }
    
    LLIST temp = H->next;
    *k = H->data;
    H->next = NULL;
    free(H);
    return temp;
}

LLIST deleteFromEnd(LLIST H, int *k) // Delete a node at the end of list
{
    if (H == NULL || H->data == INT_MIN)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (H->next == NULL)
    {
        *k = H->data;
        free(H);
        return NULL;
    }
    
    LLIST temp = H;
    LLIST prev = temp;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    
    *k = temp->data;
    prev->next = NULL;
    temp->next = NULL;
    free(temp);
    return H;
}

LLIST deleteList(LLIST H, int k) // Deletes Deletes the first occurance of node with value k
{
    if (H == NULL || H->data == INT_MIN)
    {
        printf("List is empty\n");
        return NULL;
    }
    
    LLIST temp = H;

    if (H->data == k)
    {
        temp = H->next;
        H->next = NULL;
        return temp;
    }

    LLIST prev = temp;
    while (temp != NULL)
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
    free(temp);
    return H;
}

// int main(int argc, char const *argv[])
// {
//     LLIST ls = createList();
//     int *k = (int*)malloc(sizeof(int));
//     ls = insertAtFront(ls, 10);
//     printList(ls);
//     ls = insertAtFront(ls, 20);
//     printList(ls);
//     ls = insertAtFront(ls, 30);
//     printList(ls);
//     ls = deleteFromFront(ls, k);
//     printList(ls);
//     ls = deleteFromFront(ls, k);
//     printList(ls);
//     ls = deleteFromFront(ls, k);
//     printList(ls);
//     ls = insertAtEnd(ls, 10);
//     printList(ls);
//     ls = insertAtEnd(ls, 20);
//     printList(ls);
//     ls = insertAtEnd(ls, 30);
//     printList(ls);
//     ls = deleteFromFront(ls, k);
//     printList(ls);
//     ls = deleteFromEnd(ls, k);
//     printList(ls);
//     ls = deleteFromEnd(ls, k);
//     printList(ls);
//     ls = insertAtEnd(ls, 10);
//     printList(ls);
//     ls = insertAtEnd(ls, 20);
//     printList(ls);
//     ls = insertAtEnd(ls, 30);
//     printList(ls);
//     ls = deleteList(ls, 10);
//     printList(ls);
//     ls = deleteList(ls, 20);
//     printList(ls);
//     ls = deleteList(ls, 30);
//     printList(ls);
//     ls = deleteList(ls, 30);
//     printList(ls);
//     return 0;
// }