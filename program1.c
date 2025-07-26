/*
The program is for demonstrating storage classes. 
Author: @Febin Sunny 
Date:26-07-2025
*/ 
#include<stdio.h>

int a=10; //global variable


void dis(){  // function accessing global variable 
	printf("Global variable a=%d\n",a);
}


void local_variable(){
	int a =40;  //local variable
	printf("Local variable a= %d\n ",a);
}
void no_static_variable(){  //function without using static variable
	 int a=0;  // local variable declared with datatype
	 a++;
	printf("value without using static %d\n",a);
	
}
void static_variable(){  // function using static
	static int b=0;  //variable declared using static
	b++;
	printf("value using static %d\n",b);
	
}

 void register_variable(){  //function for register variable
	register int i;  //declaring register variable
	for(i=0;i<=5;i++){
		printf("using register variable=%d\n",i);
	}
 }
int main(){
	dis();  //function for global variable is called
	local_variable();  //function for local variable is called
	no_static_variable();  //function call without using static variable
	no_static_variable();  //function call without using static variable
	static_variable();  //function call  using static variable
	static_variable();  //function call  using static variable
	register_variable();  // function have register variable is called
	return 0;
} 
