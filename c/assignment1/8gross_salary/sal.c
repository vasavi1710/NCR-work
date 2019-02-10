#include<stdio.h>
int main()
{
	float sal, hra, da, gross;
	scanf_s("%f", &sal);
	if ((sal >= 1) && (sal <= 4000))
	{
		hra = (10 * sal) / 100;
		da = (50 * sal) / 100;
		gross = sal + hra + da;
	}
	else if ((sal >= 4001) && (sal <= 8000))
	{
		hra = (20 * sal) / 100;
		da = (60 * sal) / 100;
		gross = sal + hra + da;
	}
	else if ((sal >= 8001) && (sal <= 12000))
	{
		hra = (25 * sal) / 100;
		da = (70 * sal) / 100;
		gross = sal + hra + da;
	}
	else
	{
		hra = (30 * sal) / 100;
		da = (80 * sal) / 100;
		gross = sal + hra + da;
	}
	printf("%f is gross salary", gross);
	getch();
	return 0;
}