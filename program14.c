/* program demostrating string reversal in same array.
   Author: @Febin Sunny
   Date: 27-07-2025
*/
#include <stdio.h>
// Global character array to store the string
char a[10];
int i,j;

// Function to reverse and print the input string
void str_rev(){
    int count=0,n;
    printf("\nEnter string\n");
    scanf("%s",a); // Read string from user

    // Count the length of the string
    for(i=0;a[i]!='\0';i++){
        count++;
    }
    
    // Print the string in reverse order
    for(i=0 ,j=count-1;i<j;i++ ,j--){
        char temp = a[i];
        a[i]=a[j];
        a[j]=temp;

    }
    printf("\n %s\n", a);
}

// Main function
int main(){
    str_rev(); // Call the string reverse function
    return 0;
}