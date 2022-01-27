#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"

UNION_FIND createUF(int n) // Create a union find data structure that can store n nodes pointers
{
    UNION_FIND *uf = (UNION_FIND *) malloc(sizeof(UNION_FIND));
}

UNION_FIND makeSetUF(UNION_FIND F, int x, int *i); // Inserts a value x
NODE_PTR findUF(UNION_FIND F, int i); // Returns the id of the set
void unionUF(UNION_FIND F, int i, int j); // Make a union of parent of i and parent of j