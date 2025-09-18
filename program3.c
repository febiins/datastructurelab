/*
The program is for demonstrating array operations using local variables 
in a menu driven format.
Author: @Febin Sunny 
Date:26-07-2025
*/

#include <stdio.h>

void insert(int a[5], int *pos, int e) { // function for inserting elements
    if (*pos + 1 == 5) { // checking the array is full
        printf("\nThe array is full");
    } else { // if not full element is inserted
        a[++(*pos)] = e;
        printf("\nElement %d is inserted", e);
    }
}

void delete(int a[5], int *pos) { // function for deleting elements
    if (*pos == -1) { // checking the array is empty
        printf("\nThe array is empty");
    } else { // if not empty element in the current position is deleted
        int del = a[*pos];
        printf("\nElement deleted is %d", del);
        (*pos)--;
    }
}

void display(int a[5], int *pos) { // function for displaying elements
    if (*pos == -1) {
        printf("\nArray is empty");
        return;
    }
    printf("\nArray elements: ");
    for (int i = 0; i <= *pos; i++) {
        printf("%d\t", a[i]);
    }
}

void search(int a[5], int *pos, int key) { // function for searching element
    if (*pos == -1) {
        printf("\nArray is empty");
        return;
    }
    for (int i = 0; i <= *pos; i++) {
        if (a[i] == key) {
            printf("\nElement %d found at position %d", key, i);
            return;
        }
    }
    printf("\nElement %d not found", key);
}

void sort(int a[5], int *pos) { // function for sorting elements
    if (*pos == -1) {
        printf("\nArray is empty");
        return;
    }
    for (int i = 0; i <= *pos; i++) {
        for (int j = i + 1; j <= *pos; j++) {
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

void process(int a[5], int *pos) { // function which calls operations
    int choice, element;
    for (choice = menu(); choice != 6; choice = menu()) {
        switch (choice) {
        case 1: // insert
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            insert(a, pos, element);
            break;
        case 2: // delete
            delete(a, pos);
            break;
        case 3: // display
            display(a, pos);
            break;
        case 4: // search
            printf("\nEnter the element to search: ");
            scanf("%d", &element);
            search(a, pos, element);
            break;
        case 5: // sort
            sort(a, pos);
            break;
        case 6: // exit
            break;
        default:
            printf("\nInvalid choice");
        }
    }
}

int main() {
    int a[5], pos = -1; // local variables
    process(a, &pos);   // passing the array and address of pos
    return 0;
}
