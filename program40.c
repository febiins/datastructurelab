/*Program to find mean of n numbers using malloc
@Febin Sunny 
Roll No 27
3-10-2025
*/


#include<stdio.h>
#include<stdlib.h>

void mean(){
    int n;
    float sum=0;
    float mean=0;
    int *ptr;

    printf("Enter the number of terms\n");
    scanf("%d",&n);

    ptr=(int*)malloc(n*sizeof(int));

    printf("\nEnter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }

    printf("\nThe numbers are\n");

    for(int i=0;i<n;i++){
        printf("%d\t",ptr[i]);
    }

    for(int i=0;i<n;i++){
        sum +=ptr[i];

    }

    mean=sum/n;
    printf("\nThe mean is :%f",mean);
    free(ptr);
}

int main(){
    mean();
    return 0;
}