#include<stdio.h>



void insert(int a[5],int *pos,int e){

	if(*pos+1==5){
		printf("\n The array is full");
	}
	else{
		a[++*pos]=e;
		printf("\n Element is inserted");
	}
	

}

void delete(int a[5],int *pos){
	if(*pos==-1){
		printf("\nThe array is empty");
	}
	else{
		int del=a[*pos];
		printf("Element deleted is %d",del);
		a[(*pos)--];
	}
}

void display(int a[5],int *pos){
	int i;
	for(i=0;i<=*pos;i++){
		printf("%d\t",a[i]);
	}
}

int menu(){
	int ch;
	printf("\nInsert-1 \n Delete-2 \n Display-3 \n Quit -4\n  ");
	scanf("%d",&ch);
	return ch;
	
}
void process(int a[5],int *pos){
	int choice,element;
	for(choice=menu();choice!=4;choice=menu()){
		switch(choice){
			case 1:
				printf("\nEnter the element to insert");
				scanf("%d",&element);
				insert(a,pos,element);
				break;
		    case 2:
		    	delete(a,pos);
				break;	
		    case 3:
		    	display(a,pos);
				break;	
			case 4:
		    	
				break;
			
				
			default:
			printf("Invlaid choice");						
				
		}
	}
}
int main(){
	int a[5],pos=-1;
	process(a,&pos);
	
	return 0;
	
}
