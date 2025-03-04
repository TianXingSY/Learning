//
// Created by l1460 on 2024/3/27.
//
#include <malloc.h>
#include <stdio.h>
typedef char Elemtype;

typedef struct stack {
    Elemtype data;
    struct stack *next;
}Stack,*LinkStack;

int InitStack(LinkStack *S){
    *S = (LinkStack)malloc(sizeof(Stack));
    if(!S){
        return 0;
    }
    (*S)->next = NULL;
    return 1;
}

int Push(LinkStack S,Elemtype e){
    if(!S){
        return 0;
    }
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}

int Pop(LinkStack S,Elemtype *e){
    if(!S){
        return 0;
    }
    LinkStack r = S->next;
    if(!S->next){
        return 0;
    }
    *e = S->next->data;
    S->next = S->next->next;
    free(r);
    return 1;
}

int StackEmpty(LinkStack S){
    if(!S){
        return 0;
    }
    return !S->next;
}

int StackLength(LinkStack S){
    if(!S){
        return 0;
    }
    int len = 0;
    LinkStack p = S->next;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

int ClearStack(LinkStack S){
    if(!S){
        return 0;
    }
    while(S->next){
        Pop(S,&S->next->data);
    }
    return 1;
}

int StackTraverse(LinkStack S){
    if(!S){
        return 0;
    }
    LinkStack r = S->next;
    while(r){
        printf("%d ",r->data);
    }
    printf("\n");
    return 1;
}

int TakeTop(LinkStack S,Elemtype *e){
    if(!S){
        return 0;
    }
    *e = S->next->data;
    return 1;
}