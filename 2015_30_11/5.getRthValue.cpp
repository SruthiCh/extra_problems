
/* Given three numbers n1,n2 and r
  Merge their table lists
  and return the rth value in merged list*/


#include<stdio.h>

int getValue(int n1, int n2, int r)
{
	int value = 0, i,temp1=n1,temp2=n2;
	for (i = 0; i <= r; i++)
	{
		value = (temp1 < temp2) ? (temp1) : (temp2);
		temp1 = (value < temp1) ? (temp1) : (temp1 + n1);
		temp2 = (value < temp2) ? (temp2) : (temp2 + n2);
	}
	return value;
}

int main()
{
	int value,n1, n2, r;
    printf("What are n1, n2 and r values ? ");
	scanf("%d%d%d", &n1, &n2, &r);
	value = getValue(n1, n2, r);
    printf("\nThe %dth value in the merged table is: \n%d",r,value);
	return 1;
}

