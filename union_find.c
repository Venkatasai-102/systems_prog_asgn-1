#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "union_find.h"

UNION_FIND createUF(int n) // Create a union find data structure that can store n nodes pointers
{
    UNION_FIND uf = (UNION_FIND) malloc(sizeof(UN_FD));
    uf->set_uf = (NODE_PTR *) malloc(sizeof(NODE_PTR) * n);
    uf->n = -1;
    uf->size = n;
    return uf;
}

UNION_FIND makeSetUF(UNION_FIND F, int x, int *i) // Inserts a value x
{
    F->n ++;
    *i = F->n;
    NODE_PTR new_node = (NODE_PTR) malloc(sizeof(ND_PTR));
    new_node->data = x;
    new_node->cnt_mems = 1;
    new_node->next = NULL;
    F->set_uf[*i] = new_node;
    return F;
}

NODE_PTR findUF(UNION_FIND F, int i) // Returns the id of the set
{
    NODE_PTR temp = F->set_uf[i];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void unionUF(UNION_FIND F, int i, int j) // Make a union of parent of i and parent of j
{
    NODE_PTR parent1 = findUF(F, i);
    NODE_PTR parent2 = findUF(F, j);
    if (parent1 == parent2)
    {
        return;
    }
    
    if (parent1->cnt_mems > parent2->cnt_mems)
    {
        parent2->next = parent1;
        parent1->cnt_mems += parent2->cnt_mems;
    }
    else
    {
        parent1->next = parent2;
        parent2->cnt_mems += parent1->cnt_mems;
    }
}

// int main(int argc, char const *argv[])
// {
//     UNION_FIND uf = createUF(8);
//     int *i = (int*)malloc(sizeof(int));
//     uf = makeSetUF(uf, 34, i);
//     printf("%d ", *i);
//     uf = makeSetUF(uf, 19, i);
//     printf("%d ", *i);
//     uf = makeSetUF(uf, 5, i);
//     printf("%d ", *i);
//     uf = makeSetUF(uf, 23, i);
//     printf("%d ", *i);
//     uf = makeSetUF(uf, 11, i);
//     printf("%d ", *i);
//     uf = makeSetUF(uf, 47, i);
//     printf("%d ", *i);
//     uf = makeSetUF(uf, 9, i);
//     printf("%d ", *i);
//     uf = makeSetUF(uf, 28, i);
//     printf("%d\n", *i);
//     for (int i = 0; i < 8; i++)
//     {
//         printf("%d ", uf->set_uf[i]->data);
//     }
//     printf("\n");

//     for (int i = 0; i < 8; i++)
//     {
//         NODE_PTR temp = findUF(uf, i);
//         printf("%d ", temp->data);
//     }
//     printf("\n");

//     unionUF(uf, 5, 0);
//     unionUF(uf, 6, 0);
//     unionUF(uf, 1, 4);
//     unionUF(uf, 1, 4);
//     unionUF(uf, 1, 2);
//     unionUF(uf, 1, 7);
    
//     for (int i = 0; i < 8; i++)
//     {
//         NODE_PTR temp = findUF(uf, i);
//         printf("%d ", temp->data);
//     }
//     printf("\n");
//     return 0;
// }
