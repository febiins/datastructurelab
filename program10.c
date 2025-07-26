/*
program used to demonstrates transpose of matrix 
Author: @Febin Sunny
Date: 26-07-2025
*/
#include<stdio.h>

int a[10][10],b[10][10]; //declared as global
int row1,col1,i,j;//declared as global

void read(){ //funcrion for reading matrix
   
    
    printf("Enter the row and cloumn of first matrix\n"); //inputing row and column of matrix one
    scanf("%d%d",&row1,&col1);
    printf("Enter the elements of first matrix\n");
    for( i=0;i<row1;i++){ // loop 1 for first matrix
        for(j=0;j<col1;j++){
            scanf("%d",&a[i][j]);
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
}

void transpose(){// function for transpose
    for(i=0;i<col1;i++){ //loops which do the transpose operation
        for(j=0;j<row1;j++){
            b[i][j]=a[j][i];
        }
    }
    printf("Transpose of matrix is\n");//displays the transformed matrix
    for(i=0;i<col1;i++){
        for(j=0;j<row1;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}

int main(){
    read();
    display();
    transpose();
    return 0;
}