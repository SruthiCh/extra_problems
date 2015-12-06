
//Program to add a node to a circular linked list

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
}*head = NULL, *newNode = NULL, *temp1 = NULL;

struct node* createList()
{
	int d;
	while (1)
	{
		printf("Enter data('-1' to exit): ");
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
				head->next = head;
			}
			else
			{
				temp1->next = newNode;
				newNode->next = head;
				temp1 = newNode;
			}
		}
	}
	return head;
}
void displayList(struct node* head)
{
	temp1 = head;
	do
	{
		printf("( %d ) -> ", temp1->data);
		temp1 = temp1->next;
	} while (temp1 != head);
	printf("( %d )  ", temp1->data);
}
struct node* addNode1(struct node*head, int data)
{
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = head->data;
	newNode->next = head->next;
	head->next = newNode;
	head->data = data;
	head = newNode;
	return head;
}
struct node* addNode2(struct node*head, int data)
{
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	temp1 = head;
	while (temp1->next != head)
		temp1 = temp1->next;
	temp1->next = newNode;
	newNode->next = head;
	return head;
}
int main()
{
	int data;
	head = createList();
	printf("Enter node value to add: ");
	scanf("%d", &data);
	head = addNode1(head, data);
	printf("\nThe resultant circular linked list is: \n");
	displayList(head);
	return 1;
}

