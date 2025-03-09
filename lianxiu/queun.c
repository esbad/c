//队列 先进先出线性表 队尾插入队头出队
#include<stdio.h>
#define MAXSIZE 5
typedef int ElemType;

//顺序结构对
typedef struct queue
{
    ElemType date[MAXSIZE];
    int rear;
    int fount;
}queue;
//顺序结构队初始化
void initqueue(queue* q)
{
    q->fount = 0;
    q->rear = 0; 
}

//队是否为空
int isEmpty(queue* q)
{
    if(q->fount == q->rear)
    {
        printf("对为空\n");
        return 1;
    }
    else
        return 0;
}

//删除元素
int deletqueue(queue* q/*,ElemType* e*/)
{
    if(q->fount ==q->rear)
        return 0;
    //e = q->date[q->fount];//结构体地址与结构体内容地址的关系
    q->fount++;
    return 1;
}

//入队
int equeue(queue* q,ElemType e)
{
    
    if(q->rear >= MAXSIZE)
    {
        if(q->fount == 0)
        {
            printf("满了\n");
            return 0;
        }
        else
        {
            int cha = q->rear - q->fount;
            for(int i = 0;i <= cha;i++)
            {   
                q->date[i] = q->date[q->fount];
                q->fount++;
                q->rear++;
            }
            q->rear = q->rear - q->fount;
            q->fount = 0;
        }   
    }
    
    q->date[q->rear] = e;
    q->rear++;
}

//获取对头元素
int getfount(queue* q,ElemType* e)
{
    if(q->fount == q->rear)
        return 0;
    *e = q->date[q->fount];
    return 1;
}

int main()
{
    queue q;
    initqueue(&q);
    equeue(&q,2);
    equeue(&q,3);
    equeue(&q,4);
    deletqueue(&q);
    deletqueue(&q);
    equeue(&q,6);
    equeue(&q,7);
    equeue(&q,43);
    equeue(&q,49);
    ElemType e;
    getfount(&q,&e);
    printf("%d\n",e);
    equeue(&q,234);
    
}