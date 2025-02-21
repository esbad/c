// #include<stdio.h>

// void swap(int *a,int *b){
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("a=%d,b=%d\n",*a,*b);
// }

// int main(){
//     int m = 5;
//     int n = 10;
//     // swap(&m,&n);
//     // printf("m=%d,n=%d",m,n);
//     int a[]={1,12,2,3,4};
//     int *p = a;
//     printf("%p\n%p\n%d\n%d\n",a,p,*p,*a);
//     for(int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
//     {
//         printf("%d",a[i]);
//         printf("%d",*(p+i));//对指针算术运算，自动乘以字节数
//     }
    
//     return 0;
// }