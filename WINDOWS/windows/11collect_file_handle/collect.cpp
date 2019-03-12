#include<stdio.h>
#include<windows.h>
int main(int argc,TCHAR *argv[])
{
	BOOL b_k;//TO STORE BOOLEAN VALUES RETURNEDBY THE CREATE PROCESS
	_PROCESS_INFORMATION pr;//PROCESS INFORMATION FOR PROCESS
	STARTUPINFO si;//STARTUPINFO PARAMETER IN CREATE PROCESS FOR PROCESS
	ZeroMemory(&si, sizeof(si));//ZEROING THE MEMORY OF STARTUPINFO
	si.cb = sizeof(si);// ASSIGNING THE SIZE OF SI AS COUNT OF BYTES
	ZeroMemory(&pr, sizeof(pr));//ZEROING THE MEMORY OF PROCESS INFORMATION
	//LPCWSTR lpApp_Name = L"process_info.exe";//NAME OF THE APPLICATION

	b_k = CreateProcess(NULL,//APP NAME
		argv[1],//CMD LINE ARGS
		NULL,//SECURITY ATTRIBUTES FOR PROCESS
		NULL,//SECURITY ATTRIBUTES FOR THREAD
		FALSE,//BOOL INHERITANCE
		0,//CREATION FLAG
		NULL,//ENVIORNMENT
		NULL,//CURRENT DIRECTORY
		&si,//STARTUPINFO
		&pr//PROCESS INFO
	);
	if (b_k == 0)
	{
		printf("process creation failed %d",GetLastError());
	}
	else
	{
		printf("process created successfully with process id %d", pr.dwProcessId);
		char *buffer;
		buffer = (char *)malloc(sizeof(char)*100);//A BUFFER TO STORE THE CONTENT
		ZeroMemory(buffer, 100);//ZEROING THE MEMORY OF THE BUFFER
		buffer = "hello how r u ? ssup?";//CONTENT TO THE BUFFER
		HANDLE h_file = argv[2];
		BOOL K = WriteFile(h_file,//FILE HANDLER
			buffer,	//LPBUFFER
			strlen(buffer) + 1,//NO OF BYTES TO READ
			NULL,//LP NO OF BYTES WRITTEN
			NULL//LPOVERLAPPED
		);
		int i;
		if (K == 0)
		{
			printf("file write failed");
		}
	}
	getchar();

	return 0;
}
