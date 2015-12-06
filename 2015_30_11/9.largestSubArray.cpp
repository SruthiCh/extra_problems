
//Program to return largest sub array with maximum sum

#include<stdio.h>
#include<malloc.h>

struct outArray
{
    int subArray[15];
    int length;
    int sum;
}result;

struct outArray getLargestSubArray(int *inArray, int len)
{
	int presentMaxSum = -2147483648,maxSum,first=0,last=0,i=0,j=0,presentSum=0;
	for (i = 0; i < len; i++)
	{
		presentSum += inArray[i];
		if (presentSum > presentMaxSum)
		{
		    first = j;
			last = i;
			presentMaxSum = presentSum;
        }
		if (presentSum < 0)
		{
			presentSum = 0;
			j = i + 1;
		}
	}
	result.sum = presentMaxSum;
	for (i = first,j=0; i <= last; i++,j++)
		result.subArray[j] = inArray[i];
    result.length=j;
	return result;
}
int main()
{
    int* inArray;
    int len,i;
    printf("Enter length of input array: ");
    scanf("%d",&len);
    inArray=(int*)malloc(len*sizeof(int));
    printf("Enter %d values:\n",len);
    for(i=0;i<len;i++)
        scanf("%d",&inArray[i]);
    result=getLargestSubArray(inArray,len);
    printf("The largest possible sub array with max sum as %d is\n",result.sum);
    for(i=0;i<result.length;i++)
        printf("%d  ",result.subArray[i]);
    return 1;
}
