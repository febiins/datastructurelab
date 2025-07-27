/*
Program to implement stack operations using array
Author: @Febin Sunny
Date: 27-07-2025
*/
#include<stdio.h>

int stack[10],top = -1;

void push(int e){
    if(top+1 == 10){
        printf("Stack is overflow\n");
    }else{
        stack[++top]=e;
        printf("Element is pushed to stack\n");
    }
}

void pop(){
    if(top == -1){
        printf("Stack is underflow\n");
    }
    else{
        stack[top--];
        printf("Element is poped from stack\n");

    }
}

void peek(){
    if(top == -1){
         printf("Stack is underflow\n");

    }else{
        printf("%d is the element\n",stack[top]);
    }
}

int choice(){
    int ch;
    printf("push-1\n pop-2 \n peek-3 \n quit-4\n");
    scanf("%d",&ch);
    return ch;
}

void menu(){
    int c,element;
    for(c = choice();c != 4; c = choice()){
        switch(c){
            case 1:
            printf("Enter element\n");
            scanf("%d",&element);
            push(element);
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            break;
        }
    }
}

int main(){
    menu();
    return 0;
}