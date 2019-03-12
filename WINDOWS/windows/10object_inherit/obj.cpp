#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc,TCHAR *argv[])
{

	LPCWSTR lp_FileName = L"a.txt";//NAME OF THE FILE TO READ
	HANDLE h_file;//HANDLE TO THE FILE
	SECURITY_ATTRIBUTES sa1;
	sa1.bInheritHandle = TRUE;
	sa1.lpSecurityDescriptor = NULL;
	sa1.nLength = sizeof(sa1);
	h_file = CreateFileW(lp_FileName,	//FILENAME
		GENERIC_READ,	//DWORD ACCESS
		0,				//DW SHARE MODE	
		&sa1,			//LP SECURITY ATTRIBUTES
		OPEN_EXISTING,	//DW_CREATION DISPOSITION
		FILE_ATTRIBUTE_NORMAL,//DWFLAGS AND ATTRIBUTES
		NULL			//HANDLE TEMPLATE FILE
	);

	printf("PARENT PROCESS CREATION\n");
	



	//h_file = ReadFileA(filename, NULL, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == h_file)
	{
		_tprintf(_T(" file not created\n"));
		exit(0);
	}
	else
	{
		_tprintf(_T("file created\n"));
		printf("handle:%ld", h_file);
	}
	printf("child process creation\n");
	int check1 = 1;
	STARTUPINFO  sui1;
	PROCESS_INFORMATION pi1;
	ZeroMemory(&sui1, sizeof(sui1));
	ZeroMemory(&pi1, sizeof(pi1));
	sui1.cb = sizeof(sui1);
	BOOL B_H;
	B_H = CreateProcess(NULL,argv[1], NULL,NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &sui1, &pi1);
	if (B_H == 0)
	{
		printf("process1 not created:%d\n", GetLastError());
		getchar(); exit(1);
	}
	else
	{
		printf("process created\n");
	}
	getchar();
	system("pause");
	return 0;
}

