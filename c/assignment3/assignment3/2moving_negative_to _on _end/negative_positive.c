#include<stdio.h>
int main()
{
	int a[10],b[10],c[10];
	int n;
	printf("enter the size of the array");
	scanf_s("%d", &n);
	int i,j=0,k=0;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] >= 0)
		{
			b[j] = a[i];
			j++;
		}
		else
		{
			c[k] = a[i];
			k++;
		}
	}
	for (i = 0; i < j; i++)
	{
		c[k++] = b[i];
	}
	
	for (i = 0; i < n; i++)
		printf("%d ", c[i]);
	getch();
	return 0;
}