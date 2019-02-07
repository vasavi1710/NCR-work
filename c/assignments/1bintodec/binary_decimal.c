#include<stdio.h>
#include<math.h>
int dec_binary(int c);
int bin_decimal(int b);
int main()
{
	int bin, dec;
	scanf_s("%d %d", &bin, &dec);
	int k=bin_decimal(bin);
	int l = dec_binary(dec);
	printf("%d %d", k, l);

	getch();
	return 0;
}
int bin_decimal(int b)
{
	int r = 0, d = 0, i = 0;
	while (b > 0)
	{

		r = b % 10;
		d = d + (r*pow(2, i));
		i++;
		b = b / 10;
	}
	return d;
}
int dec_binary(int c)
{
	int b=0,i=1;
	while (c > 0)
	{
		int k;
		while (c > 0)
		{
			k = c % 2;
			b = (b ) + (k*i);
			i = i * 10;
			c = c / 2;
		}
	}
	return b;

}