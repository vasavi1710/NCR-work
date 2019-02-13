#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void delete_char(char a[50], char c)
{
	int j = 0;
	for (int i = 0; i<strlen(a); i++)
	{
	if (a[i] == c)
	continue;
	a[j++] = a[i];
	}
	a[j] = '\0';
	return;
}
void delete2(char a[50], char b[50])
{
	for (int i = 0; i<strlen(b); i++)
	{
		delete_char(a, b[i]);
	}
	return;
}

int main()
{
	printf("Enter two strings\n");
	char a[50], c, b[50];
	scanf_s("%s", a);
	scanf_s("%s", b);
	delete2(a, b);
	printf("resultant string is\n");
	printf("%s\n", a);
	return 0;
}