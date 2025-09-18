/* The program used to demonstarates stack operations
    @Febin Sunny
    Rollno: 27
    27-07-2025
*/

#include<stdio.h>
#include<stdlib.h>

#define max 30 // Maximum size of the stack

char stack[max]; // Array to implement stack
int top = -1;    // Stack top pointer

// Function to push an element onto the stack
void push(char a){
    if(top==max-1){
        printf("\nStack Overflow"); // Stack is full
    }
    else{
        stack[++top]=a; // Increment top and add element
        printf("\n%c pushed to stack\n",a);
    }
}

// Function to pop an element from the stack
char pop(){
    if(top==-1){
        printf("\nstack is underflow"); // Stack is empty
    }else{
        return stack[top--]; // Return top element and decrement top
    }
}

// Function to read input, perform stack operations, and display output
void display(){
    char input[max];  // Array to store input string
    char output[max]; // Array to store output
    int i=0, k=0;
    
    printf("\nEnter the elements to stack\n");
    scanf("%s",input); // Read input string
    for(i=0;input[i]!='\0';i++){
        if(input[i]=='*'){ // If '*' encountered, pop from stack
            output[k++]=pop();
        }
        else{
            push(input[i]); // Otherwise, push character to stack
        }
    }
    for(i=0;i<k;i++){
        printf("%c",output[i]); // Print output characters
    }
}

// Main function
int main(){
    display(); // Call display function to perform stack operations
    return 0;
}