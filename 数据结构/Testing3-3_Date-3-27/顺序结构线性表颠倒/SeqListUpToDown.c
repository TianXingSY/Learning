//
// Created by l1460 on 2024/3/27.
//
#define SIZE 10
#include "xxb.c"
#include "StackList.c"


int main(){
    SeqList L;
    LinkStack P;
    InitStack(&P);
    L.last=-1;
    int i,temple[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    for(i = 0;i < SIZE;i++){
        L.data[++L.last] = temple[i];
    }
    Elemtype e;
    while (L.last > -1){
        DelList(&L,1,&e);
        Push(P,e);
    }
    while (!StackEmpty(P)){
        Pop(P,&e);
        L.data[++L.last] = e;
    }
    for(i = 0;i < L.last+1;i++){
        printf("%d ",L.data[i]);
    }
}