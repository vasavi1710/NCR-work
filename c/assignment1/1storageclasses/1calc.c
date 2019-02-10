#include<stdio.h>
#include"header.h"
int main()
{
	float a, b, result;
	int input;
	char option;

	do
	{
		printf("enter two numbers");
		scanf_s("%f %f", &a, &b);

		printf("\nEnter 1 for addition:\n ");
		printf("Enter 2 for subtraction:\n ");
		printf("Enter 3 for multiplication:\n ");
		printf("Enter 4 for division:\n ");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1: result = add(a, b);
			printf("The addition is : %f\n", result);
			break;

		case 2: result = sub(a, b);
			printf("The Substraction is : %f\n", result);
			break;

		case 3: result = mul(a, b);
			printf("The Multiplication is : %f\n", result);
			break;

		case 4: result = div(a, b);
			printf("The division is : %f\n", result);
			break;

		default: printf("wrong input\n");

		}
		printf("Do you want to continue ? (y/n)\n");
		option = getche();

	} while (option == 'y');


	return 0;
}

