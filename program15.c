/*
Program to input n strings and sort them in ascending order
Author: @Febin Sunny
Date: 27-07-2025
*/

#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 100  
char strings[MAX_STRINGS][MAX_LENGTH]; // Array to hold the strings


void sort_strings(){
    int n;
    printf("Enter number of strings\n");
    scanf("%d", &n);

     // Input strings
    printf("Enter string \n");
    for(int i=0; i<n; i++){
        
        scanf("%s", strings[i]);
    }

    char temp[MAX_LENGTH];
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(strings[i], strings[j]) > 0){ // Compare strings
                strcpy(temp, strings[i]); // Swap strings
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
     // Print sorted strings
    printf("\nSorted strings:\n");
    for(int i=0; i<n; i++){
        printf("%s\n", strings[i]);
    }
}
int main(){
    sort_strings(); // Sort the strings
    return 0;
}