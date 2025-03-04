#include <stdio.h>
#define MAXSIZE 20
typedef int Elemtype;

typedef struct seqlist{
	Elemtype data[MAXSIZE];
	int last;
}SeqList;

int Locate(SeqList L,Elemtype e){
	int i = 0;
	while((i <= L.last) && (L.data[i] != e)){
		i++;
	}
	if(i<= L.last){
		return(i+1);
	}
	else{
		return(-1);
	}
}

int Inslist(SeqList *L,int i,Elemtype e){
	int k;
	if((i<1)||(i>L->last+2)){
		printf("插入位置i不合法\n");
		return(0);
	}
	else if(L->last>= MAXSIZE-1){
		printf("表已满，无法插入\n");
		return(0);
	}
	else{
		for(k=L->last;k>=i-1;k--){
			L->data[k+1] = L->data[k];
		}
		L->data[i-1]=e;
		L->last++;
		return(1);
	}
}

int DelList(SeqList *L,int i,Elemtype *e){
	int k;
	if((i<1)||(i>L->last+2)){
		printf("删除位置i不合法\n");
		return(0);
	}
	*e=L->data[i-1];
	for(k=i;k<=L->last;k++){
		L->data[k-1]=L->data[k];
	}
	L->last--;
	return(1);
}

int Takeout(SeqList *L,int i,Elemtype *e){
	if((i<1)||(i>L->last+2)){
		printf("查询位置i不合法\n");
		return(0);
	}
	*e=L->data[i];
	return(1);
}
