/* Program to demonstrate queue using array
@Febin Sunny 
Roll No 27
1-10-2025
*/

#include <stdio.h>

int queue[10], front = -1, rear = -1;

// Function to add element to queue
void enqueue(int n) {
    if (front == -1 && rear == -1) {
        front++;
        rear++;
        queue[rear] = n;
        printf("Enqueued: %d\n", n);
    } else if (rear == 9) {
        printf("Queue is Full\n");
    } else {
        queue[++rear] = n;
        printf("Enqueued: %d\n", n);
    }
}

// Function to delete element from queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

// Function to display front element of queue
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front Element: %d\n", queue[front]);
    }
}

// Function to display all elements in queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        
    }
    else{
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
}

// Menu function
void menu() {
    int choice, element; 
    while (choice != 5) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Peek\n5.Exit\n");
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
                display();
                break;
            case 4:
                peek();
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
