#include"header.h"
#include<stdio.h>
void count()
{
	char ch;
	FILE *fp;
	fopen_s(&fp, "a.txt", "r");
	int letter = 0, digit = 0, space = 0, special_char = 0,t=0;
	
	while (!feof(fp))
	{
		ch = fgetc(fp);
	
		if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
			letter++;
		else if (ch >= 48 && ch <= 57)
			digit++;
		else if (ch == ' ')
			space++;
		else if (ch == '\t')
			t++;
		else if ((ch >= 32 && ch <= 47) || (ch >= 123 && ch <= 127) || (ch >= 91 && ch <= 96) || (ch >= 58 && ch <= 64))
			special_char++;
	}
	printf("the letters are %d and the digits are %d and the spaces are %d and the special characters are %d",
		letter, digit, space, special_char);
}