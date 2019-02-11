#include"header.h"
#include<stdio.h>
void tabs()
{
	FILE *fp;
	fopen_s(&fp, "a.txt", "r");
 //fopen_s(&f,"a.txt", "a+");
	char ch;
	char r = 'r';
	FILE *WP;
	fopen_s(&WP, "c.txt", "w+");
	while (!feof(fp))
	{
		ch = fgetc(fp);
	
		if (ch == '\t')
		{
			ch=fgetc(fp);
				
		}
		fputc(ch, WP);
	}
}