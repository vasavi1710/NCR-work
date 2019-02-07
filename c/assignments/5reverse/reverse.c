#include<stdio.h>
int main()
{
	int n,t,r=0;
	scanf_s("%d", &n);
	while (n > 0)
	{
		t = n % 10;
		r = (r * 10) + t;
		n = n / 10;
	}
	printf("%d", r);
	getch();
	return 0;
}