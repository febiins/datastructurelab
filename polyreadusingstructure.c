#include<stdio.h>
#include<stdlib.h>

// Structure to represent a term in the polynomial
typedef struct poly{
    int coeff;      // Coefficient of the term
    int exponen;    // Exponent of the term
} term;

term a[10];         // Array to store polynomial terms
int n;              // Number of terms in the polynomial

// Function to read polynomial terms from user
void read(){
    int i;
    printf("\nEnter the number of terms\n");
    scanf("%d",&n);
    printf("Enter the polynomial\n");
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].coeff,&a[i].exponen); // Read coefficient and exponent
    }
}

// Function to print the polynomial in readable format
void print(){
    int c,e;
    for(int i=0;i<n;i++){
         c=a[i].coeff;    // Get coefficient
         e=a[i].exponen;  // Get exponent
         
         if(c==0)         // Skip terms with zero coefficient
            continue;
        int a =abs(c);    // Absolute value of coefficient
         
         // Print sign for terms except the first
         if(i!=0){
            if(c>0){
                printf("+");
            }else{
                printf("-");
            }
        }else{
            if(c<0){
                printf("-");
            }
        }
        // Print term based on exponent value
        if(e==0){
            printf("%d",a);           // Constant term
        }
        else if(e==1){
            if(a==1){
                printf("x");          // x term with coefficient 1
            }else{
                printf("%dx",a);      // x term with coefficient not 1
            }
         }
         else{
            if (a==1){
                printf("x^%d",e);     // x^e term with coefficient 1
            }
            else{
                printf("%dx^%d",a,e); // x^e term with coefficient not 1
            }
         }
    }
}

// Main function
int main(){
    read();   // Read polynomial from user
    print();  // Print the polynomial
    return 0;
}