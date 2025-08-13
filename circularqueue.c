#include<stdio.h>
int circular_queue[10];
int front=-1,rear=-1;

void enqueue(int e){
    if((rear+1)%10==front){
        printf("Queue is full\n");
    }
    else{
        front=0;
        rear=(rear+1)%10;
        circular_queue[rear]=e;


    }
}

void dequeue(){
    if(front==rear){
        front==rear==0;
    }
    else{
        front=(front+1)%10;
    }
}

void display() {
    if (front==-1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", circular_queue[i]);
        if (i == rear) break;
        i = (i + 1) % 10;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // Queue full here

    display();

dequeue();
dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}