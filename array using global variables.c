#include<stdio.h>

int a[5],pos=-1;

void insert(int e){
	if(pos+1==5){
		printf("\n The array is full");
	}
	else{
		a[++pos]=e;
		printf("\n Element is inserted");
	}
}

void delete(){
	if(pos==-1){
		printf("\nThe array is empty");
	}
	else{
		int del=a[pos];
		printf("%d",del);
		a[pos--];
	}
}

void display(){
	int i;
	for(i=0;i<pos;i++){
		printf("%d",a[i]);
	}
}

void sort(){
	int i,j;
	printf("\nsorting");
	for(i=0;i<pos;i++){
		for(j=i+1;j<pos;j++){
			if(a[i]>=a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int menu(){
	int ch;
	printf("\nInsert-1 \n Delete-2 \n Display-3 \n Sort -4\n  ");
	scanf("%d",&ch);
	return ch;
	
}
void process(){
	int choice,element;
	for(choice=menu();choice!=5;choice=menu()){
		switch(choice){
			case 1:
				printf("\nEnter the element to insert");
				scanf("%d",&element);
				insert(element);
				break;
		    case 2:
		    	delete();
				break;	
		    case 3:
		    	display();
				break;	
			case 4:
		    	sort();
				break;
			case 5:
		
				break;
				
			default:
			printf("Invlaid choice");						
				
		}
	}
}
int main(){
	process();
	
	return 0;
	
}
