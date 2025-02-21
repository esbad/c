// #include <stdio.h>
// #include <string.h>
// #include <ctype.h> // 用于isspace函数

// #define MAX_RANGE 65535

// int main() {
//     char s[MAX_RANGE];
//     size_t i = 0;

//     // 定义四个变量分别作为对应的计数器
//     unsigned int count_Num = 0;
//     unsigned int count_Char = 0;
//     unsigned int count_Space = 0;
//     unsigned int count_Other = 0;

//     printf("请输入一个长度不大于%d的字符串\n", MAX_RANGE);
//     if (fgets(s, sizeof(s), stdin) == NULL) {
//         fprintf(stderr, "读取输入失败。\n");
//         return 1;
//     }

//     // 去除fgets读取的换行符
//     s[strcspn(s, "\n")] = 0;

//     for (i = 0; s[i] != '\0'; i++) {
//         if (isdigit((unsigned char)s[i])) {
//             count_Num++;
//         } else if (isalpha((unsigned char)s[i])) {
//             count_Char++;
//         } else if (isspace((unsigned char)s[i])) {
//             count_Space++;
//         } else {
//             count_Other++;
//         }
//     }

//     printf("空格符:%u个  英文字符:%u个  数字:%u个  其它字符:%u个\n", count_Space, count_Char, count_Num, count_Other);

//     return 0;
// }
