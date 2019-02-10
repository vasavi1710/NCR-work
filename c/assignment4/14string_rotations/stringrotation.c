#include<stdio.h>
#include <string.h>

int main() {
	char str[20];
	int i, j, k;
	printf("Enter a string : ");
	scanf_s("%s", str);
	for (i = 0; i<strlen(str); i++) {
		printf("\n");
		for (j = i + 1; j<strlen(str); j++)
			printf("%c", str[j]);
		for (k = 0; k <= i; k++)
			printf("%c", str[k]);
	}
	getch();
	return 0;
}