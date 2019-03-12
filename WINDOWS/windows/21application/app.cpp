#include<stdio.h>
//#include<Windows.h>
#include"E:/NCR-work/WINDOWS/windows/21dll/arithmaticop.h"
int main()
{
		int a=0, b=0, result;
		int input;
		char option;
		do
		{
			printf("enter two numbers");
			scanf_s("%d %d", &a, &b);

			printf("\nEnter 1 for addition:\n ");
			printf("Enter 2 for subtraction:\n ");
			printf("Enter 3 for multiplication:\n ");
			printf("Enter 4 for division:\n ");
			scanf_s("%d", &input);

			switch (input)
			{
			case 1: result = add(a, b);
				printf("The addition is : %d\n", result);
				break;

			case 2: result = sub(a, b);
				printf("The Substraction is : %d\n", result);
				break;

			case 3: result = mul(a, b);
				printf("The Multiplication is : %d\n", result);
				break;

			case 4: result = divi(a, b);
				printf("The division is : %d\n", result);
				break;

			default: printf("wrong input\n");

			}
			printf("Do you want to continue ? (y/n)\n");
			option = getchar();
			getchar();
		} while (option == 'y');


		return 0;
	}

