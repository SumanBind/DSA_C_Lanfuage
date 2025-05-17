#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int Top=-1;
void push(int value)
{
    if(Top==MAX)
    {
        printf("Stack is Full\n");
        exit(0);
    }
    else
    {
        Top++;
        stack[Top]=value;
    }
}
int pop()
{
    if(pop==-1)
    {
        printf("stack is empty");
        exit(0);
    }
    int item=stack[Top];
    Top--;
    return item;
}
int main()
{
    int n,i;
    printf("Enter a number\n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
    	int d;
    	scanf("%d",d);
    	 push(d);
	}
    int p=pop();
    printf("pop item",p);
    return 0;
}
