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
    CreateFromTailWithoutInput(L);
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
        L->next=L->next->next;
        free(s);
    }
    else{
        r=s->next;
        s->next=r->next;
        free(r);
    }
    bianli(L);
}