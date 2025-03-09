// 中缀表达式
// 后缀表达式
// op1 symbol op2 = 
// 数字入栈，遇到运算符出栈到op2，运算结果入栈



// 枚举
// enum 枚举名
// {
//     枚举元素;
// };
// enum weekday//符合数据类型
// {
//     mon = 1,tue,wed,thu,fri,sat,sun//默认从0开始记值
// };
#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct stack
{
    ElemType* date;
    int top;
}stack;

typedef enum
{
    LEFT_PARE,RIGHT_PARE,
    ADD,SUB,MUL,DIV,MOD,
    EOS,NUM
}countentType;

char expr[] = "82/2+56*-";

//动态栈初始化
stack* initStack()
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->date = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
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

countentType gettoken(char *symbol,int *index)
{
    *symbol = expr[*index];
    (*index)++;
    switch (*symbol)
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}

int eavl(stack *s)
{
    char symbol;
    int op1, op2;
    int index = 0;
    countentType token;
    token = gettoken(&symbol,&index);
    ElemType result;
    while(token != EOS)
    {
        if (token == NUM)
            push(s, symbol - '0');//char转Int小技巧
        else
        {
            pop(s, &op2);
            pop(s, &op1);

            switch (token)
            {
            case ADD:
                push(s, op1 + op2);
                break;
            case SUB:
                push(s, op1 - op2);
                break;
            case MUL:
                push(s, op1 * op2);
                break;
            case DIV:
                push(s, op1 / op2);
                break;
            case MOD:
                push(s, op1 % op2);
                break;
            default:
                break;
            }
        }
        token = gettoken(&symbol, &index);
    }
    pop(s, &result);
    printf("%d\n",result);
    return 1;
}

int main()
{
    stack* s = initStack();
    eavl(s);
    return 0;
}