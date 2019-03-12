#include<stdio.h>
struct d
{
	int date;
	int month;
	int year;
};
int get_diff( struct d d1, struct d d2)
{
	int i,j;
	int days=0;
	int y,flag=0;
	for (i = d1.year + 1; i < d2.year; i++)
	{
		y = i;
		flag = 0;
		if ((y / 4 && y / 400) && (!y / 100))	
			flag = 1;
		if (flag == 1)
			days += 366;
		else
			days += 365;
	}
	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
		for (i = d1.month; i <=12; i++)
		{
			days += m[i];
		}
		
		for (j = 1; j < d2.month; j++)
			days += m[j];
		
		days = days - d1.date + d2.date+1;
		if (d1.month <= 2 && ((d1.year / 4 && d1.year / 400) && (!d1.year / 100)))
		{
			days += 1;
		}
		if (d2.month >= 2 && ((d2.year / 4 && d2.year / 400) && (!d2.year / 100)))
		{
			days += 1;
		}
		return days;
}

int main()
{
	struct d d1, d2;
	char *s;
	printf("enter d1 date");
	scanf_s("%d",&d1.date);
	printf("enter d1 month");
	scanf_s("%d", &d1.month);
	printf("enter d1 year");
	scanf_s("%d", &d1.year);
	printf("the entered date is %d-%d-%d", d1.date, d1.month, d1.year);
	printf("\n enter d2 date");
	scanf_s("%d", &d2.date);
	printf("enter  d2 month");
	scanf_s("%d", &d2.month);
	printf("enter d2 year");
	scanf_s("%d", &d2.year);
	printf("the entered date is %d-%d-%d", d2.date, d2.month, d2.year);

	int days= get_diff(d1, d2);
	printf(" \n%d", days);
	getch();
	return 0;
}
