#include<stdio.h>
	int main()
{
	int x = 0xCAFE, y, val;
	if (((x & 0x7) == 0x7) || ((x & 0xB) == 0xB) || ((x & 0xD) == 0xD) || ((x & 0xE) == 0xE) || ((x & 0xF) == 0xF))
		printf("last three bits are on \n");
	y = ((0xFF & x) << 8) | (x >> 8);
	printf("0x%X \n", y);
	val = (x >> 4) | ((x & 0xF) << 12);
	printf("0x%X", val);
	getch();
	return 0;
}


