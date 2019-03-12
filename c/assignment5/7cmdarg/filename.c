#include<stdio.h>
int main(int argc, char *argv[])
{
	if (argc<2)
	{
		printf("ERROR:Arguments are not sufficient\n");
		exit(0);
	}
	FILE *fp;
	char ch[20],a;
	scanf_s("%s", ch);
	fopen_s(&fp, argv[1], "w+");
	int i;
	for (i = 0; i < strlen(ch); i++)
	{
		a = ch[i];
		fputc(a, fp);
	}
	rewind(fp);
	do {
		a = fgetc(fp);
		//printf("%c", ch);
		putchar(a);
	} while (a != EOF);

	getch();
	return 0;
}