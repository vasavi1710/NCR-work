#include<stdio.h>
int subArrsum(int a[], int size, int sum)
{
	int curr_sum, i, j;
	for (i = 0; i < size; i++) {
	curr_sum = a[i];
	for (j = i + 1; j <= size; j++) {
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
	int arr[20], size, sum;
	printf_s("Enter array size\n");
	scanf_s("%d", &size);
	printf_s("Enter array elements\n");
	for (int i = 0; i < size; i++)
		scanf_s("%d", &arr[i]);
	printf_s("Enter your sum\n");
	scanf_s("%d", &sum);
	subArrsum(arr, size, sum);
	getch();
	return 0;
}