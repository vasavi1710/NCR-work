#include <stdio.h>
int main()
{
	char s1[20], s2[20];
	int i, j, flag;
	printf("\n Enter first String :  ");
	scanf("%s", s1);
	printf("\n Enter another string  that you want to Search for :  ");
	scanf("%s", s2);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[0])
		{			
			flag = 1;
			for (j = 0; s2[j] != '\0'; j++)
			{
				if (s1[i + j] != s2[j])
				{
					flag = 0;
					break;
				}
			}
		}
	if (flag == 1)
	{
		break;
	}
	}

	if (flag == 0)
	{
	printf("\n Their is no match for  second string in first string %s ", s2);
	}
	else
	{
		printf("\n We found %s at position %d ", s2, i + 1);
	}
return 0;
}