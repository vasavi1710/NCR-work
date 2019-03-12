/*program to create a thread via CreateThread API. Print some message in the thread function*/
#include<stdio.h>
#include<Windows.h>
DWORD WINAPI Fun_Thread(
	_In_ LPVOID lpParameter
);
DWORD WINAPI Fun_Thread(LPVOID lpParam)
{
	int data;
	data = *((int*)lpParam);
	printf("HELLO I AM THREAD %d",data);
	return 0;
}
int main()
{
	HANDLE h_thread;
	int Data_Of_Thread=2;
	h_thread = CreateThread(NULL, 0, Fun_Thread, &Data_Of_Thread, 0, NULL);
	if (h_thread == NULL)
		ExitProcess(Data_Of_Thread);
	
	printf("THREAD EXECUTION COMPLETED SUCCESSFULLY");
	CloseHandle(h_thread);
	getchar();
	return 0;
}