/*
The program is for printing array elements using recursion in reverse order.
Author: @Febin Sunny 
Date:26-07-2025
*/
#include<stdio.h>

int a[5],pos=-1; //global variable
void insert(int e){  //function for inserting elements
    if(pos+1==5){  //check the array is full
        printf("Array is full\n");
    }
    else{  //if not full element is inserted
        a[++pos]=e;
        printf("Element is inserted\n");


    }

}
void display(int a[],int i, int pos){  //recursive function for printing array in reverse order
    if(pos<i){ //base case. checks the postion i is less than the index. 
        return;
    }
    else{  //print the elements in the array in reverse order and recursively call the display function
        printf("%d\t",a[pos]);
        pos--;
        display(a,i,pos);
       
    }

}

int main(){
    insert(5);  //inserting element
    insert(6);  //inserting element
    insert(3);  //inserting element
    display(a,0,pos);  //calling recursive function
  
    return 0;
}