/*program used to demonstrate read a matrix and convert it into sparse
@Febin Sunny
1-10-2025
Rollno:27
*/


#include<stdio.h>

int a[10][10];   //decalring as global variable
int row,col;      //decalring as global variable


void read(){  //function to read a matrix
    int i,j;
    printf("Enter the row and column of matrix\n");
    scanf("%d%d",&row,&col);
    printf("Enter the elements of matrix\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("The matrix is\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void sparse(){  //function converts into sparse matrix
    int i,j,k,count=0;
    
    for(i=0;i<row;i++){    //Loop which used to take the count of non-zero values
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
                count++;
            }
        }
    }
    int sparse[count+1][3];   //sparse matrix is decalred locally

    sparse[0][0]=row;      //assingned number of row
    sparse[0][1]=col;      //assingned number of column 
    sparse[0][2]=count;    //assingned number of non-zero values
    k=1;
    for(i=0;i<row;i++){      //Loop creates the sparse matrix
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=a[i][j];
                k++;

            }
            
        }
    }
    printf("The sparse matrix is\n");
    for( i = 0; i <= count; i++) {    //printing the sparse matrix
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main(){
    read();
    sparse();
    return 0;
}