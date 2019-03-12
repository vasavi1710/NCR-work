#include<stdlib.h>
#include<stdio.h>
#include <string.h> 
int main()
{
		FILE *fp;
		fopen_s(&fp, "b.txt", "w");
		char buffer[40];
		char *p;
		char ch;
		printf("Please enter a line of text, max %d characters\n", sizeof(buffer));
		if (fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			if ((p = strchr(buffer, '\n')) != NULL)
			{
				*p = '\0';
				
			}
		}
		//printf("\n%s", buffer);
		int i = 0;
		for (i = 0; buffer[i] != '\0'; i++)
		{
			if ('a' <= buffer[i] && buffer[i] <= 'z')
			{
				ch = buffer[i] - 32;
			}
			else if ('A'<= buffer[i] && buffer[i] <='Z')
			{
				ch = buffer[i]+32 ;
			}
			else
			{
				ch = buffer[i];
			}
			fputc(ch, fp);

		}
		int len = ftell(fp);
		printf("\n size of file is %d", len);
		fseek(fp, 7, SEEK_SET);
		fputs(" hello", fp);

		fseek(fp, 0, SEEK_END);
		ch = EOF;
		fputc(ch, fp);
		fseek(fp, 0, SEEK_SET);
		do {
			ch = fgetc(fp);
			//printf("%c", ch);
			putchar(ch);
			} while (ch != EOF);
		getchar();
	return 0;
	}


