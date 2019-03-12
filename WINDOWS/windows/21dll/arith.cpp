#include"arithmaticop.h"

int add(int nLeft, int nRight)
{
	return (nLeft + nRight);
}
int sub(int nLeft, int nRight)
{
	return nLeft - nRight;
}
int mul(int nLeft, int nRight)
{
	return nLeft * nRight;
}
int divi(int nLeft, int nRight)
{
	return nLeft / nRight;
}
BOOL APIENTRY DllMain(
	HANDLE hModule,	   // Handle to DLL module 
	DWORD ul_reason_for_call,
	LPVOID lpReserved)     // Reserved
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("A process is loading the DLL.");
		// A process is loading the DLL.
		break;

	case DLL_THREAD_ATTACH:
		printf("A process is creating a new thread.");
		// A process is creating a new thread.
		break;

	case DLL_THREAD_DETACH:
		printf("A thread exits normally.");
		// A thread exits normally.
		break;

	case DLL_PROCESS_DETACH:
		printf("A process unloads the DLL.");
		// A process unloads the DLL.
		break;
	}
	return TRUE;
}