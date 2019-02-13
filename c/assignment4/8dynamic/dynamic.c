#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n;
	char a[100];
	char *p[10];
	int K;
	printf_s("enter how many strings you want to enter\n");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
	printf_s("Enter string\n");
	scanf_s("%s", a);
	K= strlen(a) + 1;
	p[i] = (char *)malloc(K* sizeof(char));
	strcpy_s(p[i],K, a);
	}
	printf_s("The strings are\n");
	for (int i = 0; i<n; i++)
		printf_s("%s\n", p[i]);
	free(p);	
	return 0;

}