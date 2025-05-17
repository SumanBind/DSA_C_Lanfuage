#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int stack[MAX];
int Top = -1;


void push(int value) {
    if (Top == MAX - 1) {
        printf("Stack is Full\n");
        return;
    } else {
        Top++;
        stack[Top] = value;
    }
}


int pop() {
    if (Top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        int item = stack[Top];
        Top--;
        return item;
    }
}


void display() {
	int i;
    if (Top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements are:\n");
        for ( i = Top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int data, choice, p;
    char ch;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                p = pop();
                if (p != -1) {
                    printf("Popped item: %d\n", p);
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

