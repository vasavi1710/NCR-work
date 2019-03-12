#include<stdio.h>
#include<windows.h>
#pragma once
#ifdef MY21DLL_EXPORTS   
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif
MYLIBAPI int add(int nLeft, int nRight);
MYLIBAPI int sub(int nLeft, int nRight);
MYLIBAPI int mul(int nLeft, int nRight);
MYLIBAPI int divi(int nLeft, int nRight);

MYLIBAPI BOOL APIENTRY DllMain(
	HANDLE hModule,	   // Handle to DLL module 
	DWORD ul_reason_for_call,
	LPVOID lpReserved);