#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;

void insert_at_end(int a){
    node *newnode;
    if(head==NULL){
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=newnode;
        head=newnode;
    }else{
        node *t=head;
        while(t->next!=head){
            t=t->next;
        }
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=head;
        t->next=newnode;
    }
}

void display(){
    node *t=head;
    while(t->next!=head){
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("%d",t->data);
    printf("\n");
}

int main(){

    insert_at_end(10);
    insert_at_end(11);
    insert_at_end(12);
    display();
    return 0;
}