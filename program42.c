/*Program to demonstrate functions for reading n books and displaying the same using pointers (using structure)
@Febin Sunny 
Roll No 27
3-10-2025
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct book{
    char authorname[100];
    char bookname[100];
}book;

book *ptr;
int n;

void read(){
    
    printf("\nEnter the number of books\n");
    scanf("%d",&n);
    getchar();

    ptr=(book*)malloc(n*sizeof(book));

    for(int i=0;i<n;i++){
        printf("Enter author name:");
        gets(ptr[i].authorname);
        printf("Enter book name:");
        gets(ptr[i].bookname);
    }

    
}

void display(){
    for (int i = 0; i < n; i++) {
        printf("\nBook %d:", i + 1);
        printf("\nAuthor: %s", ptr[i].authorname);
        printf("\nBook: %s\n", ptr[i].bookname);
    }
    free(ptr);
}


int main(){
    read();
    display();
    return 0;
}

