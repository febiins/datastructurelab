/* program used to demonstrate the conversion of infix to postfix expression
   @Febin Sunny
   Rollno:27
   18-09-2025
*/

#include<stdio.h>

#include<string.h>
#include<ctype.h>

#define max 30 // Maximum size of the stack

char stack[max]; // Array to implement stack
int top = -1;    // Stack top pointer

void push(char a){
    if(top == max - 1){
        printf("\nStack Overflow"); // Stack is full
    }
    else{
        stack[++top] = a; // Increment top and add element
    }
}

char pop(){
    if(top == -1){
        printf("\nStack Underflow"); // Stack is empty
        return '\0';
    }
    else{
        return stack[top--]; // Return top element and decrement top
    }
}

char peek(){
    if(top == -1){
        return '\0'; // Empty stack
    }
    else{
        return stack[top]; // Return top element without decrementing top
    }
}

int precedence(char a){
    switch(a)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isoperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^'){
        return 1; // Character is an operator
    }
    return 0; // Not an operator
}

void infixtopostfix(){
    char infix[max], postfix[max];
    int i, j = 0;
    char ch;

    printf("\nEnter the infix expression:\n");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++){
        ch = infix[i];
        
        if(isalnum(ch)){   // operand
            postfix[j++] = ch;
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            while(top != -1 && peek() != '('){
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        else if(isoperator(ch)){
            while(top != -1 && precedence(peek()) >= precedence(ch)){
                if(ch == '^' && peek() == '^'){  // handle right associativity
                    break;
                }
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null terminate
    printf("Postfix expression is: %s\n", postfix);
}

int main(){
    infixtopostfix();
    return 0;
}
