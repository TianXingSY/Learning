//
// Created by l1460 on 2024/4/2.
//
//建立线性栈及其常用基本函数
#define MAXSIZE 50
#include "stdio.h"

typedef  int Elemtype;

typedef struct {
    Elemtype data[MAXSIZE];
    int top;
} SqStack;

int InitStack(SqStack *S) {
    S->top = -1;
    return 1;
}

int Push(SqStack *S, Elemtype e) {
    if (S->top == MAXSIZE - 1) {
        return 0;
    }
    S->data[++S->top] = e;
    return 1;
}

int Pop(SqStack *S, Elemtype *e) {
    if (S->top == -1) {
        return 0;
    }
    *e = S->data[S->top--];
    return 1;
}

int GetTop(SqStack *S, Elemtype *e) {
    if (S->top == -1) {
        return 0;
    }
    *e = S->data[S->top];
    return 1;
}
