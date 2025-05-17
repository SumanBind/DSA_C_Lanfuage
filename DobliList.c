#include <stdio.h>
#include <stdlib.h>

struct dnode 
{
    int info;
    struct dnode *next,*prev;
};

//struct dnode* head = NULL;
void insertbig(int value)
{
struct dnode* head = NULL,*temp;
	struct dnode* new1 = (struct dnode*)malloc(sizeof(struct dnode));
	if(NULL==new1)
	{
		printf("Over flow");
		exit(0);
	}
	if(head==NULL)
	{
		new1->prev=NULL;
		new1->next=NULL;
		new1->info=value;
		head=new1;
	}
	else
	{
		new1->prev=NULL;
		new1->next=head;
		new1->info=value;
		temp=head;
		temp->prev=new1;
		head=new1;
	}

}
struct dnode* tail = NULL;
void insertTailPossition(int value)
{
	struct dnode* new1,*temp;
	new1=(struct dnode*)malloc(sizeof(struct dnode));
	if(NULL==new1)
	{
		printf("Over flow");
		exit(0);
	}
	if(tail==NULL)
	{
		new1->prev=NULL;
		new1->next=NULL;
		new1->info=value;
		tail=new1;
	}
	else
	{
		new1->prev=NULL;
		new1->next=tail;
		new1->info=value;
		temp=tail;
		temp->prev=new1;
		tail=new1;
	}
	
}

void display() 
{
    struct dnode* temp=head ;
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
		printf("To insert the node at begining-1\n");
		printf("To insert the node at end-2\n");
		printf("To display the linked list-3\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value\n");
				scanf("%d",&data);
				insertbig(data);
				break;
			case 2:
				printf("Enter the value\n");
				scanf("%d",&data);
				insertTailPossition(data);
				break;
			case 3:
				printf("Linked list\n");
				display();
				break;
			default:
				printf("Involed choice\n");
		}
		printf("Do you want to repeat\n");
		fflush(stdin);
		scanf("%c",&ch);	
	}
	while(ch=='y'||ch=='Y');
	
    
    return 0;
}

