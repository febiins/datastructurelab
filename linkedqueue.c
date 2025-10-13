#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue(int a){
    node *newnode,*t=front;
    if (front==NULL&&rear==NULL){
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
    }
    else{
        
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=NULL;
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    if(front==NULL){
        printf("The queue is empty\n");

    }else{
        front=front->next;
    }
}

void display(){
    node *t=front;
    while(t!=NULL){
        printf("%d\t",t->data);
        t=t->next;
    }
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}