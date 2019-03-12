#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct country_and_capital

{
	int country_size, capital_length;
	char *country;
	char *capital;
}*s;
int main()
{
	FILE *fptr, *fptr1;
	int no_of_countries = -1;
	fopen_s(&fptr, "country_and_capital.txt", "w");
	if (fptr != NULL)
	{
		printf("\nenter number of countries and their capitals:");
		scanf_s("%d", &no_of_countries);
		s = (struct country_and_capital*)calloc(no_of_countries + 1, sizeof(struct country_and_capital));
		for (int i = 0; i < no_of_countries; i++)
		{
			printf("\nenter size of country name:");
			scanf_s("%d", &(s + i)->country_size);
			int country_size = (s + i)->country_size;
			printf("\nenter country name:");
			(s + i)->country = (char*)calloc((s + i)->country_size + 1, sizeof(char));
			char ch[2];
			gets_s(ch, 1);
			gets_s((s + i)->country, country_size + 1);
			printf("\nenter size of %s capital name:", (s + i)->country);
			scanf_s("%d", &(s + i)->capital_length);
			int capital_length = (s + i)->capital_length;
			printf("\nenter %s's capital name:", (s + i)->country);
			(s + i)->capital = (char*)calloc(capital_length + 1, sizeof(char));
			gets_s(ch, 1);
			gets_s((s + i)->capital, capital_length + 1);
			fprintf(fptr, "%s-%s\n", (s + i)->country, (s + i)->capital);
		}
		fclose(fptr);
	}
else
	{
		printf("error occured");
		exit(1);
	}
	fopen_s(&fptr1, "country_and_capital.txt", "r");
	if (fptr1 != NULL)	
	{
		int choice = -1;
		printf("\nenter the choice:");
		printf("1) determine the capital of a specified country");
		printf("\n2) determine the country whose capital is specified");
		printf("\n3) terminate the programme");
		printf("\nenter your choice:");
		scanf_s("%d", &choice);
		int country_size = -1, capital_size = -1;
		char *country1, *capital1;
		int str_length = 0, flag = 0;
		switch (choice)
		{
		case 1:
					printf("enter size of country name u want to find:");
					scanf_s("%d", &country_size);
					printf("enter country name to find it's capital:");
					country1 = (char*)calloc(country_size + 1, sizeof(char));
					char c[2];
					gets_s(c, 2);
					gets_s(country1, country_size + 1);
					char* str;
					while (!feof(fptr1))
					{
						char ch = fgetc(fptr1);
						if (ch == '\n')
						{
							flag = 0;
							str = (char *)calloc(str_length + 2, sizeof(char));
							fseek(fptr1, -str_length - 2, SEEK_CUR);
							ch = fgetc(fptr1);
							int i = 0;
							while (ch != '\n')
							{
								*(str + i) = ch;
								ch = fgetc(fptr1);
								i++;
							}

						*(str + i) = '\0';
						char *next_token;
						char *token = strtok_s(str, "-", &next_token);
						if (strcmp(country1, token) == 0);
						printf("\nthe capital of country %s is %s", country1, next_token);
						str_length = -1;
						free(str);
						}
					str_length++;
					}
					fclose(fptr1);
					break;

		case 2:

			printf("enter size of capital name u want to find:");
			scanf_s("%d", &capital_size);
			printf("enter capital name to find it's capital:");
			capital1 = (char*)calloc(capital_size + 1, sizeof(char));
			char c1[2];
			gets_s(c1, 2);
			gets_s(capital1, capital_size + 1);
			char* str1;
			while (!feof(fptr1))
			{
				char ch = fgetc(fptr1);
				if (ch == '\n')
				{
					flag = 0;
					str1 = (char *)calloc(str_length + 2, sizeof(char));
					fseek(fptr1, -str_length - 2, SEEK_CUR);
					ch = fgetc(fptr1);
					int i = 0;
					while (ch != '\n')
					{
						*(str1 + i) = ch;
						ch = fgetc(fptr1);
						i++;
					}

					*(str1 + i) = '\0';
					char *next_token;
					char *token = strtok_s(str1, "-", &next_token);
					if (strcmp(capital1, next_token) == 0)
						printf("\nthe country of capital %s is %s", capital1, token);
					str_length = -1;
					free(str1);
				}
				str_length++;

			}
			fclose(fptr1);
		break;

	case 3:
			exit(1);
			break;
	default:		printf("\ninvalid choice");break;

		}

	}
	else
	{
		printf("error occured");
	}
	_getch();
	return 0;
}