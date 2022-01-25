typedef LLIST NODE_PTR; // Making a union find data structure

typedef struct uf
{
    int n;
    NODE_PTR *set_uf;
} UNION_FIND;

UNION_FIND createUF(int n); // Create a union find data structure that can store n nodes pointers
UNION_FIND makeSetUF(UNION_FIND F, int x, int *i); // Inserts a value x
NODE_PTR findUF(UNION_FIND F, int i); // Returns the id of the set