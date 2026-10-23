
#include <stdio.h>
#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
        printf("%d inserted into queue\n", x);
    }
    else if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    }
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
        printf("%d inserted into queue\n", x);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("%d removed from queue\n", queue[front]);

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    int i;

    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: ");

        i = front;
        while (1) {
            printf("%d ", queue[i]);

            if (i == rear) {
                break;
            }

            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

int main() {
    int x, choice = 0;

    while (choice != 4) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Enter the correct choice\n");
        }
    }

    return 0;
}
