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
		printf("%d",del);
		a[(*pos)--];
	}
}

void display(int a[5],int *pos){
	int i;
	for(i=0;i<*pos;i++){
		printf("%d",a[i]);
	}
}

void sort(int a[5],int *pos){
	int i,j;
	printf("\nsorting");
	for(i=0;i<*pos;i++){
		for(j=i+1;j<*pos;j++){
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
void process(int a[5],int *pos){
	int choice,element;
	for(choice=menu();choice!=5;choice=menu()){
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
		    	sort(a,pos);
				break;
			case 5:
		
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
