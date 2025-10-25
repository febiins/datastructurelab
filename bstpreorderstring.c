#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree{
    char data[100];
    struct tree *left;
    struct tree *right;
}tree;
tree *root=NULL;

void insert(char a[]){
    tree *x,*p;
    if(root==NULL){
        root=(tree*)malloc(sizeof(tree));
        strcpy(root->data,a);
        root->left=NULL;
        root->right=NULL;
    }else{
        x=root;
        while(x!=NULL){
            p=x;
            if(strcmp(a,x->data)>0){
                x=x->right;
            }else{
                x=x->left;
            }
        }
        if(strcmp(a,p->data)>0){
            p->right=(tree*)malloc(sizeof(tree));
            strcpy(p->right->data,a);
            p->right->right=NULL;
            p->right->left=NULL;

        }else{
            p->left=(tree*)malloc(sizeof(tree));
            strcpy(p->left->data,a);
            p->left->right=NULL;
            p->left->left=NULL;
        }
    }

}

void preorder(tree *r){
    if(r!=NULL){
        printf("%s\t",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

int main(){
    insert("bat");
    insert("apple");
    insert("cat");
    preorder(root);
    return 0;
}