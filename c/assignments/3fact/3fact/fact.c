#include<stdio.h>
int main()
{
	int n, f=1, i;
	scanf_s("%d",&n);
	for (i = 1; i <= n; i++)
	{
		f = f*i;
	}
	printf("\n%d",f);
	getch();
	return 0;
}