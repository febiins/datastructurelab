/* The program used to demonstarates stack operations*/

#include<stdio.h>
#include<stdlib.h>

#define max 30

char stack[max];
int top = -1;

void push(char a){
    if(top==max-1){
        printf("\nStack Overflow");
    }
    else{
        stack[++top]=a;
        printf("\n%c pushed to stack\n",a);
    }
}

char pop(){
    if(top==-1){
        printf("\nstack is underflow");

    }else{
      return  stack[top--];
       
    }
}


void display(){
    char input[max];
    char output[max];
    int i=0, k=0;
    
    printf("\nEnter the elements to stack\n");
    scanf("%s",input);
    for(i=0;input[i]!='\0';i++){
        if(input[i]=='*'){
            output[k++]=pop();
        }
        else{
            push(input[i]);
        }

    }
    for(i=0;i<k;i++){
        printf("%c",output[i]);
    }
    
}

int main(){
    display();
    return 0;
}