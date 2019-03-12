/*create a new file with CreateFile and use WriteFile to write text to file.Verify the written text by manually opening file in notepad / wordpad*/
#include<iostream>
using namespace std;
#include<windows.h>
#define BUFFERMAXSIZE 100
int main()
{
	LPCWSTR lp_FileName = L"a.txt";//NAME OF THE FILE TO WRITE
	HANDLE h_file;//HANDLE TO THE FILE
	h_file = CreateFileW(	lp_FileName,//FILENAME
							GENERIC_WRITE,//DWORD ACCESS
							0,			//DW SHARE MODE	
							NULL,		//LP SECURITY ATTRIBUTES
							CREATE_NEW, //DW_CREATION DISPOSITION
							FILE_ATTRIBUTE_NORMAL,//DWFLAGS AND ATTRIBUTES
							NULL				//HANDLE TEMPLATE FILE
						);
	if (h_file == INVALID_HANDLE_VALUE)//HANDLE TO THE FILE IS INVALID
	{
		//printf("%s", h_out);
		printf("FILE CREATION FAILED");
	}
	else
	{
		char *buffer;
		buffer = (char *)malloc(sizeof(char)*BUFFERMAXSIZE);//A BUFFER TO STORE THE CONTENT
		ZeroMemory(buffer, BUFFERMAXSIZE);//ZEROING THE MEMORY OF THE BUFFER
		buffer = "hello how r u ? ssup?";//CONTENT TO THE BUFFER
	
		BOOL K = WriteFile(	h_file,//FILE HANDLER
							buffer,	//LPBUFFER
							strlen(buffer)+1,//NO OF BYTES TO READ
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