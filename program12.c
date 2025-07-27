/*
Program to implement stack operations using array
Author: @Febin Sunny
Date: 27-07-2025
*/
#include<stdio.h>

// Stack array and top pointer
int stack[10],top = -1;

// Function to push an element onto the stack
void push(int e){
    // Check for stack overflow
    if(top+1 == 10){
        printf("Stack is overflow\n");
    }else{
        stack[++top]=e; // Increment top and add element
        printf("Element is pushed to stack\n");
    }
}

// Function to pop an element from the stack
void pop(){
    // Check for stack underflow
    if(top == -1){
        printf("Stack is underflow\n");
    }
    else{
        stack[top--]; // Decrement top to remove element
        printf("Element is poped from stack\n");
    }
}

// Function to view the top element of the stack
void peek(){
    // Check for stack underflow
    if(top == -1){
         printf("Stack is underflow\n");
    }else{
        printf("%d is the element\n",stack[top]);
    }
}

// Function to display menu and get user choice
int choice(){
    int ch;
    printf("push-1\n pop-2 \n peek-3 \n quit-4\n");
    scanf("%d",&ch);
    return ch;
}

// Function to handle menu-driven stack operations
void menu(){
    int c,element;
    // Loop until user chooses to quit (option 4)
    for(c = choice();c != 4; c = choice()){
        switch(c){
            case 1:
            printf("Enter element\n");
            scanf("%d",&element);
            push(element); // Push element onto stack
            break;
            case 2:
            pop(); // Pop element from stack
            break;
            case 3:
            peek(); // View top element
            break;
            case 4:
            break;
        }
    }
}

// Main function to start the program
int main(){
    menu();
    return 0;
}