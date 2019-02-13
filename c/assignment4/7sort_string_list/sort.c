#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	printf("number of strings u want to enter");
	scanf_s("%d", &n);
	char arr[25][25];
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf_s("%s", arr[i]);
	}
	char temp[25];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0) {
				strcpy_s(temp, strlen(arr[j]),arr[j]);
				strcpy_s(arr[j], strlen(arr[j+1]), arr[j + 1]);
				strcpy_s(arr[j + 1], strlen(temp), temp);
			}
		}

	}
		for (i = 0; i < n; i++)
		{
			printf("%s\n ", arr[i]);
		}


	getch();
	return 0;
}