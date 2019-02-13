#include<stdio.h>
#include<string.h>
int main()
{
	int option;
	char ch[100];
	printf("enter a string");
	scanf_s("%s", ch);
	printf("1.convert to upper 2. convert to lower");
	int size = strlen(ch);
	scanf_s("%d", &option);
	if (option == 2)
	{
		int i;
		for (i = 0; i < size && 'A'<=ch[i]<='Z'; i++)
		{
			ch[i] = ch[i] + 32;
		}
		printf("%s", ch);
	}
	else if (option == 1)
	{
	
			int i;
			for (i = 0; i < size && 'a' <= ch[i] <= 'z'; i++)
			{
				ch[i] = ch[i] - 32;
			}
			printf("%s", ch);
		}
	
else
printf("entered wrong option");
getch();
	return 0;
}