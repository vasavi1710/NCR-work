#include<stdio.h>
#include<string.h>

void reverse(char a[], int index, int size);
int main()
{
	char a[100];
	printf("enter a string to reverse");
	scanf_s("%s", a);
	reverse(a,0,strlen(a)-1);

	printf("%s", a);
	getch();
	return 0;
}
void reverse(char a[], int index, int size)
{
	char temp;
	temp = a[index];
	a[index] = a[size - index];
	a[size - index] = temp;
	if (index == size / 2)
	{
		return;
	}
	reverse(a, index + 1, size);
}