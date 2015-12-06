
//Program to merge two linked lists which are in sorted order


#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
}*head=NULL,*head1=NULL,*head2=NULL,*newNode=NULL,*temp1=NULL,*temp2=NULL;
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
struct node* mergeList(struct node* head1,struct node* head2)
{
	if (head1->data < head2->data)
	{
		temp1 = head1;
		temp2 = head2;
	}
	else
	{
		temp1 = head2;
		temp2 = head1;
		head2 = temp2;
		head1 = temp1;
	}
	while (temp1->next != NULL && temp2->next != NULL)
	{
		if (temp2->data < temp1->next->data)
		{
			head2 = head2->next;
			temp2->next = temp1->next;
			temp1->next = temp2;
			temp1 = temp1->next;
			temp2 = head2;
		}
		else
		{
			temp1 = temp1->next;
		}
	}
	if (temp2->next != NULL)
		temp1->next = head2;
	return head1;
}
int main()
{
	head1=createList();
	head2 = createList();
	head1 = mergeList(head1, head2);
	printf("The resultant list is: \n");
	displayList(head1);
}
