/*
program demonstrates search a given element from an array of elements.
Author: @Febin Sunny
Date: 26-07-2025
*/

#include<stdio.h>
int a[5],pos=-1;//Global variable

void insert(int e){ // function to insert elements
    if(pos+1==10){
        printf("Array is full\n");
    }else{
        a[++pos]=e;
        printf("Element is inserted\n");
    }
}
void search(int x){//function to search an element in an array
    int n=0;
    for(int i=0;i<=pos;i++){
        n++;
    }
   printf("%d\n",n);


    for(int i=0;i<n;i++){
        if(x==a[i]){
            printf("%d is founded\n",a[i]);
        }
        
    }

}

int choice(){//function for choice
    int c;
    printf("\n 1-Insert\n 2-Search\n 3-Exit\n");
    scanf("%d",&c);
    return c;
}

void menu(){//function  for menu driven format
    int ch,element,ser;
    for(ch=choice();ch!=3;ch=choice()){
        switch(ch){
            case 1:
            printf("Enter the element to insert\n");
            scanf("%d",&element);
            insert(element);
            break;
            case 2:
            printf("Enter the element to search\n");
            scanf("%d",&ser);
            search(ser);
            break;
            case 3:
            break;
            default:
            printf("Invalid value\n");
        }
    }

   
}
int main(){
    menu();//menu function is calling
    return 0;
}