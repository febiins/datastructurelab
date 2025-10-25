#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
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
            p->right->right=NULL;
            p->right->left=NULL;
        }
        else{
            p->left=(tree*)malloc(sizeof(tree));
            p->left->data=a;
            p->left->left=NULL;
            p->left->right=NULL;
        }
    }
}

void postorder(tree *r){
    if(r!=NULL){
        postorder(r->left);
        postorder(r->right);
        printf("%d\t",r->data);
    }
}

int main(){
    insert(2);
    insert(1);
    insert(3);
    postorder(root);
    return 0;
}