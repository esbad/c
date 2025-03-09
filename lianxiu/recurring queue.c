#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct 
{
    ElemType* date;
    int rear;
    int fount; 
}queue;

queue* initqueue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->date = (ElemType*)malloc(sizeof(ElemType));
    q->fount = 0;
    q->rear = 0;
    return q;
}


//循环队列入队
int equeue(queue* q,ElemType e)
{
    if ((q->rear + 1) % MAXSIZE == q->fount)//循环队列队满和队空时q->rear==q->fount,
    {                                       //所以少放一个值用来判断队满
        printf("满了\n");
        return 0;
    }
    q->date = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

//删除元素
int deletqueue(queue* q,ElemType* e)
{
    if(q->fount == q->rear)
        return 0;
    e = q->date[q->fount];//结构体地址与结构体内容地址的关系
    q->fount = (q->fount + 1) % MAXSIZE;
    return 1;
}
