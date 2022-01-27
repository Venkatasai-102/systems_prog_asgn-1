typedef struct ND_PTR
{
    int data;
    int cnt_mems;
    struct ND_PTR *next;
} ND_PTR;

typedef ND_PTR* NODE_PTR;

typedef struct uf
{
    int n;
    int size;
    NODE_PTR *set_uf;
} UN_FD;

typedef UN_FD* UNION_FIND;

UNION_FIND createUF(int n); // Create a union find data structure that can store n nodes pointers
UNION_FIND makeSetUF(UNION_FIND F, int x, int *i); // Inserts a value x
NODE_PTR findUF(UNION_FIND F, int i); // Returns the id of the set
void unionUF(UNION_FIND F, int i, int j); // Make a union of parent of i and parent of j