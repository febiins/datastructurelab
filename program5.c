/*
program is for sort an array of numbers in ascending order.
Author: @Febin Sunny
Date: 26-07-2025

*/

#include<stdio.h>

int a[10],pos=-1;

void insert(int e){
    if(pos+1==10){
        printf("The array is empty\n");
    }
    else{
        a[++pos]=e;
        printf("Element is entered\n");
    }
}

void display(){
    printf("The array is\n");
    for(int i=0;i<=pos;i++){
        printf("%d\t",a[i]);
    }
}

void sort(){
    int temp;
    for(int i=0;i<=pos;i++){
        for(int j=i+1;j<=pos;j++)
        if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}

int choice(){//function for choice
    int c;
    printf("\n 1-Insert\n 2-Display\n 3-Sort\n 4-Exit\n");
    scanf("%d",&c);
    return c;
}

void menu(){//function  for menu driven format
    int ch,element,ser;
    for(ch=choice();ch!=4;ch=choice()){
        switch(ch){
            case 1:
            printf("Enter the element to insert\n");
            scanf("%d",&element);
            insert(element);
            break;
            case 2:
            display();
            break;
            case 3:
            sort();
            break;
            case 4:
            break;
            default:
            printf("Invalid value\n");
        }
    }
}

int main(){
    menu();


    return 0;
}