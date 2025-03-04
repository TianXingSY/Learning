//
// Created by l1460 on 2024/3/27.
//


#ifndef C_JOSERFU_LINKLIST_H
#define C_JOSERFU_LINKLIST_H
#include <stdio.h>
typedef int Elemtype;


typedef struct node{
    Elemtype data;
    struct node *next;
}Node,*LinkList;
extern int InitList(LinkList *L);
extern int CreateFromTail(LinkList L);
extern int CreateFromTailWithoutInput(LinkList L);
extern int DelLL(LinkList L,int e,int *a);
extern int InsertLL(LinkList L,int e,int a);
extern int bianli(LinkList L);
extern int Find(LinkList L,int x);
#endif //C_JOSERFU_LINKLIST_H
