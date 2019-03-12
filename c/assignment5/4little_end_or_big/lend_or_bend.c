#include <stdio.h>
int main()
{
	int x = 0x45732562;
	char *c = (char*)&x;
	printf("*c is: 0x%x\n", *c);
	if (*c == 0x45)
	{
		printf("Underlying architecture is little endian. \n");
	}
	else
	{
		printf("Underlying architecture is big endian. \n");
	}
	getchar();
	return 0;
}