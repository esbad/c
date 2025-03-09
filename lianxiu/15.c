// #include<stdio.h>

// typedef int Elemtype;
// typedef struct
// {
//     Elemtype date;
//     list* next;
// }list;

// Elemtype dao(list* l,int k)
// {
//     list* p = l;
//     list* q = l;
//     int temp = 0;
//     while(p != NULL)
//         p = p->next;
//         temp++;
//     if (k > temp)
//     {
//         return 0;
//     }
    
//     for(int i = 0;i < temp-k;i++)
//     {
//         q = q->next;
//     }
//     return q->date;
// }
// //快慢指针
// list* chazhao(list* str1,list* str2)
// {
//     list* m = str1;
//     list* n = str2;
//     int temp1 = 0;
//     while(m != NULL)
//         m = m->next;
//         temp1++;
//     int temp2 = 0;
//     while(n != NULL)
//         n = n->next;
//         temp2++;
//     list* fast;
//     list* sloow;
//     if(temp1 >= temp2)
//     {
//         temp1 = temp1-temp2;
//         fast = str1;
//         sloow = str2;
//     }
//     else
//     {
//         temp1 = temp2-temp1;
//         fast = str2;
//         sloow = str1;
//     }
//     for(int i = 0;i < temp1;i++)
//         fast = fast->next;
//     while(fast != sloow)
//         fast = fast->next;
//         sloow = sloow->next;
//     return fast;
// }

// list* fanzhuan(list* l)
// {
//     list* two = l->next;
//     list* stree;
//     list* one = NULL;
//     while (two != 0)
//     {
//         stree = two->next;
//         two->next = one;
//         one = two;
//         two = stree;
//     }
//     l->next = one;
//     return one;
// }

// //判读是否有环
// int huan(list* l)
// {
//     list* fast = l;
//     list* slow = l;
//     while(fast != NULL&&fast->next !=NULL)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//         if(fast == slow)
//         {
//             list* p = fast;
//             int count = 1;
//             int count2 = 1;
//             while(p->next != slow)
//             {
//                 p = p->next;
//                 count++;
//             }
//             fast = l;
//             slow = l;
//             for(int i = 0;i < count;i++)
//                 fast = fast->next;
//             while(fast != slow)
//             {
                
//                 fast = fast->next;
//                 slow = slow->next;
//                 count2++;
//             }
//             return count2;
//         }

//     }
//     return 0;
// }

// int main()
// {

// }