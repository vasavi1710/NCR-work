/*command line arguments passed to program are read via CommandLineToArgvW.*/
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<windows.h>
int main(int argc, CHAR *argv[])
{
	LPWSTR *szArgList;
	int no_of_args;
	int i;
	szArgList = CommandLineToArgvW(GetCommandLine(), &no_of_args);
	if (szArgList == NULL || no_of_args<2)
	{
		cout << "szArglist Failed";
	}
	else
	{
		for (i = 0; i < no_of_args; i++)
			wcout << szArgList[i] << endl;
	}
	getchar();
	return 0;
}