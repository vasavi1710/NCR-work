#include<stdio.h>
int main()
{
	FILE *fp;
	char ch;
	fopen_s(&fp, "a.txt", "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	getchar();
	return 0;
}