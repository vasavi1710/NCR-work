/*program to increment the value of a shared integer by two threads of the same process. Print the final value of shared integer in the process’s primary thread. Print the case when final value of shared integer is inconsistent.*/
#include<stdio.h>
#include<Windows.h>
long int g_data = 1;
DWORD WINAPI Fun_Thread1(_In_ LPVOID lpParameter);
DWORD WINAPI Fun_Thread2(_In_ LPVOID lpParameter);
DWORD WINAPI Fun_Thread1(_In_ LPVOID lpParam)
{
	InterlockedExchangeAdd(&g_data, 1);
	return 0;
}
DWORD WINAPI Fun_Thread2(_In_ LPVOID lpParam)
{
	InterlockedExchangeAdd(&g_data,1);
	//g_data++;
	//	printf(" GLOBAL DATA VALUE IN SECONDARY THREAD IS %d", g_data);
	return 0;
}
//DWORD WINAPI Fun_Thread3(_In_ LPVOID lpParam)
//{
//
//	g_data++;
//	printf(" GLOBAL DATA VALUE IN third THREAD IS %d", g_data);
//	return 0;
//}

int main()
{
	HANDLE h_thread1, h_thread2;// h_thread3;
	HANDLE h_array[2];

	while (1)
	{
		g_data = 0;
		h_thread1 = CreateThread(NULL, 0, Fun_Thread1, NULL, 0, NULL);
		h_thread2 = CreateThread(NULL, 0, Fun_Thread2, NULL, 0, NULL);
		//h_thread3 = CreateThread(NULL, 0, Fun_Thread3, NULL, 0, NULL);
		h_array[0] = h_thread1;
		h_array[1] = h_thread2;
		//h_array[2] = h_thread3;
		WaitForMultipleObjects(2, h_array, TRUE, INFINITE);
		printf("\n GLOBAL DATA VALUE AFTER EXECUTION OF THREADS IS %d", g_data);
		if (g_data == 1)
			break;
	}
	getchar();
	return 0;
}