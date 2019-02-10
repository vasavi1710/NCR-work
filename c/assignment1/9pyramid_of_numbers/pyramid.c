#include <stdio.h>
#include<conio.h>
int main()
{
	int n,i,j;
	printf("Enter number of rows: ");
	scanf_s("%d", &n);

	for (i = 1; i<=n; i++)
	{
		for (j = 0; j<n - i; j++)
			printf("  ");
		for (j = i; j > 0; j--)
			printf(" %d", j);
		for ( j=j+2; j<=i; j++)
			printf(" %d", j);
		printf("\n");
	}

	_getch();
	return 0;
}