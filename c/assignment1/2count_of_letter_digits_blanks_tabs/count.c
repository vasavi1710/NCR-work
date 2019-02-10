#include<stdio.h>
int main()
{
	char data[80];
	int i, l = 0, d = 0, s = 0, t = 0, special_char = 0;
	scanf_s("%[^\n]s", data);
	for (i = 0; data[i] != '\0'; i++)
	{
		if ((data[i] >= 97 && data[i] <= 122) || (data[i] >= 65 && data[i] <= 90))
			l++;
		else if (data[i] >= 48 && data[i] <= 57)
			d++;
		else if (data[i] == ' ')
			s++;
		else if (data[i] == '\t')
			t++;
		else if ((data[i] >= 32 && data[i] <= 47) || (data[i] >= 123 && data[i] <= 127) || (data[i] >= 91 && data[i] <= 96) || (data[i] >= 58 && data[i] <= 64))
			special_char++;
	}
	printf("%d letters\n", l);
	printf("%d digits\n", d);
	printf("%d space\n", s);
	printf("%d tabs\n", t);
	printf("%d specialcharacters", special_char);
	return 0;
	getch();
}