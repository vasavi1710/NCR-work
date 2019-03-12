/* program to create a thread in suspended state. Resume the thread after 5 seconds wait. The thread should print integers from 1 to 1000 and return normally. Use getchar() in process’s primary thread to wait for user input and allow time for thread to return.*/
#include<stdio.h>
#include<Windows.h>
DWORD WINAPI Fun_Thread1(
	_In_ LPVOID lpParameter
);

DWORD WINAPI Fun_Thread2(
	_In_ LPVOID lpParameter
);
DWORD WINAPI Fun_Thread2(LPVOID lpParam)
{
	int data;
	data = 1;
	printf(" THREAD 2 WAITING FOR USER INPUT TO START THE THREAD EXECUTION");
	for (data = 1; data <= 10; data++)
		printf("\n %d", data);
	Sleep(5000);
	printf("thread execution completed successfully");
	return 0;
}
DWORD WINAPI Fun_Thread1(LPVOID lpParam)
{
	int data;
	data = 1;
	HANDLE h_thread2;
	h_thread2 = CreateThread(NULL, 0, Fun_Thread2, NULL, 0, NULL);
		printf("\n THREAD ONE %d", data);
		WaitForSingleObject(h_thread2, 1000);
		
	printf("\n funthread execution completed successfully");
	return 0;
}
int main()
{
	HANDLE h_thread;
	h_thread = CreateThread(NULL, 0, Fun_Thread1, NULL, 0, NULL);
	WaitForSingleObject(h_thread, INFINITE);
	CloseHandle(h_thread);
	getchar();
	return 0;
}