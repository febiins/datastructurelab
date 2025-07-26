/*
program used to demonstrates matrix multiplication
Author: @Febin Sunny
Date: 26-07-2025
*/
#include<stdio.h>

int a[10][10],b[10][10],result[10][10]; //declared as global
int row1,col1,row2,col2,i,j,k;//declared as global

void read(){ //funcrion for reading matrix
   
    
    printf("Enter the row and cloumn of first matrix\n"); //inputing row and column of matrix one
    scanf("%d%d",&row1,&col1);
    printf("Enter the elements of first matrix\n");
    for( i=0;i<row1;i++){ // loop 1 for first matrix
        for(j=0;j<col1;j++){
            scanf("%d",&a[i][j]);
        }
    }

     printf("Enter the row and cloumn of second matrix\n");  //inputing row and column of matrix two
     scanf("%d%d",&row2,&col2);

     printf("Enter the elements of second matrix\n");
    for( i=0;i<row2;i++){ // loop 2 for first matrix
        for(j=0;j<col2;j++){
            scanf("%d",&b[i][j]);
        }
    }

}


void display(){
    
    printf("Displaying first matrix\n"); 
    for(i=0;i<row1;i++){ // loop 1 for displaying first matrix
        for(j=0;j<col1;j++){
            printf("%d\t",a[i][j]);
            
        }
        printf("\n");
    }

    printf("Displaying second matrix\n");
    for(i=0;i<row2;i++){ // loop 2 for displaying second matrix
        for(j=0;j<col2;j++){
            printf("%d\t",b[i][j]);
            
        }
        printf("\n");
    }
}

void mul(){
    if(col1 == row2){ // Check if matrix multiplication is possible
        for(i=0;i<row1;i++){ // Loop through each row of the first matrix 
            for(j=0;j<col2;j++){  // Loop through each column of the second matrix
                result[i][j]=0; // Initialize result element
                for(k=0;k<col1;k++){ // Multiply row of first and column of second
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        printf("Resultant matrix is\n");

        for(i=0;i<row1;i++){ // Displaying the result matrix
            for(j=0;j<col2;j++){
                printf("%d\t",result[i][j]);
            }
            printf("\n");
        }

    }
}

int main(){

    read(); // Reads matrix
    display();  // Displays input matrices 
    mul();      // Performs matrix multiplication and shows result
    
    return 0;
}