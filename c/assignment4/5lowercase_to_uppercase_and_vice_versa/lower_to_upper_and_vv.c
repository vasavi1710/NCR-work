#include<stdio.h>
#include<string.h>
int main()
{
	char ch[100];
	printf("enter a string");
	scanf_s("%s", ch);
	int size = strlen(ch);
	int i;
	for (i = 0; i < size; i++)
	{
		ch[i] = ch[i] + 48;
	}
	printf("%s", ch);
	getch();
	return 0;
}