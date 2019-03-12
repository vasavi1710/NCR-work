#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int subArrsum(float a[], int size, float sum)
{
	int i, j;
	float curr_sum = 0;
	for (i = 0; i < size; i++) {
		curr_sum = a[i];
		for (j = i + 1; j <=size; j++) {
			if (curr_sum == sum)
			{
				printf("The sum is  found from indices %d and %d", i, j - 1);
				return 1;
			}
			if (curr_sum > sum || j == size)
				break;
			curr_sum = curr_sum + a[j];
		}
	}
	printf("No subarray found\n");
	return 0;
}
int main()
{
	int *array;
		float sum;
		int flag=0;
	int size, i = 0;
	printf("Enter array size\n");
	scanf("%d", &size);
	array = (int *)malloc(sizeof(int)*(size+1));
	printf("Enter array elements as integer or float numbers only  \n");
	for ( i = 0; i <size; i++)
	{
		scanf("%d", &array[i]);
	//	printf("%f", array[i]);
		if(isalpha(array[i]))//	((int)('a')<=(int)array[i]) &&(int)array[i]<='z') //|| ('A' <= array[i] && array[i] <= 'Z') || (array[i] >= 32 && array[i] <= 47) || (array[i] >= 123 && array[i] <= 127) || (array[i] >= 91 && array[i] <= 96) || (array[i] >= 58 && array[i] <= 64))
		{

			printf("invalid data");
			exit(1);
		}
	}
	/*if (flag == 1)
	{
		printf("invalid data");
		exit(1);
	}*/
	/*else*/

	
		printf("Enter your sum \n");
		scanf("%f", &sum);
		subArrsum(array, size, sum);
	
	getch();
	return 0;
}
