//
// Created by l1460 on 2024/3/27.
//

#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"



int InitList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Node));
    if(L==NULL){
        printf("内存申请失败\n");
        return(0);
    }
    else{
        (*L)->next=NULL;
        return(1);
    }
    return(0);
}

int CreateFromTailWithoutInput(LinkList L){
    Node *r,*s;
    int flag=1,i=0;
    r=L;
    Elemtype c,listc[11]={90,45,34,56,30,9,45,56,4,6,0};
    while(flag){
        printf("请输入...");
        c=listc[i++];
        if(c>0){
            s=(Node*)malloc(sizeof(Node));
            s->data=c;
            r->next=s;
            r=s;
        }
        else{
            flag=0;
            r->next=NULL;
        }
    }
    return(0);
}
int CreateFromTail(LinkList L){
    Node *r,*s;
    int flag=1;
    r=L;
    Elemtype c;
    while(flag){
        printf("请输入（输入小于0的数以结束输入）：");
        scanf("%d",&c);
        if(c>0){
            s=(Node*)malloc(sizeof(Node));
            s->data=c;
            r->next=s;
            r=s;
        }
        else{
            flag=0;
            r->next=NULL;
        }
    }
    return(0);
}

int DelLL(LinkList L,int e,int *a){
    if(e<1){
        printf("输入非法\n");
    }

    int i;
    LinkList r,s;
    r=L->next;
    for(i=0;i<e;i++){
        if(e==1){
            s=L->next;
            L->next=L->next->next;
            free(s);
            return(1);
        }
        if(i==e-2){
            s=r;
        }
        else if(i==e-1){
            s->next=r->next;
            *a=r->data;
            free(r);
            return(1);
        }
        if(r->next==NULL){
            printf("删除位置不存在\n");
            return(0);
        }
        r=r->next;
    }
}

int InsertLL(LinkList L,int e,int a){
    if(e<1){
        printf("输入非法\n");
    }

    int i;
    LinkList r=L->next,s,In;
    In=(Node*)malloc(sizeof(Node));
    In->data=a;
    for(i=0;i<e;i++){
        if(e==1){
            In->next=L->next;
            L->next=In;
            return(1);
        }
        if(i==e-2){
            s=r;
        }
        else if(i==e-1){
            s->next=In;
            In->next=r;
            return(1);
        }
        if(r==NULL){
            printf("插入位置不存在\n");
            return(0);
        }
        else if(r->next==NULL && i==e-2){
            r->next=In;
            In->next=NULL;
            return(0);
        }
        r=r->next;
    }
}

int bianli(LinkList L){
    LinkList r;
    r=L->next;
    printf("\n");
    while(r!=NULL){
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");
    return(0);
}

int Find(LinkList L,int x){
    LinkList r;
    int i=0;
    r=L->next;
    while(r!=NULL){
        if(r->data==x){
            return(i+1);
        }
        r=r->next;
        i++;
    }
    printf("数据不存在\n");
    return(0);
}
