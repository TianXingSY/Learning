//
// Created by l1460 on 2024/4/1.
//
#include "StackList.c"
#include "string.h"
//利用函数检测字符数组里括号数量是否匹配



int CheckBrackets(char *str) {
    LinkStack S;
    InitStack(&S);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (StackEmpty(S)) {
                printf("多出%c\n", str[i]);
                return 0;
            }
            char c;
            Pop(S, &c);
            if ((c == '(' && str[i] != ')') || (c == '[' && str[i] != ']') || (c == '{' && str[i] != '}')) {
                printf("括号不匹配,%c can't match %c\n", str[i], c);
                return 0;
            }
        }
    }
    if (StackEmpty(S)) {
        return 1;
    }
    while (!StackEmpty(S)) {
        char c;
        Pop(S, &c);
        printf("多出%c\n", c);
    }
    return 0;
}

int main() {
    char str[50] = "{3+[4*(4+5)]}(()]";
    char *p = str;
    if (CheckBrackets(p)) {
        printf("括号匹配成功");
    }
    else {
        printf("括号匹配失败");
    }
}