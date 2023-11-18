#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if (rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue element.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d enqueued successfully.\n", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue element.\n");
    } else {
        printf("%d dequeued successfully.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        int i;
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
