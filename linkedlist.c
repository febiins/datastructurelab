/*insertion and deletion operations on linked list*/

#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head = NULL;
void insert(int a){
    node *t;
    if(head==NULL){
        head=(node*)malloc(sizeof(node));
        head->data=a;
        head->next=NULL;

    }
    else{
        t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=(node*)malloc(sizeof(node));
        t->next->data=a;
        t->next->next=NULL;
    }
}

void insertatspecific(){
    node *t;
    int value;
    printf("Enter the value after which you want to insert\n");
    scanf("%d",&value);
    t=head;
    while(t->data!=value){
        t=t->next;
    }
    if(t==NULL){
        printf("value not found\n");
        return;
    }
    else{
        node* newnode;
        newnode=(node*)malloc(sizeof(node));
        printf("Enter the value to be inserted\n");
        scanf("%d",&newnode->data);
        newnode->next=t->next;
        t->next=newnode;
    }
}

void deletion_at_begining(){
    node *t;
    t=head;
  
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    head=t->next;
}

void deletion_at_end(){
    node *t,*prev;
    t=head;
    while(t->next!=NULL){
        prev=t;
        t=t->next;
    }
    prev->next=NULL;
}

void display(){
    node *t;
    t=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    while(t!=NULL){
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");
}


int main(){
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    display();
    insertatspecific();
    display();
    deletion_at_end(); 
    display();
    return 0;
}