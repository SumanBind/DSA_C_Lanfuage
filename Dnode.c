
#include <stdio.h>
#include <stdlib.h>

struct dnode 
{
    int info;
    struct dnode *next, *prev;
};

struct dnode* head = NULL;
struct dnode* tail = NULL;

void insertbig(int value) 
{
    struct dnode* new1 = (struct dnode*)malloc(sizeof(struct dnode));
    if (new1 == NULL) 
	{
        printf("Overflow\n");
        exit(0);
    }

    new1->info = value;
    new1->prev = NULL;
    new1->next = head;

    if (head != NULL) 
	{
        head->prev = new1;
    }
	 else 
	 {
        
        tail = new1;
    }
    head = new1;
}

void insertTailPossition(int value) 
{
    struct dnode* new1 = (struct dnode*)malloc(sizeof(struct dnode));
    if (new1 == NULL) 
	{
        printf("Overflow\n");
        exit(0);
    }

    new1->info = value;
    new1->next = NULL;
    new1->prev = tail;

    if (tail != NULL) 
	{
        tail->next = new1;
    } else 
	{
        
        head = new1;
    }
    tail = new1;
}


void insertAtPosition(int value, int position) 
{
    struct dnode* new1 = (struct dnode*)malloc(sizeof(struct dnode));
    if (new1 == NULL) 
    {
        printf("Overflow\n");
        return;
    }

    new1->info = value;

    
    if (position == 1) 
    {
        new1->prev = NULL;
        new1->next = head;
        if (head != NULL)
            head->prev = new1;
        else
            tail = new1; 
        head = new1;
        return;
    }
	int i;
    struct dnode* temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position out of range\n");
        free(new1);
        return;
    }

    new1->next = temp->next;
    new1->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new1;
    else
        tail = new1; 

    temp->next = new1;
}

// Delete from beginning
void deleteAtBeginning() 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct dnode* temp = head;

    if (head == tail) 
    {
        head = tail = NULL;
    } 
    else 
    {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteAtEnd() 
{
    if (tail == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct dnode* temp = tail;

    if (head == tail) 
    {
        head = tail = NULL;
    } 
    else 
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
    printf("Node deleted from end.\n");
}

// Delete from specific position
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

    struct dnode* temp = head;
    int i;
    for (i = 1; i < position && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }

    if (temp == tail) 
    {
        deleteAtEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    printf("Node deleted from position %d.\n", position);
}



void display() 
{
    struct dnode* temp = head;
    printf("Linked List: ");
    while (temp != NULL) 
	{
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    int data, choice;
    char ch;
    do 
	{
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from beginning\n");
		printf("5. Delete from end\n");
		printf("6. Delete from specific position\n");
        printf("7. Display list\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertbig(data);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertTailPossition(data);
                break;
            case 3:
    			printf("Enter value: ");
  			  	scanf("%d", &data);
    			int pos;
    			printf("Enter position: ");
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
    			printf("Enter position to delete: ");
    			int delPos;
    			scanf("%d", &delPos);
    			deleteAtPosition(delPos);
    			break;
            case 7:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue (y/n)? ");
        while ((getchar()) != '\n'); 
        scanf("%c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

