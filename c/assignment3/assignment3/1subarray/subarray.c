#include<stdio.h>
int main()
{
	int i,n,s=0,m1=0,n1=0;
	printf("enter the size of the array");
	scanf_s("%d", &n);
	int a[100];
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("enterr the indexes that yu want the sum in between");
	scanf_s("%d %d", &m1, &n1);
	if (m1 <= n &&  n1 <= n && m1 <= n1)
	{
		for (i = m1; i <= n1; i++)
		{
			s += a[i];
		}
		printf("\n%d", s);
	}
	else
		printf("no subarray found");
	//printf("\n%d", s);
	getch();
	return 0;
}
