
/*Given a linked list of combination of ascending and descending
  provided min of descending is greater than max of ascending
  sort the linked list*/

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
}*head = NULL, *temp=NULL,*temp1 = NULL, *temp2 = NULL, *newNode = NULL;


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
struct node* sortList(struct node* head)
{
	struct node* nextNode;
	while (1)
	{
		nextNode = NULL;
	temp1 = head;
	while (temp1->data < temp1->next->data&& temp1->next!=NULL)
	{
		temp = temp1;
		temp1 = temp1->next;
	}
	temp2 = temp1;
	while (temp2->data > temp2->next->data && temp2->next != NULL)
		temp2 = temp2->next;
	nextNode = temp2->next;
	temp2->next = NULL;
	newNode = reverse(temp1, NULL);
	temp->next = newNode;
	while (temp->next != NULL) temp = temp->next;
	if (nextNode == NULL) return head;
	else
	temp->next = nextNode;
}

}
int main()
{
	head = createList();
	printf("The given list is:\n");
	displayList(head);
	head = sortList(head);
	printf("\nThe resultant list is: \n");
	displayList(head);
	return 1;
}


