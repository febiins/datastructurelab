/* Program to evaluate an expression using stack by converting it into postfix before evaluating
   @Febin Sunny
   Roll No 27 
   18/09/2025 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Global arrays
char stack[20], b[50], pf[50];   // stack for operators, b = infix input, pf = postfix output
int top=-1, ptop=-1;             // top for operator stack, ptop for postfix array

// Push an operator into stack
void push(char n) {
    if(top+1==20) {
        printf("Error: Stack is full\n");
    } else {
        stack[++top]=n;
    }
}

// Pop operator from stack and add to postfix array
void pop() {
    if(top==-1) {
        printf("Error: Stack is empty\n");
    } else {
        pf[++ptop]=stack[top--];
    }
}

// Return precedence of operator
int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0; // default case
}

// Push operator with precedence handling
void pushpres(char op) {
    // Pop higher/equal precedence operators before pushing the new one
    while(top!=-1 && precedence(stack[top])>=precedence(op)) {
        pop();
    }
    push(op);
}

// Convert infix expression (b) into postfix (pf)
void postfix() {
    int i;
    for(i=0;b[i]!='\0';i++) {
        if(isdigit(b[i])) {   // if operand (number)
            pf[++ptop]=b[i];
            // insert space after multi-digit number
            if(!isdigit(b[i+1])) pf[++ptop]=' ';
        } 
        else if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/') {
            pushpres(b[i]);   // operator
        } 
        else if(b[i]=='(') {
            push(b[i]);       // left parenthesis
        } 
        else if(b[i]==')') {
            // pop until matching '('
            while(stack[top]!='(') pop();
            top--;  // remove '('
        } 
        else if(b[i]!=' ') {  // invalid character
            printf("Error: Invalid Character in the Expression\n");
            return;
        }
    }
    // Pop any remaining operators
    while(top!=-1) pop();
    pf[++ptop]='\0';   // terminate postfix string
}

// Evaluate the postfix expression
void evaluate() {
    int i,vstack[20],vtop=-1,v1,v2,num=0;
    for(i=0;i<=ptop;i++) {
        if(isdigit(pf[i])) {   // if operand
            num=0;
            while(isdigit(pf[i])) {   // handle multi-digit numbers
                num=num*10+(pf[i]-'0');
                i++;
            }
            vstack[++vtop]=num;   // push number to value stack
        }
        if(pf[i]=='+'||pf[i]=='-'||pf[i]=='*'||pf[i]=='/') {
            // Pop two operands
            v2=vstack[vtop--];
            v1=vstack[vtop--];
            // Apply operator and push result
            switch(pf[i]) {
                case '+': vstack[++vtop]=v1+v2; break;
                case '-': vstack[++vtop]=v1-v2; break;
                case '*': vstack[++vtop]=v1*v2; break;
                case '/': vstack[++vtop]=v1/v2; break;
            }
        }
    }
    // Final result
    printf("The evaluated result is: %d\n", vstack[vtop]);
}

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", b);  // read full expression including spaces

    printf("The infix expression:\n%s\n", b);

    postfix();   // convert to postfix
    printf("The postfix expression:\n%s\n", pf);

    evaluate();  // evaluate postfix
    return 0;
}
