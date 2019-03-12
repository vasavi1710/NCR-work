#include<stdio.h>
#define Book(name,author) #name "is written by" #author
#define print(s) printf("cap "#s" = %d",cap##s)

int main()
{
	printf("%s\n",Book(ANSI,SWAMY));
	int cap5 = 50;
	print(5);
	int cap10 = 30;
print(10);
#ifdef Book1
printf(" \nbook is defined");
#else
printf("book1 undefined");
#endif // Book

	getchar();
	return 0;
}

