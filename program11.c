/*
program demonstrates to find the determinant of matrix of same order.
Author: @Febin Sunny
Date: 27-07-2025
*/

#include<stdio.h>


int a[10][10],p,q,n;// Global declarations

void read() { // Function to read the matrix
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {  // Loop over rows
        for (int j = 0; j < n; j++) { // Loop over columns
            scanf("%d", &a[i][j]);
        }
    }
     printf("\nMatrix you entered:\n");
     // Display the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}


void cofactor_matrix(int a[10][10],int temp[10][10],int p,int q,int n){ // Function to build cofactor matrix by removing row p and column q
    int i = 0,j = 0;
    int row,col;
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            if(row != p && col != q){ // Copy only the elements not in row 'p' or column 'q'
                temp[i][j++]=a[row][col];
                if(j == n - 1){// When a row in temp is filled, move to next row
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int a[10][10],int n){// Recursive function to find determinant of matrix
    int result=0;  // Initialize result
    if(n==1){// Base case: single element matrix
        return a[0][0];

    }else{
        int sign = 1; // Sign multiplier for cofactors
        for(int i=0;i<n;i++){ // Iterate over first row elements
            int temp[10][10];   // Temporary matrix for minor
            cofactor_matrix(a,temp,0,i,n);// Get cofactor of element a[0][i]
            result+=sign * a[0][i] * determinant(temp,n-1);   // Apply cofactor expansion
            sign = -sign; // Alternate sign for next cofactor

        }
        return result;
    }
}

int main(){
    read(); // Read the matrix 
    int d=determinant(a,n); // calculate determinant
    printf("\n%d is the determinant ",d);// print the determinant
}