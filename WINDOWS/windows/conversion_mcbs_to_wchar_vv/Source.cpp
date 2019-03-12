#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	CHAR ch = 'A';
	WCHAR w_ch = L'c';

	printf(" THE CHARCTER STORED IN CH IS %c\n", ch);
	printf(" SIZE OF CHARACTER CH IS %d\n", sizeof(ch));
	printf(" THE WIDECHARACTER STORED IN WCH IS %c\n", w_ch);
	printf(" SIZE OF WIDE CHARACTER WCH IS %d\n", sizeof(w_ch));

	LPSTR c_str;
	CHAR Temporary_Char;
	int Size_C = 2,i=0;
	printf("\nENTER A CHARACTER STRING");
	c_str = (char *)malloc(sizeof(char));
	while ((Temporary_Char=getc(stdin)) != '\n')
	{
		realloc(c_str, sizeof(char)*Size_C);
		c_str[i] = Temporary_Char;
		Size_C++;
		i++;
	}
	c_str[i]='\0';
	printf("\n THE STRING ENTERED BY U IS %s", c_str);
	
	LPWSTR w_str;
	printf("\nENTER A STRING FOR WIDECHAR");
	WCHAR Temporary_WChar;
	int Size_W = 2;
	i = 0;
	printf("\nENTER A CHARACTER STRING");
	w_str = (WCHAR *)malloc(sizeof(WCHAR));
	while ((Temporary_WChar = getc(stdin)) != '\n')
	{
		realloc(c_str, sizeof(char)*Size_W);
		w_str[i] = Temporary_WChar;
		Size_W++;
		i++;
	}
	w_str[i]='\0';
	/*printf(" THE SIZEOF OF STRING CSTR IS %d\n", sizeof(c_str));
	printf("THE SIZEOF STRING WSTR IS %d\n", sizeof(w_str));*/
	printf("IF THE RESULT VALUE IS 0 THEN IT IS NOT UNICODE ELSE IT IS UNICODE\n");
	int r = IsTextUnicode(c_str, strlen(c_str)+1, NULL);
	printf(" CHECKING CSTR IS UNICODE OR NOT %d\n", r);
	r= IsTextUnicode(w_str, wcslen(w_str)+1,NULL);
	printf("CHECKING WSTR IS UNICODE OR NOT %d\n", r);

	int req = MultiByteToWideChar(	CP_UTF8,	//CODE PAGE
									0,			//DWORD FLAGS
									c_str,		//MULTIBYTE STRING
									-1,			//COUNT OF BYTES IN MULTIBYTE(-1 TELLS TO INCLUDE TILL NULL TERMINATOR
									NULL,		//WIDE CHARACTER STRING
									0			//COUNT OF WIDE CHAR CHARACTERS
								);
	if (req == 0)//NUMBER OF CHARACTERS WRITTEN TO THE BUFFER
	{
		printf("\nMULTIBYTE TO WIDECHAR CONVERSION FAILED DUE TO %d",GetLastError());//CONVERSION FAILED
	}
	else
	{
		//printf("%d", req);
		wchar_t * w_new = (wchar_t *)malloc(sizeof(wchar_t)*req);//CREATE NEW WIDE CHAR ARRAY OF  SIZE REQ
		int res = MultiByteToWideChar(	CP_UTF8,	//CODE PAGE
										0,			//DWORD FLAGS
										c_str,		//MULTIBYTE STRING
										-1,			//COUNT OF BYTES IN MULTIBYTE(-1 TELLS TO INCLUDE TILL NULL TERMINATOR
										w_new,		//WIDE CHARACTER STRING
										req			//COUNT OF WIDE CHAR CHARACTERS
									);
		printf("%S\n", w_new);//PRINTING THE NEW WIDE CHAR STRING
		printf("size %d \n", wcslen(w_new)+1);//LENGTH OF THE WIDE CHAR STRING
	}
	req = WideCharToMultiByte(	CP_UTF8, //CODE PAGE
								0,		//DWORD FLAGS
								w_str,	//WIDE CHAR STRING
								-1,		//COUNT OF BYTES IN WIDECHAR STRING
								NULL,	//MULTIBYTE STRING
								0,		//COUNT OF BYTES IN WIDE CHAR STRING
								NULL,	//LP DEFAULT CHARACTER
								NULL	//BOOLEAN LP DEFAULT USED CHAR 
							);
	if (req == 0)//NUMBER OF CHARACTERS WRITTEN TO THE BUFFER
	{
		printf("\nWIDECHAR TO MULTIBYTE CONVERSION FAILED DUE TO %d",GetLastError());//CONVERSION FAILED
	}
	else
	{
		//printf("%d", req);
		CHAR * c_new = (char *)malloc(sizeof(char)*req);//MEMORY ALLOCATION FOR NEW MULTIBYTE STRING
		int res = WideCharToMultiByte(	CP_UTF8, //CODE PAGE
										0,		//DWORD FLAGS
										w_str,	//WIDE CHAR STRING
										-1,		//COUNT OF BYTES IN WIDECHAR STRING
										c_new,	//MULTIBYTE STRING
										req,		//COUNT OF BYTES IN WIDE CHAR STRING
										NULL,	//LP DEFAULT CHARACTER
										NULL	//BOOLEAN LP DEFAULT USED CHAR 
									);
		printf("%s\n", c_new);//PRINTING NEW CHAR STRING
		printf("SIZE %d", strlen(c_new)+1);//LENGTH OF THE CHARACTER STRING
	}
	getchar();
	return 0;
}
