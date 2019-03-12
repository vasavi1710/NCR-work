#include<stdio.h>
void main()
{
	int x, p, n, result;
	int invert(int, int, int);

	printf("enter any integer to invert (x) : \n");
	scanf_s("%d", &x);
	printf("enter the start position to invert (p) :\n");
	scanf_s("%d", &p);
	printf("enter the length to invert (n) :\n");
	scanf_s("%d", &n);
	printf("converted binary value of %d is \t", x);
	result = invert(x, p, n);
	printf("\ninverted integer in decimal form is \t%d", result);
	getch();
}

int invert(int x, int p, int n)
{
	int i, y, limit, len, bin[15];
	len = 0;
	while (x>0)
	{
		bin[len] = x % 2;
		x = x / 2;
		len++;
	};

	for (i = len - 1; i>-1; i--)
	{
		printf("%d ", bin[i]);
	}
	printf("\n");
	limit = p + n;
	if (limit < len)
	{
		for (i = p - 1; i<p + n - 1; i++)
		{
			if (bin[i] == 0)
				bin[i] = 1;
			else
				bin[i] = 0;
		}
	}
	else
	{
		printf("you have entered large value for p and n");
	}

	printf("inverted integer in binary form is \t");
	for (i = len - 1; i>-1; i--)
	{
		printf("%d ", bin[i]);
	}
	y = 0;
	for (i = len - 1; i >= 0; i--)
	{
		y = y * 2 + bin[i];
	}
	return y;
}