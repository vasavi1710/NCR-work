#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
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

	printf("%d", h_file);
	printf("Program1 created successfuly\n");

	getchar();

	return 0;
}
