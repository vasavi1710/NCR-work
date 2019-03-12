#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s1[100];
	printf("enter a string to expand\n");
	scanf_s("%s", s1);
	int size = strlen(s1);
	char ch, prev;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (s1[i] == '-')
		{
			if ('a' <= s1[i + 1] <= 'z')
			{
				for (ch = prev; ch <= s1[i + 1]; ch++)
				{
					printf("%c", ch);
				}
			}
			else if ('A' <= s1[i + 1] <= 'Z')
			{
				for (ch = prev; ch <= s1[i + 1]; ch++)
				{
					printf("%c", ch);
				}

			}
			else if (isdigit(s1[i + 1]))
			{
				int l = atoi(s1[i + 1]);
				int f = atoi(prev);
				int m;
				for (m = f; m <= l; m++)
				{
					printf("%d", m);
				}
			}

		}
		else

			prev = s1[i];
	}


getch();
	return 0;
}
