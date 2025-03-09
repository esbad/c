#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct queuenode
{
    ElemType date;
    struct queuenode* next;
}queuenode;

typedef struct//q.fount相当于队头节点
{
    queuenode* fount;
    queuenode* rear;
}Queue;

//初始化
Queue* initqueuenode()
{
    queuenode* node = (queuenode*)(malloc(sizeof(queuenode)));
    Queue* q = (Queue*)(malloc(sizeof(Queue)));
    node->date = 0;
    node->next = NULL;
    q->fount = node;
    q->rear = node;
    return q;
}

//是否为空
int isEmpty(Queue* q)
{
    if (q->fount == q->rear)
    {
        printf("空的\n");
        return 1;
    }
    else
        return 0;
}

//尾插法入队
void equeue(Queue* q,ElemType e)
{
    queuenode* node = (queuenode*)(malloc(sizeof(queuenode)));
    q->rear->next = node;
    node->date = e;
    node->next = NULL;
    q->rear = node;
}

//出队
int dequeue(Queue* q,ElemType* e)
{
    if (q->fount == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = q->fount->next->date;
    queuenode* node = q->fount->next;
    q->fount->next = node->next;
    if (q->rear == node)
        q->rear = q->fount;
    free(node);
    return 1;
}