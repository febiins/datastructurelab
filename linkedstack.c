#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
} stack;
stack *top = NULL;

void push(int a){
    stack *t;
        t=(stack*)malloc(sizeof(stack));
        t->data=a;
        t->next=top;
        top=t;
    
}

void pop(){
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Popped element is %d\n",top->data);
        top=top->next;
    }
}
void peek(){

    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n",top->data);
    }
}

int main(){
    push(5);
    push(10);
    push(15);
    peek();
    return 0;
}