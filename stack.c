#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK createStack() // Creates an empty stack
{
    STACK new_node = (STACK) malloc(sizeof(NODE));
    new_node->data = INT_MIN;
    new_node->next = NULL;
    return new_node;
}

int isEmptyStack(STACK S) // Returns 1 if stack is empty
{
    if (S == NULL || S->data == INT_MIN)
    {
        return 1;
    }
    return 0;
}

int top_stack(STACK S) // Returns the value in the top of the stack
{
    if (isEmptyStack(S))
    {
        return INT_MIN;
    }

    return S->data;
}

STACK push(STACK S, int k) // Push a node to stack
{
    
    STACK new_stk = createStack();
    new_stk->data = k;

    if (isEmptyStack(S))
    {
        return new_stk;
    }

    new_stk->next = S;
    return new_stk;
}

STACK pop(STACK S, int *k) // Pop a node from stack
{
    if (isEmptyStack(S))
    {
        printf("The stack is empty\n");
        return NULL;
    }
    
    *k = S->data;
    STACK temp = S->next;
    S->next = NULL;
    free(S);
    return temp;
}

// int main(int argc, char const *argv[])
// {
//     STACK s = createStack();
//     int *k = (int*) malloc(sizeof(int));
//     int p = top_stack(s);
//     if (p == INT_MIN)
//     {
//         printf("Stack is empty\n");
//     }
//     s = push(s, 10);
//     printf("%d ", top_stack(s));
//     s = push(s, 20);
//     printf("%d ", top_stack(s));
//     s = push(s, 30);
//     printf("%d ", top_stack(s));
//     s = push(s, 40);
//     printf("%d\n", top_stack(s));
//     s = pop(s, k);
//     printf("%d ", *k);
//     s = pop(s, k);
//     printf("%d ", *k);
//     s = pop(s, k);
//     printf("%d ", *k);
//     s = pop(s, k);
//     printf("%d\n", *k);
//     s = pop(s, k);
//     return 0;
// }