/*Program to find mode of n numbers using calloc
@Febin Sunny 
Roll No 27
3-10-2025
*/


#include<stdio.h>
#include<stdlib.h>

void mode(){
    int n;
    int max=0,mode=0;
    int *ptr;

    printf("Enter the number of terms\n");
    scanf("%d",&n);

    ptr=(int*)calloc(n,sizeof(int));

    printf("\nEnter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }

    printf("\nThe numbers are\n");

    for(int i=0;i<n;i++){
        printf("%d\t",ptr[i]);
    }

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i+1;j<n;j++){
            if(ptr[i]==ptr[j]){
                count++;
            }

        }
        if(count>max){
            max=count;
            mode=ptr[i];
        }
        
    }

    printf("\nThe mode is :%d",mode);
    free(ptr);
}

int main(){
    mode();
    return 0;
}