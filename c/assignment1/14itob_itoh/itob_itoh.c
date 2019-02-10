#include<stdio.h>
int main()
{
	int n, s;
	char hexadecimal[100] = { 0 };
	scanf_s("%d", &n);
	itob(n, 0);
	itoh(n, hexadecimal);
	getch();
	return 0;
}
int itob(int a, int s)
{
	long r, base = 1;
	while (a > 0)
	{
		r = a % 2;
		s = s + (r * base);
		base = base * 10;
		a = a / 2;
	}
	printf("%ld", s);
}
int itoh(int q, char hexadecimal[])
{
	int i = 0, j = 0, remainder;
	while (q != 0)
	{
		remainder = q % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		q = q / 16;
	}

	for (i = j; i >= 0; i--)
		printf("%c", hexadecimal[i]);

}






