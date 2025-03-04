//
// Created by l1460 on 2024/3/29.
//
#include <stdio.h>
#include "malloc.h"
int S_hanshu(int n){
    if(n==1) {
        printf("1 ");
    }
    else if(n>1){
        S_hanshu(n-1);
        printf("%d ",n);
        S_hanshu(n-1);
    }
    return 0;
}

int main(){
    int n;
    printf("请输入一个整数：");
    scanf("%d",&n);
    if(n>=1){
        S_hanshu(n);
    }
    else{
        printf("输入的整数必须大于0\n");
    }
    return 0;
}


