// #include<stdio.h>

// int main()
// {
//     int x,y,z,d,a;
//     printf("请输入三个数\n");
//     scanf("%d%d%d%d",&x,&y,&z,&d);
//     int sh[]={x,y,z,d};
//     for(int i=0;i<3;i++)
//     {
//         for(int j=0;j<3-i;j++){
//             if(sh[j]>sh[j+1]){
//                 a=sh[j];
//                 sh[j]=sh[j+1];
//                 sh[j+1]=a;
//             }
//         }
//     }
//     printf("%d %d %d %d",sh[0],sh[1],sh[2],sh[3]);
//     return 0;
// }