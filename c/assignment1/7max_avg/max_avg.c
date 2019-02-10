#include<stdio.h>
#include<string.h>
int main()
{
	int a[100], i, j, count = 0, sum = 0, temp, n;
	for (i = 0;; i++)
	{
		scanf_s("%d", &j);
		if (j>0)
		{
			a[i] = j;
		}
		else
			break;
	}
	n = i;
	//printf("%d ", n);
	for (i = 0; i<n; i++)
	{
		if (a[i] > 0)
			count++;
		sum = sum + a[i];
	}
	sum = sum / n;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j <n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("%d is number of positive numbers \n %d is minimum number \n %d maximum\n %d is average", count, a[0], a[n - 1], sum);
	getch();
}