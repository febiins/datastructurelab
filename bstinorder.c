#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int  data;
    struct tree *right;
    struct tree *left;
}tree;

typedef struct stack{
    tree *tnode;
    struct stack *next;
}stack;

tree *root=NULL;
stack *top=NULL;

void insert(int a){
    tree *x,*p;
    if(root==NULL){
        root=(tree*)malloc(sizeof(tree));
        root->data=a;
        root->right=NULL;
        root->left=NULL;
    }else{
        x=root;
        while(x!=NULL){
            p=x;
            if(x->data<a){
                x=x->right;
            }
            else{
                x=x->left;
            }
        }

        if(p->data<a){
            p->right=(tree*)malloc(sizeof(tree));
            p->right->data=a;
            p->right->right=NULL;
            p->right->left=NULL;
        }else{
            p->left=(tree*)malloc(sizeof(tree));
            p->left->data=a;
            p->left->right=NULL;
            p->left->left=NULL;
        }
    }
}

void push(tree *n){
    stack *temp=(stack*)malloc(sizeof(stack));
    temp->tnode=n;
    temp->next=top;
    top=temp;
}

void inorder(tree *r){
    tree *t;
    for(t=r;t!=NULL;t=t->left){
        push(t);
    }
    while(top){
        //printf("%d\t",t->data);
        t=top->tnode;
        top=top->next;
        printf("%d\t",t->data);
		for(t = t->right;t != NULL; t= t->left) {
			push(t);
		}
    }
}


/*void inorder(tree *r){
    if(r!=NULL){
        inorder(r->left);
        printf("%d\t",r->data);
        inorder(r->right);
    }
}*/

int main(){
    insert(2);
    insert(1);
    insert(3);
    inorder(root);
    return 0;
}