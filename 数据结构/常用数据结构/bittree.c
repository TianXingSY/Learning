//
// Created by l1460 on 24-4-18.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent;
}bittree;
//二叉树前序建立
bittree *createtree(bittree *root) {
    char c;
    printf("enter a char\n:");
    c=getchar();
    if (c == '\n'|| c == ' ') {
        return NULL;
    }
    else{
        root = (bittree *) malloc(sizeof(bittree));
        root->data=c;
        root->left=createtree(root->left);
        root->right=createtree(root->right);
        return root;
    }
}
//通过前序序列和中序序列建立二叉树
bittree *createtree_by_PreandIn(bittree *root,char *Pre,char *Pin,int len) {
    if (len == 0) {
        return NULL;
    }
    else{
        int left_len=0;
        char *Pin_left;
        root = (bittree *) malloc(sizeof(bittree));
        root->data=Pre[0];
        for (int i = 0; i < len; ++i) {
            if (Pin[i] == Pre[0]) {
                left_len = i;
                break;
            }
        }
        Pin_left=(char *)malloc(sizeof(char)*left_len);
        for(int i = 0; i < left_len; ++i){
            Pin_left[i]=Pin[i];
        }
        root->left=createtree_by_PreandIn(root->left,Pre+1,Pin_left,left_len);
        root->right=createtree_by_PreandIn(root->right,Pre+left_len+1,Pin+left_len+1,len-left_len-1);
        return root;
    }
}

int PreOrder(bittree *root) {
    if (root == NULL) {
        return 0;
    }
    printf("%c",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    return 0;
}

/*int main(){
    bittree *two,*miao;
    char Pre[6]="ABDCEF";
    char Pin[6]="DBACEF";
    two=createtree(two);
    PreOrder(two);
    printf("\n");
    createtree_by_PreandIn(miao,Pre,Pin,6);
    PreOrder(miao);
    return 0;
}*/