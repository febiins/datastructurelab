/*
The program is for demonstrating array operations using global variables in a menu driven format.
 Author: @Febin Sunny 
 Date:26-07-2025
 */ 
#include<stdio.h>

int a[5],pos=-1;  //global variables

void insert(int e){  //function for inserting
	if(pos+1==5){   //checking the array is empty
		printf("\n The array is full");
	}
	else{   //if not element is inserted
		a[++pos]=e;
		printf("\n Element is inserted");
	}
}

void delete(){    //function for deleting
	if(pos==-1){  //checking the array is empty 
		printf("\nThe array is empty");
	}
	else{     //if not empty element in the current position is deleted
		int del=a[pos];
		printf("Element deleted is %d",del);
		a[pos--];
	}
}

void display(){  //function for displaying array elements
	int i;
	for(i=0;i<=pos;i++){
		printf("%d\t",a[i]);
	}
}


int menu(){  //menu function for choice
	int ch;
	printf("\nInsert-1 \n Delete-2 \n Display-3\n Quit-4\n ");
	scanf("%d",&ch);
	return ch;
	
}
void process(){  //function which calls operation based on your choice
	int choice,element;
	for(choice=menu();choice!=4;choice=menu()){
		switch(choice){
			case 1:         //insert
				printf("\nEnter the element to insert");
				scanf("%d",&element);
				insert(element);
				break;
		    case 2:         //delete
		    	delete();
				break;	
		    case 3:         //display
		    	display();
				break;	
			case 4:        //exit
		    	
				break;
			
				
			default:
			printf("Invlaid choice");						
				
		}
	}
}
int main(){
	process();  //calling the process function for the operation
	
	return 0;
	
}
