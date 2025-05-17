#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int queue[MAX];
int front = -1, rear = -1;


void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) 
	front = 0; 
    rear++;
    queue[rear] = value;
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return -1;
    }
    int item = queue[front];
    front++;
    return item;
}

void display() {
	int i;
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int data, choice, p;
    char ch;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                p = dequeue();
                if (p != -1) {
                    printf("Dequeued item: %d\n", p);
                }
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue (Y/N)? ");
        while ((getchar()) != '\n'); 
        scanf("%c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}


