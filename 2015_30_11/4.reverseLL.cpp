
//Program to reverse a given linked list

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
}*head = NULL, *temp1 = NULL, *temp2 = NULL, *newNode = NULL;


struct node* createList()
{
	head = NULL;
	int d;
	printf("\n");
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

struct node * reverse(struct node * head, struct node * tail)
{

	if (head == NULL)
		return tail;
	else
	{
		struct node * next = head->next;
		head->next = tail;
		return reverse(next, head);
	}
}

int main()
{
	head = createList();
	printf("The given list is:\n");
	displayList(head);
	head = reverse(head, NULL);
	printf("\nThe resultant list is: \n");
	displayList(head);
	return 1;
}

