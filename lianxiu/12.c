// #include<stdio.h>

// void gongyueshu(int m,int n){
//     int temp1,temp2,temp3;
//     if(m<n)
//     {temp1=n;n=m;m=temp1;}
//     temp2=m%n;
//     temp3=m*n;
//     while(temp2!=0)
//     {
//         m=n;
//         n=temp2;
//         temp2=m%n;
//     }
//     printf("最大公约数为：%d\n最小公倍数为:%d",m,temp3/m);
// }

// int sums(int a,int b){
//     int s = 0,temp = a;
//     for(int i = 1;i <= b;i++)
//     {
//         s += temp;
//         temp = temp*10 + a;
//     }
//     return s;
// }
// int main()
// {
//     int m,n,a,b,s;
//     printf("请输入a=");
//     scanf("%d",&a);
//     printf("请输入数量b=");
//     scanf("%d",&b);
//     s = sums(a,b);
//     printf("s=%d",s);
//     // printf("请输入两个数：");
//     // scanf("%d%d",&m,&n);
//     // gongyueshu(m,n);
//     return 0;
// }