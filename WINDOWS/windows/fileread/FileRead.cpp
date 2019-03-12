/*open an existing file with CreateFile and use ReadFile to read the contents of file till EOF and print the contents to console*/
#include<iostream>
using namespace std;
#include<windows.h>
#define BUFFERMAXSIZE 50
int main()
{
	LPCWSTR lp_FileName=L"a.txt";//NAME OF THE FILE TO READ
	HANDLE h_file;//HANDLE TO THE FILE
	h_file=CreateFileW(	lp_FileName,	//FILENAME
						GENERIC_READ,	//DWORD ACCESS
						0,				//DW SHARE MODE	
						NULL,			//LP SECURITY ATTRIBUTES
						OPEN_EXISTING,	//DW_CREATION DISPOSITION
						FILE_ATTRIBUTE_NORMAL,//DWFLAGS AND ATTRIBUTES
						NULL			//HANDLE TEMPLATE FILE
					);
	if (h_file == INVALID_HANDLE_VALUE)//HANDLE TO THE FILE IS INVALID
	{
		//printf("%s", h_out);
		printf("FILE READ FAILED");
	}
	else
	{
		char *buffer;
		buffer = (char *)malloc(sizeof(char)*BUFFERMAXSIZE);//A BUFFER TO READ THE CONTENT
		while (1)
		{
			ZeroMemory(buffer, BUFFERMAXSIZE);//ZEROING THE MEMORY OF THE BUFFER
			BOOL K = ReadFile(	h_file,//HANDLE 
								buffer,//LPBUFFER
								BUFFERMAXSIZE,//DWORD NUMBER OF BYTES TO READ
								NULL,//LP NO OF BYTES READ
								NULL//LPOVERLAPPED
							);//READING  CHARACTER FROM THE FILE
			int i;
			if (K&&h_file == 0)//EOF
			{
				printf("\n REACHED END OF THE FILE");
				break;
			}

			else
				printf("%s", buffer);
		}
	}
	getchar();
	return 0;
}