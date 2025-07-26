/*program used to demonstrate matrix addition and substration.
Author: @Febin Sunny
Date: 26-07-2025
*/
#include<stdio.h>

int a[10][10],b[10][10],result[10][10]; //declared as global
int row1,col1,row2,col2;//declared as global

void read(){ //funcrion for reading matrix
    int i,j; //declared variables for loop
    
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
    int i,j; //declared variables for loop
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
void add(){
    int i,j; //declared variables for loop
    if(row1==row1 && col1==col2){//loop which do the addition operation
        for(i=0;i<row1;i++){
            for(j=0;j<row2;j++){
                result[i][j]= a[i][j] + b[i][j];
            }
        }

        printf("Sum is\n");

    for(i=0;i<row1;i++){//displays the resultant matrix
        for(j=0;j<col1;j++){
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }
    }else{
        printf("order of matrix is not same\n");
    }

}

void sub(){
     int i,j; //declared variables for loop
    if(row1==row1 && col1==col2){
        for(i=0;i<row1;i++){ //loop which do the substraction operation
            for(j=0;j<row2;j++){
                result[i][j]= b[i][j] - a[i][j];
            }
        }

        printf("Difference is\n");

    for(i=0;i<row1;i++){ //displays the resultant matrix
        for(j=0;j<col1;j++){
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }
    }else{
        printf("order of matrix is not same\n");
    }
    
    

}

int main(){
    read(); // function called for reading matrix
    display(); // function called for displaying the enterd matrix
    add(); // function called for adding two matrix
    sub(); // function called for substracting two matrix
    return 0;
}