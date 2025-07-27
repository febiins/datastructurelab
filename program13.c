/*
Program to reverse a string using a stack (array)
Author: @Febin Sunny
Date: 27-07-2025
*/

#include<stdio.h>

// Stack array to hold characters, max size 10
char stack[10];
// Top pointer for stack
int top = -1;

// Function to push characters of input string onto the stack
void push(){
    char str[10];
    printf("Enter the string\n");
    // Read string from user (no spaces)
    scanf("%s",str);
    // Check for stack overflow
    if(top + 1 == 10){
        printf("Stack is overflow\n");
    }
    else{
        // Push each character onto the stack
        for(int i=0;str[i]!='\0';i++){
             stack[++top]=str[i];
        }
    }
}

// Function to pop and print all characters from the stack (reverse order)
void pop(){
    // Check for stack underflow
    if(top == -1){
        printf("Stack is underflow\n");
    }
    else{
        // Pop and print each character until stack is empty
        while(top != -1){
            char a=stack[top--];
            printf("%c",a);
        }
    }
}

// Main function to execute push and pop
int main(){
    push(); // Push string onto stack
    pop();  // Pop and print reversed string
}