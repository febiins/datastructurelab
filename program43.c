/*Program to demonstrate Use of realloc to implement varchar for any length.
@Febin Sunny 
Roll No 27
3-10-2025
*/

#include<stdio.h>
#include<stdlib.h>

void read(){
    char *ptr;
    int size;
    int len=0;
    printf("Enter the size\n");
    scanf("%d",&size);
    getchar();
    
    ptr=(char*)malloc(size*sizeof(char));

    char ch;
     printf("Enter the characters\n");

    while((ch=getchar())!='\n'){
        ptr[len++]=ch;

        if(len==size){
        size *=2;
        ptr=realloc(ptr,size*sizeof(char));
    }
}
    ptr[len] = '\0'; 

    printf("You entered: %s\n", ptr);

    free(ptr);
    
}


int main(){
    read();
    return 0;
}