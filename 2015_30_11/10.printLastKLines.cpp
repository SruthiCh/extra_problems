
//Program to print last k lines in a file

#include<stdio.h>
#include<malloc.h>

int main()
{
	FILE *fp, *temp;
	char ch;
	int k, count = 0, i, flag = 0;
	char* string = (char*)malloc(sizeof(char) * 500);
	fp = fopen("data.txt", "w");
	printf("\nEnter data to be stored in the file:\n");
	while ((ch = getchar()) != EOF)
		putc(ch, fp);
	fclose(fp);
	fp = fopen("data.txt", "r");
	printf("Enter no.of lines to be printed from last: ");
	scanf("%d", &k);
	if (k <= 0) return '\0';
	while ((ch = fgetc(fp)) != EOF)
		if (ch == '\n') count++;
	rewind(fp);
	if (count <= k)
	{
		while ((ch = fgetc(fp)) != EOF)
		{
			string[i] = ch;
			i++;
		}
		string[i] = '\0';
	}
	else
	{
		count -= k;
		while (count > 0)
		{
			ch = fgetc(fp);
			if (ch == '\n')
				count--;
		}
		while ((ch = fgetc(fp)) != EOF)
		{
			string[i] = ch;
			i++;
		}
		string[i] = '\0';
	}
	for (i = 0; string[i] != '\0'; i++)
		printf("%c", string[i]);
}

