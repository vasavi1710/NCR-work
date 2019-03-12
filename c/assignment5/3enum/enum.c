#include<stdio.h>
struct complex
{
	int real, img;
};
int main()
{
	int k,x,y;
	enum a { add,sub,mul,div,mod};
	struct complex c1, c2, c3;
	printf("enter the real and imaginary values of complex number c1");
	scanf_s("%d %d", &x, &y);
	c1.real = x;
	c1.img = y;
	printf("enter the real and imaginary values of complex number c2");
	scanf_s("%d %d", &x, &y);
	c2.real = x;
	c2.img = y;
	printf("0.add 1.subtract 2.multiplication  choose ur option");
	scanf_s("%d", &k);

	switch (k)
	{
	case add:c3.real = c1.real + c2.real;
		c3.img = c1.img + c2.img;
		printf("result after performing addition is ");
		break;
	case sub:c3.real = c1.real - c2.real;
		c3.img = c1.img - c2.img;
		printf("result after performing subtraction is ");
		break;
	case mul:	c3.real = ((c1.real)*(c2.real)) - ((c1.img)*(c2.img));
		c3.img = ((c1.real)*(c2.img)) + ((c1.real)*(c2.img));
		printf("result after performing multiplication is ");
		break;
	default:printf("entered option is not there"); break;
	}
	printf("%d+%di", c3.real, c3.img);
	getch();
	//System("pause");

	return 0;
}
