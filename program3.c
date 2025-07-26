/*
The program is for demonstrating array operations using local variables in a menu driven format.
 Author: @Febin Sunny 
 Date:26-07-2025
 */ 

#include<stdio.h>

void insert(int a[5],int *pos,int e){  //function for inserting elements

	if(*pos+1==5){  //checking the array is full
		printf("\n The array is full");
	}
	else{  //if not element is inserted
		a[++*pos]=e;
		printf("\n Element is inserted");
	}
	

}

void delete(int a[5],int *pos){  //function for deleting elements
	if(*pos==-1){  //checking the array is empty
		printf("\nThe array is empty");
	}
	else{  //if not empty element in the current position is deleted
		int del=a[*pos];
		printf("Element deleted is %d",del);
		a[(*pos)--];
	}
}

void display(int a[5],int *pos){  //function for displaying elements
	int i; //declaring variable
	for(i=0;i<=*pos;i++){
		printf("%d\t",a[i]);
	}
}

int menu(){  //menu function for choice
	int ch;  //delcartion variable  
	printf("\nInsert-1 \n Delete-2 \n Display-3 \n Quit -4\n  ");
	scanf("%d",&ch);
	return ch;  //returning the choice
	
}
void process(int a[5],int *pos){  //function which calls operation based on your choice
	int choice,element;
	for(choice=menu();choice!=4;choice=menu()){
		switch(choice){
			case 1:            //insert
				printf("\nEnter the element to insert");
				scanf("%d",&element);
				insert(a,pos,element);
				break;
		    case 2:           //delete
		    	delete(a,pos);
				break;	
		    case 3:           //display
		    	display(a,pos);
				break;	
			case 4:          //exit
		    	
				break;
			
				
			default:
			printf("Invlaid choice");						
				
		}
	}
}
int main(){
	int a[5],pos=-1;  //local variable
	process(a,&pos); //passing the array and address of pos due to using pointer
	
	return 0;
	
}
