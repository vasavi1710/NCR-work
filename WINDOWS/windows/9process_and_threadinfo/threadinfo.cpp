/* creating a child process. Using GetCurrentProcessId, GetCurrentThreadId, GetProcessId, GetThreadId, GetProcessIdOfThread to print process and thread information in each of the process.*/
#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])//COMMAND LINE ARGS
{
	BOOL b_k;//TO STORE BOOLEAN VALUES RETURNEDBY THE CREATE PROCESS
	STARTUPINFO si;//STARTUPINFO PARAMETER IN CREATE PROCESS FOR PROCESS
	PROCESS_INFORMATION pr;//PROCESS INFORMATION FOR PROCESS
	ZeroMemory(&pr, sizeof(pr));//ZEROING THE MEMORY OF PROCESS INFORMATION
	ZeroMemory(&si, sizeof(si));//ZEROING THE MEMORY OF STARTUPINFO
	_SECURITY_ATTRIBUTES SA;//SECURITY ATTRIBUTES FOR PROCESS
	SA.bInheritHandle = TRUE;//TO INHERIT
	si.cb = sizeof(si);//ASSIGNING THE SIZE OF SI1 AS COUNT OF BYTES
	if (argc < 2)
	{
		printf("number of args are less");
		getchar();
		exit(1);
	}
	b_k = CreateProcess(NULL,//APPLICATION NAME
		argv[1],//COMMAND LINE
		NULL,//SA FOR PROCESS
		NULL,//SA FOR THREAD
		TRUE,//BOOL INHERIT
		0,//CREATION FLAGS
		NULL,//ENVIRONMENT
		NULL,//CURRENT DIR
		&si,//STARTUPINFO
		&pr//PROCESS INFO
	);
	if (b_k == 0)
	{
		printf("process creation failed%d", GetLastError());
	}
	else
	{
		
		printf("\nprocess created successfully with process id %d and processhandle %ld\n \n", pr.dwProcessId, pr.hProcess);
		DWORD curr_proc_id = GetCurrentProcessId();
		printf("current process id %d \n", curr_proc_id);
		DWORD curr_thread_id = GetCurrentThreadId();
		printf("current Thread id %d \n", curr_thread_id);
		DWORD get_proc_id = GetProcessId(pr.hProcess);
		printf(" process id %d \n", get_proc_id);
		DWORD get_thread_id = GetThreadId(pr.hThread);
		printf("Thread id  %d \n", get_thread_id);
		DWORD proc_id_of_thread = GetProcessIdOfThread(pr.hThread);
		printf(" process id  %d \n", proc_id_of_thread);
	
	}
	getchar();
	return 0;
}