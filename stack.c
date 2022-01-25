#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK createStack() // Creates an empty stack
{
    STACK new_node = (STACK) malloc(sizeof(STACK));
    new_node->data = 0;
    new_node->next = NULL;
    return new_node;
}

int isEmptyStack(STACK S) // Returns 1 if stack is empty
{
    if (S == NULL)
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
    new_stk->next = S;
    return new_stk;
}

STACK pop(STACK S, int *k) // Pop a node from stack
{
    if (isEmptyStack(S))
    {
        return NULL;
    }
    
    *k = S->data;
    STACK temp = S->next;
    S->next = NULL;
    free(S);
    return temp;
}