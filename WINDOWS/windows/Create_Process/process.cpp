#include<stdio.h>
#include<windows.h>
int main()
{
	BOOL b_k;//TO STORE BOOLEAN VALUES RETURNEDBY THE CREATE PROCESS
	_PROCESS_INFORMATION pr;//PROCESS INFORMATION FOR PROCESS
	STARTUPINFO si;//STARTUPINFO PARAMETER IN CREATE PROCESS FOR PROCESS
	ZeroMemory(&si, sizeof(si));//ZEROING THE MEMORY OF STARTUPINFO
	si.cb = sizeof(si);// ASSIGNING THE SIZE OF SI AS COUNT OF BYTES
	ZeroMemory(&pr, sizeof(pr));//ZEROING THE MEMORY OF PROCESS INFORMATION
	LPCWSTR lpApp_Name=L"C://Windows//notepad.exe" ;//NAME OF THE APPLICATION

	b_k = CreateProcessW(	lpApp_Name,//APP NAME
							NULL,//CMD LINE ARGS
							NULL,//SECURITY ATTRIBUTES FOR PROCESS
							NULL,//SECURITY ATTRIBUTES FOR THREAD
							FALSE,//BOOL INHERITANCE
							0,//CREATION FLAG
							NULL,//ENVIORNMENT
							NULL,//CURRENT DIRECTORY
							&si,//STARTUPINFO
							&pr//PROCESS INFO
						);
if(b_k==0)
	{
		printf("process creation failed");
	}
	else
	{
		printf("process created successfully with process id %d", pr.dwProcessId);
	}
	getchar();

	return 0;
}
