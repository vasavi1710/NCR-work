#include<stdio.h>
int main()
{
	int n,k,c=0;
	scanf_s("%d", &n);
	while(n > 0)
	{
		k = n % 2;
		if (k == 1)
			c++;
		n = n / 2;

	}
	printf("%d", c);
	getch();
	return 0;
}