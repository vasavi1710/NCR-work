/*SHORT HAND NOTATION*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char *string;//CHARACTER POINTERTO STOR THE STRING
	char Temporary_Char = ' ';//TEMPORARY CHARACTER
	int Size = 2, i = 0;//SIZE VARIABLE TO ALLOCATE MEMORY FOR STRING
	printf("enter a string to expand\n");
	string = (char *)malloc(sizeof(char));//JUST ALLOCATING MEMORY FOR THE STRING
	while ((Temporary_Char = getc(stdin)) != '\n')//GETTING INPUT FROM THE USER
	{
		realloc(string, sizeof(char)*Size);
		string[i] = Temporary_Char;
		Size++;
		i++;
	}
	string[i] = '\0';//PUTTING NULL AT THE LAST INDEX TO INDICATE END OF THE STRING
	Size = i;//SIZE OF STRING IS IN I
	char ch, prev;//PREV IS PREVIOUS ELEMENT
	for (i = 0; i < Size; i++)//TRAVERSING TILL END OF THE STRING
	{
		if (string[i] != '-')//WHEN ENCOUNTERED OTHER THAN -
		{
			printf("%c", string[i]);//JUST PRINT
		}
		else
		{
			if (string[i + 1] == '-')//WHEN THE STRING CONTAINS MORE THAN ONE - SIDE BY SIDE
			{
				printf("invalid data");
				getchar();
				exit(1);
			}
			if ('a' <= string[i + 1] <= 'z')//IF THE ELEMENT AFTER - ENCOUNTERED IS ALPHABET
			{
				if (isdigit(string[i - 1]) )//IF THE PREV IS DIGIT
				{
					printf("EXPANSION INCLUDES SPECIAL CHARACTERS");
					getchar();
					exit(1);
				}
				if (string[i - 1] > string[i + 1] )//IF DESCENDING EXPANSION
				{
					printf("cannot expanding in descending form ");
					getchar();
					exit(1);
				}
				for (ch = prev + 1; ch < string[i + 1]; ch++)//IF THE EXPANSION IS VALID
				{
					printf("%c", ch);
				}
			}
			else if ('A' <= string[i + 1] <= 'Z')//IF THE STRING[I+1] IS ALPHABET
			{
				if (string[i - 1] > string[i + 1])
				{
					printf("Cannot expand descending form ");
					getchar();
					exit(1);
				}
				for (ch = prev; ch <= string[i + 1]; ch++)
				{
					printf("%c", ch);
				}

		}
			else if (isdigit(string[i + 1]))
			{
				if (string[i - 1] > string[i + 1])
				{
					printf("Cannot expand descending form ");
					getchar();
					exit(1);
				}
				int l = string[i + 1];
				int f = prev;
				int m;
				for (m = f; m <= l; m++)
				{
					printf("%d", m);
				}
			}
		}
		prev = string[i];
	}
	getchar();
	return 0;
}
