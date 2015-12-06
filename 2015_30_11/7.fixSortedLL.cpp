
//Program to fix a given sorted array in which two values are interchanged


#include<stdio.h>
#include<malloc.h>

struct  node
{
	int data;
	struct node* next;
}*head=NULL,*temp1=NULL,*index1=NULL,*index2=NULL,*newNode=NULL;

struct node* createList()
{
	head = NULL;
	int d;
	while (1)
	{
		printf("Enter data: ");
		scanf("%d", &d);
		if (d == -1) break;
		else
		{
			newNode = (struct node*)malloc(sizeof(struct node));
			newNode->data = d;
			newNode->next = NULL;
			if (head == NULL)
			{
				head = newNode;
				temp1 = newNode;
			}
			else
			{
				temp1->next = newNode;
				temp1 = newNode;
			}
		}
	}
	return head;
}
void displayList(struct node* head)
{
	temp1 = head;
	while (temp1)
	{
		printf("( %d ) -> ", temp1->data);
		temp1 = temp1->next;
	}
}
struct node* fixArray(struct node* head)
{
	int temp;
	temp1 = head;
	while (temp1->next != NULL)
	{
		if (temp1->data > temp1->next->data)
		{
			index1 = temp1;
			break;
		}
		temp1 = temp1->next;
	}
	temp1 = temp1->next;
	index2 = temp1;
	while (temp1->next != NULL)
	{
		if (temp1->data > temp1->next->data)
		{
			index2 = temp1->next;
			break;
		}
		temp1 = temp1->next;
	}
	temp = index1->data;
	index1->data = index2->data;
	index2->data = temp;
	return head;
}

int main()
{
	head = createList();
	printf("The given list is:\n");
	displayList(head);
	head = fixArray(head);
	printf("\nThe fixed array is:\n");
	displayList(head);
	return 1;
}
