#include<stdio.h>
#include"header.h"
float operand1, operand2;
int main()
{
	float  result;
	int input;
	char option;

	do
	{
		printf("enter two numbers");
		scanf_s("%f %f", &operand1, &operand2);

		printf("\nEnter 1 for addition:\n ");
		printf("Enter 2 for subtraction:\n ");
		printf("Enter 3 for multiplication:\n ");
		printf("Enter 4 for division:\n ");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1: result = add();
			printf("The addition is : %f\n", result);
			break;

		case 2: result = sub();
			printf("The Substraction is : %f\n", result);
			break;

		case 3: result = mul();
			printf("The Multiplication is : %f\n", result);
			break;

		case 4: result = div();
			if (result != -1)
				printf("The division is : %f\n", result);
			else
				printf("divide by  0");
			break;

		default: printf("wrong input\n");

		}
		printf("Do you want to continue ? (y/n)\n");
		option = getche();

	} while (option == 'y');


	return 0;
}

