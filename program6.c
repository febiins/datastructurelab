/*
 The program is for printing array elements using recursion.
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
void display(int a[],int i, int pos){  //recursive function
    if(i>pos){ //base case. checks the index i is greater than the position. 
        return;
    }
    else{  //print the elements in the array and recursively call the display function
        printf("%d\t",a[i]);
        display(a,i+1,pos);
       
    }

}


int choice(){
    int ch;
    printf("\nEnter your choice 1.Insert 2.Display 3.Exit\n");
    scanf("%d",&ch);
    return ch;
}
void menu(){
    int c,e;
    for(c=choice();c!=3;c=choice()){
        switch(c){
            case 1: printf("Enter elements\n");
            scanf("%d",&e);
            insert(e);
            break;
            case 2: display(a,0,pos);
            break;
            case 3:
            break;
            default:
            printf("Invalid choice");
        }
    }
}

int main(){
   
    menu();
  
    return 0;
}