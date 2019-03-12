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
	printf("hello i am your secondary thread");
	
	//ExitThread(dw_exitcode);
	printf("i have exited successfully");
	return 0;
}
DWORD WINAPI Fun_Thread1(LPVOID lpParam)
{
	HANDLE h_thread2;
	int data;
	data = 1;
	printf("WAITING FOR USER INPUT TO START THE primary THREAD EXECUTION");
	getchar();
	DWORD dw_exitcode = 10;
	for (data = 1; data <= 1000; data++)
		printf("\n %d", data);
	h_thread2 = CreateThread(NULL, 0, Fun_Thread2, NULL, 0, NULL);
	TerminateThread(h_thread2, dw_exitcode);
	printf("thread terminated");
	WaitForSingleObject(h_thread2, INFINITE);
	DWORD lpW;

	GetExitCodeThread(h_thread2, &lpW);
	if (lpW != STILL_ACTIVE)
	{
		printf("thread exited successfully");
	}

	printf("thread execution completed successfully");
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