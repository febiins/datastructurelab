#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char str[100];
    struct node *next;
}node;

node *head=NULL;

void insert_begining(char *value){
    node *newnode;
    if(head==NULL){
        printf("The list is empty\n");
        newnode=(node*)malloc(sizeof(node));
        strcpy(newnode->str,value);
        newnode->next=NULL;
        head=newnode;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode=(node*)malloc(sizeof(node));
        temp->next=newnode;
        strcpy(newnode->str,value);
        newnode->next=NULL;
    }
}

void intermediate(char *value){
    char  str[100];
    node *temp=head,*newnode;
    printf("Enter the node where you want to insert after\n");
    gets(str);
    while(temp!=NULL&&strcmp(temp->str,str)!=0){
        temp=temp->next;
    }
    newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->str,value);
    newnode->next=temp->next;
    temp->next=newnode;
}

void delete(){
    char str[100];
    node *t=head;
    printf("Enter the string to delete");
    gets(str);
    while(t!=NULL&&strcmp(t->next->str,str)!=0){
        t=t->next;
    }
    t->next=t->next->next;

}

void sor(){
    node *i,*j;
    char temp[100];
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(strcmp(i->str,j->str)>0){
                strcpy(temp,i->str);
                strcpy(i->str,j->str);
                strcpy(j->str,temp);
            }
        }
    }
}
void display(){
    node *t=head;
    while(t!=NULL){
        printf("%s\t",t->str);
        t=t->next;
    }
}

int main(){
    insert_begining("febin");
    insert_begining("sunny");
    insert_begining("albin");
    insert_begining("bibn");
    display();
    intermediate("feba");
    sor();
    display();
    //delete();
    //display();
    //delete();
    //display();
    
    return 0;
}


