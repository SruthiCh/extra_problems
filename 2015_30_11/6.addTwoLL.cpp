
//Program to add two given linked lists

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
}*head = NULL, *head1 = NULL, *head2 = NULL, *temp1 = NULL, *temp2 = NULL, *newNode = NULL;


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
struct node* addLists(struct node* head1, struct node* head2)
{
	temp1 = head1;
	temp2 = head2;
	while (temp1->next != NULL&&temp2->next != NULL)
	{
		temp1->data += temp2->data;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp1->data += temp2->data;
	if (temp1->next == NULL)
		temp1->next = temp2->next;
	return head1;
}
int main()
{
	head1 = createList();
	head2 = createList();
	printf("\nFirst list is:\n");
	displayList(head1);
	printf("\nSecond list is:\n");
	displayList(head2);
	head = addLists(head1, head2);
	printf("\nThe sum results as: \n");
	displayList(head);
	return 1;
}





