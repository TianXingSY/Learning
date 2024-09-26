//
// Created by l1460 on 2024/3/28.
//
#include "LinkList.c"

int main() {
    LinkList L,s,z;
    InitList(&L);
    CreateFromTail(L);
    bianli(L);
    z=L->next->next;
    s=z;
    L->next->next=NULL;
    while(z){
        z=z->next;
        s->next=L->next;
        L->next=s;
        s=z;
    }
    bianli(L);
}