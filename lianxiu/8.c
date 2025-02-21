// #include<stdio.h>

// int main()
// {
//     // int a,b,c;
//     // for(int i=100;i<1000;i++){
//     //     a=i/100;
//     //     b=(i-a*100)/10;
//     //     c=i-a*100-b*10;
//     //     if(a*a*a+b*b*b+c*c*c==i)
//     //         printf("%d ",i);
//     // }
//     //水仙花数

//     int n,i;
//     printf("请输入");
//     scanf("%d",&n);
//     printf("%d=",n);
//     for(i=2;i<=n;i++)
//     {
//         while(n%i==0){
//             printf("%d",i);
//             n=n/i;
//             if(n!=1)
//             printf("*");
//         }       
//     }
//     return 0;
// }