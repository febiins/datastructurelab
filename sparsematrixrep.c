#include<stdio.h>

int a[10][10];
int row,col;


void read(){
    int i,j;
    printf("Enter the row and column of matrix\n");
    scanf("%d%d",&row,&col);
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

void sparse(){
    int i,j,k,count=0;
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
                count++;
            }
        }
    }
    int sparse[count+1][3];

    sparse[0][0]=row;
    sparse[0][1]=col;
    sparse[0][2]=count;
    k=1;
    for(i=0;i<row;i++){
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
    for( i = 0; i <= count; i++) {
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

printf("Convert into matrix\n");
int b[10][10];
int c;
row =sparse[0][0];
col=sparse[0][1];
c=sparse[0][2];

for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        b[i][j]=0;

    }
}

for(k=1;k<=c;k++){
    int ro=sparse[k][0];
    int co=sparse[k][1];
    int v=sparse[k][2];
    b[ro][co]=v;
}
printf("The original matrix is\n");
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        printf("%d\t",b[i][j]);
    }
    printf("\n");
}

}


int main(){
    read();
    sparse();
    return 0;
}