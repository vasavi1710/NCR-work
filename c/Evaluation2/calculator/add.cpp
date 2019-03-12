#include<stdio.h>
extern int operand1, operand2;
int add()
{
	int sum = operand2 + operand1;
	//printf("%d + %d = %d\n", operand1, operand2, sum);
	return sum;
}