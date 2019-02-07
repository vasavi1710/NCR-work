#include<stdio.h>
int main()
{
	int f, l, i, j,c;
	scanf_s("%d %d", &f, &l);
	for (i = f; i <= l; i++)
	{
		c = 0;
		for (j = 2; j <= i; j++)
		{
			if (i%j == 0)
				c++;
		}
		if(c==1)
			printf(" %d",i);
	}
	getch();
	return 0;
}