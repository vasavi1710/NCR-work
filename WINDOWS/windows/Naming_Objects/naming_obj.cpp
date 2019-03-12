#include<iostream>
using namespace std;
#include<windows.h>
int main()
{
	HANDLE h_event = CreateEventW(	NULL,//EVENT SECURITY ATTRIBUTES
									TRUE,//MANUAL RESET
									TRUE,//INITIAL STATE
									TEXT("HELLO")//EVENT NAME
								);

	getchar();
	return 0;
}