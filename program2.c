/*
The program is for demonstrating array operations using global variables 
in a menu driven format.
Author: @Febin Sunny 
Date:26-07-2025
*/
#include <stdio.h>

int a[5], pos = -1; // global variables

void insert(int e) { // function for inserting
    if (pos + 1 == 5) { // checking the array is full
        printf("\nThe array is full");
    } else { // if not full, element is inserted
        a[++pos] = e;
        printf("\nElement %d is inserted", e);
    }
}

void delete () { // function for deleting
    if (pos == -1) { // checking the array is empty
        printf("\nThe array is empty");
    } else { // if not empty, element in the current position is deleted
        int del = a[pos];
        printf("\nElement deleted is %d", del);
        pos--;
    }
}

void display() { // function for displaying array elements
    if (pos == -1) {
        printf("\nArray is empty");
        return;
    }
    printf("\nArray elements: ");
    for (int i = 0; i <= pos; i++) {
        printf("%d\t", a[i]);
    }
}

void search(int key) { // function for searching an element
    if (pos == -1) {
        printf("\nArray is empty");
        return;
    }
    for (int i = 0; i <= pos; i++) {
        if (a[i] == key) {
            printf("\nElement %d found at position %d", key, i);
            return;
        }
    }
    printf("\nElement %d not found", key);
}

void sort() { // function for sorting elements
    if (pos == -1) {
        printf("\nArray is empty");
        return;
    }
    for (int i = 0; i <= pos; i++) {
        for (int j = i + 1; j <= pos; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nArray sorted successfully");
}

int menu() { // menu function for choice
    int ch;
    printf("\n\n--- MENU ---");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Search");
    printf("\n5. Sort");
    printf("\n6. Quit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void process() { // function which calls operation based on your choice
    int choice, element;
    for (choice = menu(); choice != 6; choice = menu()) {
        switch (choice) {
        case 1: // insert
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            insert(element);
            break;
        case 2: // delete
            delete ();
            break;
        case 3: // display
            display();
            break;
        case 4: // search
            printf("\nEnter the element to search: ");
            scanf("%d", &element);
            search(element);
            break;
        case 5: // sort
            sort();
            break;
        case 6: // exit
            break;
        default:
            printf("\nInvalid choice");
        }
    }
}

int main() {
    process(); // calling the process function for the operation
    return 0;
}
