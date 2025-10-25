#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *right;
    struct tree *left;
}tree;

tree *root=NULL;

void insert(int a){
    tree *x,*p;
    if(root==NULL){
        root=(tree*)malloc(sizeof(tree));
        root->data=a;
        root->left=NULL;
        root->right=NULL;
    }else{
        x=root;
        while(x!=NULL){
            p=x;
            if(x->data<a){
                x=x->right;
            }else{
                x=x->left;
            }

        }
        if(p->data<a){
            p->right=(tree*)malloc(sizeof(tree));
            p->right->data=a;
            p->right->left=NULL;
            p->right->right=NULL;
        }else{
            p->left=(tree*)malloc(sizeof(tree));
            p->left->data=a;
            p->left->right=NULL;
            p->left->left=NULL;
        }
    }

}

void preorder(tree *r){
    if(r!=NULL){
        printf("%d\t",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

int main(){
    insert(2);
    insert(1);
    insert(3);
    preorder(root);
    return 0;
}