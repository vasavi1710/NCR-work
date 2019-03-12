#include"header.h"
#include<stdio.h>
extern float operand1, operand2;
float div()
{
	if (operand2 != 0 && operand1 != 0)
		return operand1 / operand2;
	else
		return -1;
}
