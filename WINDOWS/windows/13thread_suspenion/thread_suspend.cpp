/* program to create a thread in suspended state. Resume the thread after 5 seconds wait. The thread should print integers from 1 to 1000 and return normally. Use getchar() in process’s primary thread to wait for user input and allow time for thread to return.*/
#include<stdio.h>
#include<Windows.h>
DWORD WINAPI Fun_Thread(
	_In_ LPVOID lpParameter
);
DWORD WINAPI Fun_Thread(LPVOID lpParam)
{
	int data;
	data = 1;
	printf("WAITING FOR USER INPUT TO START THE THREAD EXECUTION");
	getchar();
	for (data = 1; data <= 1000; data++)
		printf("\n %d", data);
	printf("thread execution completed successfully");
	return 0;
}
int main()
{
	HANDLE h_thread;
	h_thread = CreateThread(NULL, 0, Fun_Thread, NULL, 0, NULL);
	//SuspendThread(h_thread);
	printf("THREAD IS SLEEPING  AND NOW RESUMED");
	Sleep(5000);
	//WaitForSingleObject(h_thread, 5000);
	
	ResumeThread(h_thread);
	CloseHandle(h_thread);
	getchar();
	return 0;
}