#include<stdio.h>

#define MAXSIZE 100
typedef int ElemType;//表内数据类型 可能更改

typedef struct{
    ElemType date[MAXSIZE];//数组自动初始化
    int length;
}Seqlist;//线性表内数据类型表达

void iniList(Seqlist *L)
{
    L->length = 0;//初始化
}

int add(Seqlist *l,ElemType b){//返回值判断错误操作
    if(l->length>=MAXSIZE)
    {
        printf("满了");
        return 0;
    }
    l->date[l->length] = b;
    l->length++;
    return 1;
}

void listElem(Seqlist *l)//遍历
{
    for(int i = 0;i < l->length;i++)
    {
        printf("%d",l->date);
    }
    printf("\n");
}
//让最后一项的下一项植等于上一项
int insertElem(Seqlist *l,int p,ElemType b)
{
    if(p <= l->length)
    {
        for(int i = l->length - 1;i >= p - 1;i--)
        {
            l->date[i + 1] = l->date[i];
        }
        l->date[p - 1] = b;
        l->length++;
    }
    return 1;
}

int main()
{
    Seqlist List;
    iniList(&List);
    add(&List,33);
    add(&List,44);
    add(&List,35);
    add(&List,24);
    add(&List,63);
    add(&List,334);
    listElem(&List);
    insertElem(&List,3,376);
    listElem(&List);
    return 0;
}
