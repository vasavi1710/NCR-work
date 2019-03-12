#include<stdio.h>
struct day
{
	char *time;
}d;
int main()
{
	d.time= __TIME__;
	printf("%s", d.time);
	getchar();
	return 0;
}