#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int stack[MAX];
int Top = -1;

void push(int value)
{
    if (Top == MAX - 1)
    {
        printf("Stack is Full\n");
        exit(0);
    }
    else
    {
        Top++;
        stack[Top] = value;
    }
}

int pop()
{
    if (Top == -1)
    {
        printf("Stack is empty\n");
        exit(0);
    }
    int item = stack[Top];
    Top--;
    return item;
}

int main()
{
	
    int n, i,n1;
    printf("Enter number of elements to push into the stack:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int d;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &d);
        push(d);
    }
    printf("Enter number of elements to pop into the stack:\n");
    scanf("%d", &n1);

	for(i=0;i<n1;i++)
	{
    int p = pop();
    printf("Pop item: %d\n", p);
	}	
    return 0;
}


