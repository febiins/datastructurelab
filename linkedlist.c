/*insertion,deletion,search and replace,sort,display,polynomial representation,count of node operations on linked list*/

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
void count(){
    node *t;
    int c=0;
    t=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    while(t!=NULL){
        c++;
        t=t->next;
    }
    printf("Count of nodes is %d\n",c);
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
        t->next=newnode;
       
    }
    

}

void poly_display(){
    poly *t;
    t=start;
    while(t!=NULL){
        printf("%dx^%d",t->coeff,t->pow);
        if(t->next != NULL){
            printf(" + ");
        }
        t=t->next;

    }
    printf("\n");

}

int choice(){
    int ch;
    printf("\nEnter your choice \n1.insert\n2.delete\n3.display\n4.sort\n5.search and replace\n6.polynomial repersentation\n7.display polynomial\n8.count of nodes\n9.exit\n");
    scanf("%d",&ch);
    return ch;
}

void menu(){
    int c,e;
    for(c=choice();c!=9;c=choice()){
        switch(c){
            case 1:
              printf("Enter the element to insert\n");
              scanf("%d",&e);
              insert(e);
              break;
            case 2:
             deletion();
             break;
            case 3:
             display();
             break;
            case 4:
             sort();
             break;
            case 5:
             search();
             break;
            case 6:
             insertpoly();
             break;
            case 7:
             poly_display();
             break;
            case 8:
             count();
             break;
            case 9:
             break;
            default:
             printf("Invalid choice\n"); 
        }
    }
}

int main(){
    menu();
    return 0;
}