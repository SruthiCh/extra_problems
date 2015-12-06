

//Program to find median of a given linked list


#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
}*head=NULL,*temp1=NULL,*temp2=NULL,*newNode=NULL;
int getMedian1(struct node* head)
{
	int count = 0, i,temp;
	temp1 = head;
	while (temp1 != NULL)
	{
		count++;
		temp1 = temp1->next;
	}
	temp1 = head;
	if (count % 2 == 1) temp = (count + 1)/2;
	else temp = count/2;
	for (i=1;i<temp;i++)
		temp1 = temp1->next;
	if (count % 2 == 0)
		return ((temp1->data) + (temp1->next->data)) / 2;
	else
		return temp1->data;

}
int getMedian2(struct node* head)
{
	temp1 = head;
	temp2 = head;
	while (temp1->next != NULL && temp1->next->next != NULL)
	{
		temp1 = temp1->next->next;
		temp2 = temp2->next;
	}
	if (temp1->next == NULL)
		return temp2->data;
	else
		return ((temp2->data) + (temp2->next->data)) / 2;
}
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
int main()
{
	int median;
	head = createList();
	median = getMedian2(head);
	printf("\nMedian is: %d", median);
	return 1;
}

