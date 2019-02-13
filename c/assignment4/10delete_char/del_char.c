#include<stdio.h>
int main()
{
	char s1[100],s2[100];
	printf("enter a string");
	scanf_s("%s", s1);
	char ch;
	printf("\n enter the character which you want to delete");
	scanf_s("%c",&ch);
	printf("%c",ch);
	int i,j=0;
	for (i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == ch)

			continue;
		s2[j] = ch;
		j++;
	}
		
	
	s2[j]='\0';
	printf("%s", s2);
	getch();
	return 0;
}
