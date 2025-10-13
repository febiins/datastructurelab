#include<stdio.h>
#include<stdlib.h>

void mean(){
    int n;
    int *a;
    printf("Enter the number of terms\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
         sum+=a[i];
    }
    int mean=sum/n;
    printf("%d",mean);
    free(a);
}

int main(){
    mean();
}