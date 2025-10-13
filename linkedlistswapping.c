#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* head=NULL;
void display(){
    node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert(int n){
    node* newnode;
    if(head==NULL){
        newnode=(node*)malloc(sizeof(node));
        newnode->data=n;
        newnode->next=NULL;
        head=newnode;
    }
    else{
        node* temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode=(node*)malloc(sizeof(node));
        temp->next=newnode;
        newnode->data=n;
        newnode->next=NULL;
    }
}

void sort_value(){
    node *i,*j;
    int temp;
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data < j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }

        }
    }
    display();
}

void reverse(){
    node *current,*prev,*next;
    current=head;
    prev=NULL;
    next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    display();

}



int main(){
    insert(10);
    insert(20);
    insert(30);
    display();
    sort_value();
    reverse();
    return 0;
}