#include<stdio.h>
#include<math.h>
#include<string.h>
#include<math.h>
void hexbin(char *);
int bin_decimal_hex(int bin);
void dec_binary(int);

char h[10];
int main()
{
	int bin;
	char hex[10];
	scanf_s("%d %s", &bin, hex);
	int dec = bin_decimal_hex(bin);
	hexbin(hex);
	printf("%x %s", dec, h);
	//	getch();
	return 0;
}

int bin_decimal_hex(int b)
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

void hexbin(char a[])
{
	int i, k = 0;
	for (i = 0; i<strlen(a); i++)
	{

		switch (a[i])
		{
		case 'a':k = (int)10; break;
		case 'b':k = (int)11; break;

		case 'c':k = (int)12; break;
		case 'd':k = (int)13; break;
		case 'e':k = (int)14; break;

		case 'f':k = (int)15; break;
		default:k = (int)k;
		}
		dec_binary(k);

	}

}
int n = 0;

void dec_binary(int c)
{
	int b = 0, i = 1;
	while (c > 0)
	{
		int k;
		while (c > 0)
		{
			k = c % 2;
			b = (b)+(k*i);
			i = i * 10;
			c = c / 2;
			h[n] = k + 48;
			n++;
		}
	}
	h[n] = '\0';
	_strrev(h);
	//return b;

}