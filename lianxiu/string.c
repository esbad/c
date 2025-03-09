#include<stdio.h>
#include<string.h>

//const常量
//const char str[] = "hallo"常量字符串，内容无法改变
//char * const str1 = str 常量指针，指向无法改变
//const常量字符串的指针，传递参数
// BF算法实现
int BF(const char *str, const char *pattern) {
    int strLen = strlen(str);
    int patternLen = strlen(pattern);
    int i, j;

    // 主串遍历
    for (i = 0; i <= strLen - patternLen; i++) {
        // 模式串遍历
        for (j = 0; j < patternLen; j++) {
            if (str[i + j] != pattern[j]) {
                // 若不匹配，跳出当前模式串遍历
                break;
            }
        }
        // 若模式串遍历完，说明匹配成功
        if (j == patternLen) {
            return i;
        }
    }
    // 未找到匹配，返回 -1
    return -1;
}

int kmp(const char* str,const char *pattern)
{
    int strLen = strlen(str);
    int patternLen = strlen(pattern);
    int i, j;
    
}










int main() {
    const char *str = "ABCABCD";
    const char *pattern = "ABCD";
    int index = BF(str, pattern);
    if (index != -1) {
        printf("Pattern found at index %d.\n", index);
    } else {
        printf("Pattern not found.\n");
    }
    return 0;
}