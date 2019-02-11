#include"header.h"
#include<stdio.h>
void comment()
{
	FILE *fp;
	fopen_s(&fp, "a.txt", "r");
	char ch,space=' ';
	FILE *WP;
	//RP = fopen("a.txt", "r");
	 fopen_s(&WP,"b.txt", "w+");
	 //fputc('s', WP);
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '/') 
		{
			
			ch = fgetc(fp);
			if (ch == '/')
			{
				while (ch != '\n')
					ch=fgetc(fp);
			}
			else if(ch=='*')
			{
				while (ch != '*')
				{
					ch = fgetc(fp);
				}
				ch = fgetc(fp);
			}
		
		}
		fputc(ch, WP);
	}
	fputc('\0',WP);
}