#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild;
    struct ThreadNode *rchild;
    int ltag;
    int rtag;
}ThreadNode;

typedef ThreadNode* ThreadTree;

char str[] = "AHSUHBI##SH##CH##SGH";
int idx = 0;

ThreadTree prev;//用地址记录上一个访问的结点
                //用二重指针来修改该地址
//创建线索树
void createTree(ThreadTree *T)//二重指针因为没有返回值，要直接修改地址
{
    ElemType ch;
    ch = str[idx++];

    if (ch == '#'){
        *T = NULL;
    }else{
        *T = (ThreadTree)malloc(sizeof(ThreadNode));//前序造树

        (*T)->data = ch;
        (*T)->ltag = 0; // 初始化 ltag
        (*T)->rtag = 0; // 初始化 rtag

        createTree(&(*T)->lchild);
        if ((*T)->lchild != NULL)//有点像中序加0，需要知道孩子是否为空，所以先进递归，顺序不影响
        {
            (*T)->ltag = 0;
        }
        createTree(&(*T)->rchild);
        if ((*T)->rchild != NULL)//后序加0，需要知道右孩子空否
        {
            (*T)->rtag = 0;
        }
    }
}
//中序线索化（内）
void threading(ThreadTree T)
{
    if (T != NULL)
    {
        threading(T->lchild);//找到最后一个左孩子
        if (T->lchild == NULL)//让上一项指向下一项，if是筛选需要线索化的
        {
            T->ltag = 1;
            T->lchild = prev;
        }
        if (prev->rchild == NULL)//上一个访问的结点右孩子是空
        {
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;//线索化关键
        threading(T->rchild);
    }
}

//线索化（外）
void inOrderThreading(ThreadTree *head,ThreadTree T)
{
    //头结点
    *head = (ThreadTree)malloc(sizeof(ThreadNode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);

    if (T == NULL)
    {
        (*head)->lchild = *head;
    }
    else
    {
        (*head)->lchild = T;
        prev = (*head);

        threading(T);

        //最后结点线索化
        prev->rchild = *head;
        prev->rtag = 1;
        (*head)->rchild = prev;
    }
}

void inOder(ThreadTree T)
{
    ThreadTree curr;
    curr = T->lchild;

    while (curr != T)//循环
    {
        while (curr->ltag == 0)//找到最左
        {
            curr = curr->lchild;
        }

        printf("%c\n", curr->data);
        
        while (curr->rtag == 1 && curr->rchild != T)//利用线索回到上一个
        {
            curr = curr->rchild;
            printf("%c", curr->data);
        }
        curr = curr->rchild;//next
    }
    printf("\n");
}

int main()
{
    ThreadTree head;
    ThreadTree T;
    createTree(&T);
    inOrderThreading(&head, T);
    inOder(head);

    return 0;
}