#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char *, int k, int size);
int main()
{
	char *string;
	char Temporary_Char = ' ';
	int string_size = 0;
	int Size = 2, i = 0;
	printf("ENTER THE STRING \n");
	string = (char *)malloc(sizeof(char));
	while ((Temporary_Char = getc(stdin)) != '\n')
	{
		realloc(string, sizeof(char)*Size);
		string[i] = Temporary_Char;
		Size++;
		i++;
	}
	string[i] = '\0';
	printf("THE STRING ENTERED BY YOU IS: %s", string);
	string_size = i;
	printf("\n OPERATIONS THAT CAN BE PERFORMED ON THE STRING \n 1.REVERSE THE ENTIRE STRING \n 2.REVERSE A SPECIFIC WORD \n 3.REVESE FROM A SPECIFIC INDEX TO SPECIFIC INDEX  \n CHOOSE YOUR OPTION ");
	scanf("%c", &Temporary_Char);
	switch (Temporary_Char)
	{
	case '1':
		reverse(string, 0, string_size - 1);
		printf("\n THE OUTPUT AFTER REVERSING THE ENTIRE STRING IS %s", string);
		break;
	case '2':
		i = 0; int j = 0;
		char Char=' ';
		char end='~';
		char *word, *Temporary_word;
		Temporary_word = (char *)malloc(sizeof(char));
		int word_size = 0;
		int Size=2;
		printf("\n ENTER THE SPECIFIC WORD THAT YOU WANT TO REVERSE IN YOUR STRING  and append ~ at the end of the word");
		word = (char *)malloc(sizeof(char));
		while ((Char = getc(stdin)) != end)
		{
			 realloc(word, sizeof(char)*(Size));
			word[i] = Char;
			//printf("%c",word[i]);
			Size++;
				i++;
		
				
		}
		word[i]='\0';
		word_size=i;
		i = 0;
	//	printf("%s",word);
		//word_size = 2;
		int temp, k = 0;
		while (string[i] != '\n')
		{
			j = 0;
			temp = i;
			realloc(Temporary_word, sizeof(char)*word_size);
			
			while (string[i] != ' ')
			{
				Temporary_word[j] = (string[i]);
				i++;
				j++;
			//	word_size++;
			
			Temporary_word[j] = '\0';
	//	printf("\n%s",Temporary_word);
			if (strcmp(Temporary_word, word) == 0)
			{
				reverse(word, 0, i - 1);
			//	printf("%s",word);
				for (k = temp, i = 0; k <= j; k++, i++)
				{
					strcpy(string[k],word[i]);
				}
				printf("\n AFTER REVERSING A SPECIFIC WORD THE ENTIRE STRING IS %s", string);
				break;
			}
	i++;
		}
			
		}
		printf("\n THE STRING ENTERED IS NOT PRESENT IN THE INPUT STRING");
		break;
	default:printf("entered wrong oaption");
		break;
	}


	return 0;
}

void reverse(char *string, int index, int size)
{
	char temp;
	temp = string[index];
	string[index] = string[size - index];
	string[size - index] = temp;
	if (index == size / 2)
	{
		return;
	}
	reverse(string, index + 1, size);
}
