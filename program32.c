/*Program to demonstrate priority queue
@Febin Sunny 
Roll No 27
1-10-2025
*/

#include <stdio.h>
#define MAX 100

int priorityQueue[MAX];  // decalared as global 
int size = 0;            // Current size of priority queue

// Function to swap two elements in the priority queue
void swap(int i, int j) {
    int temp = priorityQueue[i];
    priorityQueue[i] = priorityQueue[j];
    priorityQueue[j] = temp;
}

// Heapify function to maintain max-heap property from index i downwards
void heapify(int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && priorityQueue[left] > priorityQueue[largest])
        largest = left;
    if (right < n && priorityQueue[right] > priorityQueue[largest])
        largest = right;

    if (largest != i) {
        swap(i, largest);
        heapify(largest, n);
    }
}

// Insert an element into the priority queue
void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue is Full\n");
        return;
    }

    priorityQueue[size] = value;
    int i = size;
    size++;

    // Percolate up to maintain max-heap property
    while (i != 0 && priorityQueue[(i - 1) / 2] < priorityQueue[i]) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }

    printf("Inserted: %d\n", value);
}

// Delete the element with the highest priority (root of max-heap)
void deleteMax() {
    if (size <= 0) {
        printf("Priority Queue is Empty\n");
        return;
    }

    int max = priorityQueue[0];
    priorityQueue[0] = priorityQueue[size - 1];
    size--;
    heapify(0, size);

    printf("Deleted: %d\n", max);
}

// function for peek
void peek() {
    if (size <= 0) {
        printf("Priority Queue is Empty\n");
    } else {
        printf("Highest Priority Element: %d\n", priorityQueue[0]);
    }
}

// function for display
void display() {
    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue Elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", priorityQueue[i]);
    printf("\n");
}

// Menu-driven function
void menu() {
    int choice, value;

    do {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n2. Delete Max\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteMax();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 5);
}


int main() {
    menu();  
    return 0;
}
