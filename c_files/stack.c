#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"

STACK createStack() // Creates an empty stack
{
    STACK new_node = (STACK) malloc(sizeof(STACK));
    new_node->size = 0;
    new_node->stk->data = 0;
    new_node->stk->next = NULL;
    return new_node;
}

int isEmptyStack(STACK S) // Returns 1 if stack is empty
{
    if (S->size == 0)
    {
        return 1;
    }
    return 0;
}

STACK push(STACK S, int k) // Push a node to stack
{
    STACK new_stk = createStack();
    new_stk->stk->data = k;

    if (isEmptyStack(S))
    {
        new_stk->size = 1;
        return new_stk;
    }

    new_stk->size = S->size + 1;
    new_stk->stk->data = k;
    new_stk->stk->next = S;
    return new_stk;
}

STACK pop(STACK S, int *k) // Pop a node from stack
{
    if (isEmptyStack(S))
    {
        return NULL;
    }
    
    STACK temp = S->stk->next;
    S->stk->next = NULL;
    return temp;
}