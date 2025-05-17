
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) 
	{
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) 
	{
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int value, int position) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }
	int i;
    struct Node* temp = head;
    for (i= 1; i < position - 1 && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
    	
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteAtBeginning() 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteAtEnd() 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) 
    {
        free(head);
        head = NULL;
        printf("Node deleted from end.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from end.\n");
}

// Delete from a given position
void deleteAtPosition(int position) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) 
    {
        deleteAtBeginning();
        return;
    }
	int i;
    struct Node* temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node deleted from position %d.\n", position);
}

void display() 
{
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d-> \n ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() 
{
	int data,choice;
	char ch;
	do
	{
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert at any position\n");
		printf("4. Delete from beginning\n");
		printf("5. Delete from end\n");
		printf("6. Delete from any position\n");
		printf("7. Display the linked list\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value\n");
				scanf("%d",&data);
				insertAtBeginning(data);
				break;
			case 2:
				printf("Enter the value\n");
				scanf("%d",&data);
				insertAtEnd(data);
				break;
			
			case 3:
    			printf("Enter the value: ");
   				 scanf("%d", &data);
   				 int pos;
   				 printf("Enter the position: ");
    			scanf("%d", &pos);
    			insertAtPosition(data, pos);
   				 break;
   			case 4:
    			deleteAtBeginning();
    			break;
			case 5:
    			deleteAtEnd();
    			break;
			case 6:
    			printf("Enter the position to delete: ");
    			int delPos;
    			scanf("%d", &delPos);
    			deleteAtPosition(delPos);
    			break;
   			 case 7:
				printf("Linked list\n");
				display();
				break;
			default:
				printf("Involed choice\n");
		}
		printf("Do you want to repeat then enter (y/Y) .\n");
		fflush(stdin);
		scanf("%c",&ch);	
	}
	while(ch=='y'||ch=='Y');
	
    
    return 0;
}

