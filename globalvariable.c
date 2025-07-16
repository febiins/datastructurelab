#include<stdio.h>

int a=10; //global variable


void dis(){
	printf("%d",a);
}

void next(){
	printf("\n%d",a);
}

int main(){
	dis();
	next();
	return 0;
} 
