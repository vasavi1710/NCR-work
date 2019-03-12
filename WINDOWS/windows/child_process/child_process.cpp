/*create two child processes(say calc.exe and notepad.exe).Print handle and process Id of each child process*/
#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc,TCHAR *argv[])//COMMAND LINE ARGS
{
	BOOL b_k1,b_k2;//TO STORE BOOLEAN VALUES RETURNEDBY THE CREATE PROCESS
	STARTUPINFO si1;//STARTUPINFO PARAMETER IN CREATE PROCESS FOR PROCESS1
	PROCESS_INFORMATION pr1;//PROCESS INFORMATION FOR PROCESS1
	ZeroMemory(&pr1, sizeof(pr1));//ZEROING THE MEMORY OF PROCESS INFORMATION
	ZeroMemory(&si1, sizeof(si1));//ZEROING THE MEMORY OF STARTUPINFO
	_SECURITY_ATTRIBUTES SA1;//SECURITY ATTRIBUTES FOR PROCESS 1
	SA1.bInheritHandle = TRUE;//TO INHERIT
	si1.cb = sizeof(si1);//ASSIGNING THE SIZE OF SI1 AS COUNT OF BYTES
	if (argc < 2)
	{
		printf("number of args are less");
		getchar();
		exit(1);
	}
	b_k1 = CreateProcess(	NULL,//APPLICATION NAME
							argv[1],//COMMAND LINE
							NULL,//SA FOR PROCESS
							NULL,//SA FOR THREAD
							TRUE,//BOOL INHERIT
							0,//CREATION FLAGS
							NULL,//ENVIRONMENT
							NULL,//CURRENT DIR
							&si1,//STARTUPINFO
							&pr1//PROCESS INFO
						);
	if (b_k1 == 0)
	{
		printf("process creation failed%d",GetLastError());
	}
	else
	{
		printf("process1 created successfully with process id %d and processhandle %ld", pr1.dwProcessId,pr1.hProcess);
		
	}
	
	STARTUPINFO si2;//STARTUPINFO PARAMETER IN CREATE PROCESS FOR PROCESS1
	PROCESS_INFORMATION pr2;//PROCESS INFORMATION FOR PROCESS1
	ZeroMemory(&pr2, sizeof(pr2));//ZEROING THE MEMORY OF PROCESS INFORMATION
	ZeroMemory(&si2, sizeof(si2));//ZEROING THE MEMORY OF STARTUPINFO
	
	_SECURITY_ATTRIBUTES SA2;//SECURITY ATTRIBUTES FOR PROCESS 1
	SA2.bInheritHandle = TRUE;//TO INHERIT
	si2.cb = sizeof(si2);

	b_k2 = CreateProcess(	NULL,//APPLICATION NAME
							argv[2],//COMMAND LINE
							NULL,//SA FOR PROCESS
							NULL,//SA FOR THREAD
							TRUE,//BOOL INHERIT
							0,//CREATION FLAGS
							NULL,//ENVIRONMENT
							NULL,//CURRENT DIR
							&si2,//STARTUPINFO
							&pr2//PROCESS INFO
						);
	if (b_k2 == 0)
	{
		printf("process creation failed%d", GetLastError());
	}
	else
	{
		printf("process2 created successfully with process id %d and handle to process is %ld", pr2.dwProcessId,pr2.hProcess);

	}

	getchar();

	return 0;
}
