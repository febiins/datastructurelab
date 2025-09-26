/* 
Program to evaluate an infix expression using stack
@Febin Sunny
Rollno:27 
18/09/2025 
*/

#include<stdio.h>
#include<ctype.h>   // for isdigit() function

// Function to return precedence of operators
int precedence(char op)
{
    switch(op)
    {
        case '/':
        case '*':
            return 1;   // Higher precedence
        case '+':
        case '-':
            return 0;   // Lower precedence
    }
    return -1;  // For invalid operator
}

// Function to apply the operator on two operands
int apply(int a,int b,char sign)
{
    switch(sign)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;   // Assume denominator ≠ 0
    }
    return 0;   // Default (shouldn’t reach here)
}

// Function to evaluate infix expression
int infix_evaluate(char a[100])
{
    int i = 0, vstack[100], vtop = -1;     // Operand stack & top
    char opstack[100], sign;               // Operator stack & operator variable
    int otop = -1;                         // Operator stack top
    int v1, v2;                            // Two operands for evaluation
    int number = 0;                        // To store multi-digit numbers

    while (a[i] != '\0')   // Loop through expression
    {
        if (isdigit(a[i]))   // If digit → form the complete number
        {
            number = 0;
            while (isdigit(a[i]))          // Handle multi-digit numbers
            {
                number = number * 10 + (a[i] - '0');
                i++;
            }
            vstack[++vtop] = number;       // Push number to operand stack
            continue;                      // Skip i++ here (already done in loop)
        }
        else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            // While operator stack not empty & precedence of top ≥ current operator
            while (otop != -1 && precedence(opstack[otop]) >= precedence(a[i]))
            {
                v2 = vstack[vtop--];       // Pop 2 operands
                v1 = vstack[vtop--];
                sign = opstack[otop--];    // Pop operator
                vstack[++vtop] = apply(v1, v2, sign); // Push result
            }
            opstack[++otop] = a[i];        // Push current operator
        }
        i++;   // Move to next character
    }

    // Apply remaining operators in stack
    while (otop != -1)
    {
        v2 = vstack[vtop--];
        v1 = vstack[vtop--];
        sign = opstack[otop--];
        vstack[++vtop] = apply(v1, v2, sign);
    }
    return vstack[0];   // Final result is in operand stack
}

int main()
{
    char a[100];    // Input expression
    int result;

    printf("Enter infix expression: ");
    scanf("%s", a);   // Read input (without spaces, e.g., 3+5*2)

    result = infix_evaluate(a);    // Evaluate expression
    printf("Result: %d", result);  // Print result

    return 0;
}
