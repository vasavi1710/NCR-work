#include<stdio.h>
int main()
{
	long int hex, hn, mn;
	int choice, op, c, n;
	printf("Enter hexadecimal number\n");
	scanf("%x", &hex);
	printf("Enter your choice to carry following operations: 1.One's complement\n 2.Masking\n 3.Shifting\n 4.Exit\n");
	scanf("%d", &choice);
	switch (choice) {
	case 1:

		hn = ~(hex);

		printf("The hexadecimal equvalent of one's complement is %x", hn);

		break;

	case 2:

		printf("Enter which operation you want to undergo: 1.Bitwise And\n 2.Bitwise Exclusive OR\n 3.Bitwise OR\n");

		scanf("%d", &op);

		printf("Enter the number you want to mask with\n");

		scanf("%x", &mn);

		switch (op) {

		case 1:

			hn = (hex & mn);

			printf("The bitwise and operation of given hexa number is %x", hn);

			break;

		case 2:

			hn = (hex ^ mn);

			printf("The bitwise exclusive or operation of given hexa is %x", hn);

			break;

		case 3:

			hn = (hex | mn);

			printf("The bitwise or operation of given number is %x", hn);

			break;

		default:

			printf("Please enter correct operation\n");

			break;

		}

		break;

	case 3:

		printf("Enter which operation you want to undergo: 1.Left Shift\n 2.Right Shift\n");

		scanf("%d", &c);

		printf("Enter number of bits you want to shift\n");

		scanf("%d", &n);

		switch (c) {

		case 1:

			hex = hex << n;

			printf("After left shift the value is %x", hex);

			break;

		case 2:

			hex = hex >> n;

			printf("After right shift the value is %x", hex);

			break;

		default:

			printf("Enter correct option\n");

			break;

		}

		break;

	case 4:

		printf("Exit");

		break;

		//default:

		//printf_s("Please enter valid option\n");

		//break;

	}

	return 0;

}