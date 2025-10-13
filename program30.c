/*Program to demonstrate circular queue using array
@Febin Sunny 
Roll No 27
1-10-2025
*/

#include <stdio.h>

// Define a circular queue of size 10
int circular_queue[10];
int front = -1, rear = -1;

// Function to add element to the circular queue
void enqueue(int e) {
    
    if ((rear + 1) % 10 == front) {
        printf("Queue is full\n");
    } 
    else {
        // If queue is empty, initialize front
        if (front == -1)
            front = 0;
        // Move rear to next position in circular manner
        rear = (rear + 1) % 10;
        circular_queue[rear] = e;
        printf("Enqueued: %d\n", e);
    }
}

// Function to delete element from circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
      
    }
     printf("Deleted element: %d\n", circular_queue[front]);
      if (front == rear) {
        front = rear = -1; 
    } 
    else {
        front = (front + 1) % 10; 
    }
}

// Function to display all elements in the circular queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", circular_queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % 10; 
    }
    printf("\n");
}

// Function to display the front element without removing
void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
    } 
    else {
        printf("Front Element: %d\n", circular_queue[front]);
    }
}

// Menu-driven function
void menu() {
    int choice, element;
    choice = 0; // Initialize choice
    while (choice != 5) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
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
    }
}

int main() {
    menu();
    return 0;
}
