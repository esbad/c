#include<stdio.h>
#include<malloc.h>

typedef char ElemType;
typedef struct threadNode
{
    ElemType data;
    struct threadNode *lchild;//不能套娃，要用指针指向自己
    struct threadNode *rchild;
    int ltag;
    int rtag;
};

