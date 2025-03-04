//
// Created by l1460 on 2024/4/2.
//
#include "SeqStack.c"
//利用顺序栈实现十进制转换N进制


int Ten_To_0o(int num, int n) {
    SqStack S;
    InitStack(&S);
    while (num) {
        Push(&S, num % n);
        num /= n;
    }
    while (S.top!=-1) {
        Pop(&S, &num);
        printf("%d", num);
    }
    return 0;
}

int main() {
    int num,n;
    printf("请输入一个十进制数：");
    scanf("%d", &num);
    printf("请输入目标进制数：");
    scanf("%d", &n);
    Ten_To_0o(num,n);
    return 0;
}