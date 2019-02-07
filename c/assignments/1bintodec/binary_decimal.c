#include<stdio.h>
#include<math.h>
int main()
{
	int b, d=0, r=0, i = 0;
	scanf_s("%d", &b);
	while (b > 0)
	{

		r = b % 10;
		d = d + (r*pow(2, i));
		i++;
		b = b / 10;
	}
	printf("%d", d);
	getch();
	return 0;
}