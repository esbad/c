#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

typedef TreeNode *Bitree;

// //初始化
// Bitree inittree(ElemType e)
// {
//     Bitree t = (Bitree)(malloc(sizeof(TreeNode)));
//     t->date = e;
//     t->lchild = NULL;
//     t->rchild = NULL;
//     return t;
// }
char str[] = "ha##llo";
int idx = 0;
void createTree(Bitree *T)
{
    if (T == NULL) {
        return; // 如果 T 是 NULL，直接返回
    }
    ElemType ch;
    ch = str[idx++];
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (Bitree)malloc(sizeof(TreeNode)); // 显式转换为 Bitree 类型
        if (*T == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }   
        (*T)->data = ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}

//前序遍历 从左开始
void preOrder(Bitree t)
{
    if (t == NULL){
        return;
    }
    printf("%c",t->data);
    preOrder(t->lchild);
    preOrder(t->rchild);
}
//中序遍历 从左开始
void inOrder(Bitree t)
{
    if (t == NULL){
        return;
    }
    inOrder(t->lchild);
    printf("%c",t->data);
    inOrder(t->rchild);
}
//后序遍历 从左开始
void postOrder(Bitree t)
{
    if (t == NULL){
        return;
    }
    postOrder(t->lchild);
    postOrder(t->rchild);
    printf("%c",t->data);
}

int main() {
    Bitree T = NULL; // 初始化二叉树
    createTree(&T);  // 创建二叉树

    printf("前序遍历: ");
    preOrder(T);
    printf("\n");

    printf("中序遍历: ");
    inOrder(T);
    printf("\n");

    printf("后序遍历: ");
    postOrder(T);
    printf("\n");

    return 0;
}