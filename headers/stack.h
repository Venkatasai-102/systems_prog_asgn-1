typedef LLIST STACK; // Making a stack

STACK createStack(); // Creates an empty stack
int isEmptyStack(STACK S); // Returns 1 if stack is empty
STACK push(STACK S, int k); // Push a node to stack
STACK pop(STACK S, int *k); // Pop a node from stack