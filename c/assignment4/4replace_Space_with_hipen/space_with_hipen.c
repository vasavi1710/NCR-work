#include<stdio.h>
void replace(char a[]);
int main()
{
	char ch[100];
	scanf_s("%[^\n]%*c", ch);

	replace(ch);
		getch();
	return 0;

}
void replace(char a[])
{
	int i = 0;
	char r[100];
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == ' ')
		{
			r[i] = '-';
		}
		else
			r[i] = a[i];
	}
	printf("%s", r);
}