//
// Created by l1460 on 2024/4/2.
//
#include "SeqStack.c"
//����˳��ջʵ��ʮ����ת��N����


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
    printf("������һ��ʮ��������");
    scanf("%d", &num);
    printf("������Ŀ���������");
    scanf("%d", &n);
    Ten_To_0o(num,n);
    return 0;
}