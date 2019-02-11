#include<stdio.h>
//#include"header"
int main()
{
	
	
	int i;
	char word[100];
	printf("the menu is		1.count different characters, 2.remove the comments, 3.find matching file and rotate and replace it, 4.replace tabs with \t");
	printf("\n select an item from the menu");
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		count(); break;
	case 2:comment(); break;
	case 3:	matching_word(); break;
	case 4:tabs(); break;
	default:printf("the entered test case doesnot exist");
	}
	getch();
	return 0;

}

