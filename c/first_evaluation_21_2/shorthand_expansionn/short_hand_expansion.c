#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *string;
	char Temporary_Char = ' ';
	int Size = 2,i=0;
	printf("enter a string to expand\n");
	string = (char *)malloc(sizeof(char));
	while ((Temporary_Char = getc(stdin)) != '\n')
	{
		realloc(string, sizeof(char)*Size);
		string[i] = Temporary_Char;
		Size++;
		i++;
	}
	string[i] = '\0';
	Size = i;
	char ch, prev;
	for (i = 0; i < Size; i++)
	{

		if (string[i] != '-')
		{
			printf("%c", string[i]);

		}
		else
		{
			if ('a' <= string[i + 1] <= 'z')
			{
				for (ch = prev + 1; ch < string[i + 1]; ch++)
				{
					printf("%c", ch);
				}
			}
			else if ('A' <= string[i + 1] <= 'Z')
			{
				for (ch = prev; ch <= string[i + 1]; ch++)
				{
					printf("%c", ch);
				}

			}
			else if (isdigit(string[i + 1]))
			{
				int l = atoi(string[i + 1]);
				int f = atoi(prev);
				int m;
				for (m = f; m <= l; m++)
				{
					printf("%d", m);
				}
			}

		}
		
			prev = string[i];
		
	
	}


	getch();
	return 0;
}