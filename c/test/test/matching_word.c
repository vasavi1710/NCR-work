#include"header.h"
#include<stdio.h>
#include<string.h>


void matching_word()
{
	FILE *f;
	fopen_s(&f, "a.txt", "a+");
	FILE *WP;
	fopen_s( &WP,"d.txt", "w+");
	char word[100],ch;
	printf("enter a word to match and rotate");
	scanf_s("%s", word);
	char temp[100];
	int k=strlen(word);
	strcpy_s(temp,k, word);
	_strrev(temp);
	printf("%s",temp);
	int i = 0;
	while (!feof(f))
	{

		ch = fgetc(f);
		if (ch == word[i] )
		{
			ch=fgetc(f);
			while (ch == word[i+1] && (ch!=' '||ch!='\n') )
			{
				fputc(temp[i],WP);
				ch = fgetc(f);
				
				
				i++;
			}
			
		}
		
	//	ch=fgetc(f);
		fputc(ch, WP);

	}
}






















	
