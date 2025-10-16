/*Program to demonstrate malloc,calloc and free
@Febin Sunny 
Roll No 27
3-10-2025
*/

#include<stdio.h>
#include<stdlib.h>

void implement(){
    int *ptr;
    int n;
    printf("\nEnter the number of allocation you need \n");
    scanf("%d",&n);
    ptr=(int *)malloc( n*sizeof(int));    //allocating memory using malloc
    printf("\nEnter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }
    printf("\nprinting the elements (implementation of malloc)\n");
    for(int i=0;i<n;i++){
        printf("%d\t",ptr[i]);
    }
    free(ptr);    //use to free the memory

    ptr=(int*)calloc(n,sizeof(int));    //memory allocation using calloc
    printf("\nprinting initial elements in memory(after allocating using calloc)\n");
    for(int i=0;i<n;i++){
        printf("%d\t",ptr[i]);
    }
    free(ptr);

}


int main(){
    implement();
    return 0;
}