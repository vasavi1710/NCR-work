#include<stdio.h>
#include<stdlib.h>
struct s
{
	int a;
	char b;
}svar;
union u
{
	int a;
	char b;
}uvar;
int main()
{
	printf("size of structure var is:%d", sizeof(svar));
	printf("\nsize of union var is:%d", sizeof(uvar));
	getchar();
	return 0;
}