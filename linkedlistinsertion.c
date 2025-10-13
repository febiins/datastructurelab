#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;


node *head=NULL;

void insert_at_begining(int a){
    node *newnode,*temp=head;
    if(head==NULL){
        printf("List is empty and new node is assining to head\n");
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=NULL;
        head=newnode;
        
    }
    else{
        newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=temp;
        head=newnode;

    }
}

void insertion_intermediate(int a){
    int c;
    node *temp=head;
    printf("\nEnter the node which you want to insert new node before\n");
    scanf("%d",&c);
    while(temp->next!=NULL && temp->next->data!=c){
        temp=temp->next;
    }
    
     node *newnode=(node*)malloc(sizeof(node));
     newnode->data=a;
     newnode->next=temp->next;
     temp->next=newnode;
        

}

void insertion_end(int a){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
} 
    temp->next=(node*)malloc(sizeof(node));
    temp->next->data=a;
    temp->next->next=NULL;
    
}
void reverse(){
    node*current=head,*prev=NULL,*next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    
}

void secondlar(){
    int max=head->data, smax=0;
    node *i=head,*j;
    while(i!=NULL){
        if(i->data >max){
            smax=max;
            max=i->data;
        }
        else if(i->data > smax && i->data <max){
            smax=i->data;
        }
        i=i->next;
    }
    printf("%d",smax);
}

void deletion_at_begining(){
    node *temp=head;
    head=temp->next;
}

void deletion_intermediate(int a){
    node *temp=head;
    while(temp!=NULL&&temp->next->data!=a){
        temp=temp->next;
    }
    temp->next=temp->next->next;

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

    insert_at_begining(5);
    
    display();
    //deletion_at_begining();
    //display();
    //deletion_intermediate(5);
    //display();
   // insertion_intermediate(35);
    //display();
    insertion_end(20);
    insertion_end(80);
    insertion_end(100);
    insertion_end(30);

    display();
    //reverse();
    //display();
    secondlar();
    return 0;
}