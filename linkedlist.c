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





void deletion(){
    node *t;
    int a;
    printf("Enter the element to delete\n");
    scanf("%d",&a);
    if(head==NULL){
            printf("List is empty\n");
        }
    else if(head->data==a){
        head=head->next;

    }
    else{
        t=head;
        while(t->next!=NULL && t->next->data!=a){
            t=t->next;
        }
        if(t->next==NULL){
            printf("Element is not found\n");
        }
        else{
            t->next=t->next->next;
        }

    }
   
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
    deletion(); 
    display();
    return 0;
}