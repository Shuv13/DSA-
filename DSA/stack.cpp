#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }

    stack->data[++stack->top] = element;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }

    return stack->data[stack->top--];
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice, element;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                element = pop(&stack);
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}
