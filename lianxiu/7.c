// #include<stdio.h>

// int main(){
//     // int i,t;
//     // int fo_month=0;
//     // int ct_month=1;
//     // for(i=1;i<21;i++){
//     //     printf("%d\n",ct_month);
//     //     t = ct_month;
//     //     ct_month += fo_month;
//     //     fo_month = t;
//     // }//兔子数列

//     int i,j;
//     int count=0;
//     for(i=100;i<=200;i++){
//         for(j=2;j<i;j++){
//             if(i%j==0)
//             break;
//         }
//         if(j==i){
//             count++;
//             printf("%d ",i);
//             if(count%5==0)
//             printf("\n");
//         }
//     }
//     return 0;
// }