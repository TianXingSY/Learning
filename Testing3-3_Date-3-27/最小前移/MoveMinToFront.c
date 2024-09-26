//
// Created by l1460 on 2024/3/27.
//

#include <stdio.h>
#include "malloc.h"
#include "LinkList.c"

int main(){
    LinkList L,r,s;
    Elemtype min;
    int i=0;
    InitList(&L);
    CreateFromTail(L);
    bianli(L);
    r=L->next;
    min=r->data;
    s=r;
    while(r->next!=NULL){
        if(r->next->data<min){
            min=r->next->data;
            s=r;
            i++;
        }
        r=r->next;
    }
    if(i==0){
        printf("第一个已是最小值\n");
    }
    else{
        r=s->next;
        s->next=r->next;
        r->next=L->next;
        L->next=r;
    }
    bianli(L);
}