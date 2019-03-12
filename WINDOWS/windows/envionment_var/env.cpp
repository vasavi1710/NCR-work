#include<iostream>
using namespace std;
#include<windows.h>
int main()
{
	LPTCH GetEnvironmentString();
	//char *str;
	LPWSTR str;
	 str = L"%SystemRoot";
	 LPTSTR  lpDst;
	 ExpandEnvironmentStrings(str,lpDst,100);
	cout << str;
	getchar();
	return 0;
}