#include<stdio.h>
#include<malloc.h>
//last in first out
//|  |
//|__|限制插入和删除操作只能在一个位置进行的表，栈顶，进栈push出栈pop
#define MAXSIZE 100
typedef int ElemType;

// typedef struct
// {
//     ElemType date[MAXSIZE];
//     int top;//栈顶指针（下标）
// }stack;

// void initStack(stack* s)
// {
//     s->top = -1;
// }

//动态链
typedef struct stack
{
    ElemType* date;
    int top;
}stack;
//动态栈初始化
stack* initStack()
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->date = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
}
//初始化？
// void dd_initStack(d_stack* s)
// {
//     s = (d_stack*)malloc(sizeof(d_stack));
//     s->date = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//     s->top = -1;
// }



//判断是否为空栈
int isEmpty(stack*s)
{
    if(s->top == -1)
    {
        printf("Empty\n");
        return 1;
    }
    else
        return 0;
}
//压栈
int push(stack* s,ElemType e)
{
    if(s->top >=MAXSIZE - 1)
    {
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->date[s->top] = e;
    return 1;
}


//出栈
int pop(stack* s,ElemType* e)
{
    if(s->top == -1)
    {
        printf("Empty\n");
        return 0;
    }
    *e = s->date[s->top];
    s->top--;
    return 1;
}
//获取栈顶元素
ElemType getpop(stack* s)
{
    if(s->top == -1)
    {
        printf("Empty\n");
        return 0;
    }
    return s->date[s->top];
}

int main()
{
    // stack s;
    // initStack(&s);
    // push(&s,10);
    // push(&s,55);
    // push(&s,33);
    // push(&s,23);
    // push(&s,44);
    // ElemType e;
    // pop(&s,&e);
    // printf("%d",e);
    
    stack* s = initStack();
    push(s,13);
    push(s,156);
    push(s,24);
    push(s,23);
    ElemType e;
    pop(s,&e);
    printf("%d",e);
    ElemType d = getpop(s);
    
    return 0;
}