#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *head=NULL;
void insert_begining(int a){
    node *newnode,*t=head;
    if(head==NULL){
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else{
        
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
        newnode->next->prev=head;


    }
}

void insert_end(int a){
    node *t=head,*newnode;
    while(t->next!=NULL){
        t=t->next;
    }
    newnode=(node*)malloc(sizeof(node));
    newnode->data=a;
    newnode->next=NULL;
    newnode->prev=t;
    t->next=newnode;
}

void deletion_at_begining(){
    if(head==NULL){
        printf("The list is empty\n");
    }
    else{
        head->next->prev=NULL;
        head=head->next;

    }
}

void display(){
    node *t=head;
    while(t!=NULL){
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");
}

int main(){
    insert_begining(10);
    insert_begining(20);
    display();
    insert_end(30);
    display();
    deletion_at_begining();
    display();
   
    return 0;
}