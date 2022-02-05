#ifndef STACK_H
#define STACK_H

typedef LLIST STACK; // Making a stack data structure

STACK createStack(); // Creates an empty stack
int isEmptyStack(STACK S); // Returns 1 if stack is empty
int top_stack(STACK S); // Returns the value in the top of the stack
STACK push(STACK S, int k); // Push a node to stack
STACK pop(STACK S, int *k); // Pop a node from stack

#endif