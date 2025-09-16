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

void sort(){
    node *t1,*t2;
    int temp;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    for(t1=head;t1->next!=NULL;t1=t1->next){
        for(t2=t1->next;t2!=NULL;t2=t2->next){
            if(t1->data>t2->data){
                temp=t1->data;
                t1->data=t2->data;
                t2->data=temp;
            }
        }
    }

}

void search(){
    int a,b;
    printf("Enter the element to search\n");
    scanf("%d",&a);
    printf("Enter element to replace\n");
    scanf("%d",&b);
    node *t,*prev;
    t=head;
    prev=head;
    if(head==NULL){
        printf("List is empty\n");

    }else{
        while(prev->next!=NULL && t->next->data!=a){
            if(t->data==a){
                printf("%d Element is found\n",t->data);
            }
            
        }
        prev->next->data=b;
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
/*-----------------------------------------------------------------------------------------------------------*/
/*Creating a new node for polynomial representation*/

typedef struct poly{
    int coeff;
    int pow;
    struct poly *next;
} poly;
poly *start=NULL;

void insertpoly(){
    int c,p;
    printf("Enter coefficient and power\n");
    scanf("%d%d",&c,&p);
    poly *newnode;
    newnode=(poly*)malloc(sizeof(poly));
    newnode->coeff=c;
    newnode->pow=p;
    newnode->next=NULL;
    if(start==NULL){
        start=newnode;
    }
    else{
        poly *t;
        t=start;
        while(t->next!=NULL){
            t=t->next;
}
        t->next=(poly*)malloc(sizeof(poly));
        t->next->coeff=c;
        t->next->pow=p;
        t->next->next=NULL;
    }
    

}

void poly_display(){
    poly *t;
    t=start;
    while(t!=NULL){
        printf("%dx^%d",t->coeff,t->pow);
        t=t->next;

    }

}



int main(){
    insert(6);
    insert(3);
    insert(5);
    insert(1);
    deletion();
    display();
    sort(); 
    display();
    search();
    display();
    return 0;
}