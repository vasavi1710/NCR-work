#include<stdio.h>
#include<string.h>
int main()
{
	char *s[] = { "we will teach you how to ",
		"Move a mountain ",
		"Level a building ",
		"Erase the past",
		"Make a million " };

	int i = 0, c, j;
	int size = sizeof(s) / 4;
	for (i = 1; i < size; i++)
	{
		char temp[40];
		strcpy(temp,*(s + i));
		c = 0;
		for (j = 0; j < strlen(temp); j++)
		{
			if (temp[j] == 'e')
				c++;
		}
		printf("count of e in %s is %d \n", *(s + i), c);
	}
	getch();
	return 0;
}
