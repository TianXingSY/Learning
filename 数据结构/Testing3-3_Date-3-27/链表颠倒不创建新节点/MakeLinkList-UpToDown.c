//
// Created by l1460 on 2024/3/28.
//
#include "LinkList.c"

int main() {
    LinkList L,s,z;
    InitList(&L);
    CreateFromTailWithoutInput(L);
    bianli(L);
    z=L->next->next;
    L->next->next=NULL;
    while(z){
        s=z;
        z=z->next;
        s->next=L->next;
        L->next=s;
    }
    bianli(L);
}