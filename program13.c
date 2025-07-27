/*
Program to reverse a string using a stack (array)
Author: @Febin Sunny
Date: 27-07-2025
*/

#include<stdio.h>

char stack[10];
int top = -1;


void push(){
    char str[10];
    printf("Enter the string\n");
    scanf("%s",str);
    if(top + 1 == 10){
        printf("Stack is overflow\n");
    }
    else{
        for(int i=0;str[i]!='\0';i++){
             stack[++top]=str[i];

        }
       
    }

}

void pop(){
    if(top == -1){
        printf("Stack is underflow\n");
    }
    else{
        while(top != -1){
        char a=stack[top--];
        printf("%c",a);
        }
    }
}

int main(){
    push();
    pop();
}