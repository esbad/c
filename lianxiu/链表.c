#include<stdio.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct node
{
    ElemType date;
    struct node *next;//存数据和下一个数据的地址
}Node;

Node* initList()//初始化，返回其地址
{
    Node* head = (Node*)(malloc(sizeof(Node)));//堆内存
    head->date = 0;
    head->next = NULL;//头节点
    return head;
}
//头插法
int insertHead(Node* l,ElemType e)//头节点 本项数据
{
    Node* p = (Node*)(malloc(sizeof(Node)));//开辟新节点
    p->date = e;//给新结点赋值
    p->next = l->next;//新节点指向原来节点指向的位置
    l->next = p;//上一项指向本项
    return 1;
}
//遍历
void listNode(Node* l)//给头节点
{
    Node* p = l->next;//传第一个节点的地址
    while(p != NULL)
    {
        printf("%d\n",p->date);//打印第一个节点数据
        p = p->next;//传下一个节点的地址
    }
    printf("\n");
}
//获取尾节点
Node* get_tail(Node* l)//给头节点
{
    Node* p = l->next;//传第一个节点的地址
    while(p != NULL)
    {
        p = p->next;//传下一个节点的地址
    }
    return p;
}
//尾插法
Node* insertTail(Node* tail,ElemType e)//给尾节点
{
    Node* p =  (Node*)(malloc(sizeof(Node)));//开辟新节点
    p->date = e;
    tail->next = p;
    p->next = NULL;
    return p;//返回新的尾节点
}

int insertNode(Node* l,int pos,ElemType e)
{
    //获取前驱节点
    Node* p = l;
    int i = 0;
    while(i < pos-1)//从头节点开始，循环几次就得到第几个节点地址
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }
    Node* q =  (Node*)(malloc(sizeof(Node)));//开辟新节点
    q->date = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

int main()
{
    Node* list = initList();
    insertHead(list,13);
    insertHead(list,43);
    insertHead(list,155);
    insertHead(list,643);
    insertHead(list,34);
    listNode(list);
    Node* tail = get_tail(list);
    tail = insertTail(tail,43);
    tail = insertTail(tail,355);
    tail = insertTail(tail,46);
    tail = insertTail(tail,24);
    listNode(list);
    insertNode(list,5,477);
    listNode(list);

    return 0;
}