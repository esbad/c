// #include<stdio.h>
//     struct point//结构体创建
//     {
//         int x;
//         int y;
//     };
//     typedef struct 
//     {
//         int a;
//         int b;
//     }po;//别名
//     struct point createpoint(int x,int y){
//         struct point temp;
//         temp.x = x;
//         temp.y = y;
//         return temp;
//     }
    
// int main()
// {
//     int x = 5;
//     int y = 10;
//     struct point p;
//     p = createpoint(x,y);
//     printf("%d,%d\n",p.x,p.y);
//     struct point *pp;//结构体与指针
//     pp = &p;
//     (*pp).x = 10;
//     pp->y = 5;

//     return 0;
// }