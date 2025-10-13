#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&&arr[left]>arr[right]){
        largest=left;
    }

    if(right<n&&arr[left]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: One by one extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);     // Move current root to end
        heapify(arr, i, 0);         // call heapify on reduced heap
    }
}
int main(){
    return 0;
}