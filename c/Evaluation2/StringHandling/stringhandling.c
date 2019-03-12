#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void str_copy(char *str1, char *str2,int str1_size,int str2_size);
int str_cmp(char *,char *);//,int str1_len, int str2_len);
int strlen(char *);
void str_cat(char *, char *,int str1_len,int str2_len);
void str_reverse(char *string, int index, int size);
int getString();
char *string2;
int main()
{
	char *string1;
	char Temporary_char = ' ';
	int Size_C = 2, i = 0;
	string1 = (char*)malloc(sizeof(char));
	printf("ENTER A STRING");
	while((Temporary_char=getc(stdin))!='\n')
	{
		realloc(string1, sizeof(char)*Size_C);
		string1[i] = Temporary_char;
		Size_C++;
		i++;
	}
	string1[i] = '\0';
	int string1_len = i;
	int option;
	char ch;
	do
	{
		printf("\n OPERATIONS ON THE STRING: \n 1.STRING REVERSE \n 2.STRING COPY \n 3.STRING CONCAT \n 4.STRING COMPARE \n CHOOSE YOUR OPTION");
		scanf("%d", &option);
		switch (option)
		{
		case 1:		str_reverse(string1, 0, string1_len - 1);
					printf("\n THE OUTPUT AFTER REVERSING THE ENTIRE STRING IS %s", string1);
					break;

		case 2:		printf("ENTER A STRING TO COPY IN STRING1 \n");
					int string2_len = getString();
				//	string2=&string2[1];
					str_copy(string1, string2,string1_len,string2_len);
					string1_len=string2_len;
					printf("AFTER COPY FUNCTION EXECUTION STRING1 IS %s",string1);
					free(string2);
					break;
		case 3:		printf("ENTER A STRING TO CONCAT");
					string2_len=getString();
				//	string2=&string2[1];
					str_cat(string1, string2,string1_len,string2_len);
					string1_len=strlen(string1);
					printf("AFTER CONCAT FUNCTION EXECUTION STRING1 IS %s",string1);
					free(string2);
					break;
		case 4:		printf("ENTER A STRING TO COMPARE");	
					string2_len=getString();
					//string2=&string2[1];
					printf("%s",string2);
					int cmp=str_cmp(string1,string2);//, string1_len, string2_len);
					printf("%d",cmp);
					if (cmp ==-1)
					{
						printf("\n%s is less than  %s", string1, string2);
					}
					else if (cmp ==1)
					{
						printf("\n%s is greater than %s", string1, string2);
					}
					else
						printf("\n%s is equal %s", string1, string2);
						free(string2);
						break;
		default:	break;
		}
		printf("Do you want to continue ? (y/n)\n");
		ch = _getche();

	} while (ch == 'y' || ch == 'Y');
		getchar();
	return 0;
}
void str_copy(char *str1, char *str2,int str1_size,int str2_size)
{
int i = 0;
if(str1_size<str2_size)
{
	realloc(str1, str2_size);
}
for (i = 0; str2[i] != '\0'; ++i) 
{
	str1[i] = str2[i];
}
str1[i] = '\0';
}
/*int str_cmp(char *str1, char *str2,int str1_len,int str2_len)
{
	int i = 0, j = 0;
	while (*(str1 + i) != *(str2 + j))
	{
		i++;
		j++;
	}
	if (i == j)
	{	
		return 0;
	}
else if (*(str2 + i) > *(str1))
	//else if(str1_len>str2_len)
	{	
		return 1;
	}
	return -1;
}*/
int str_cmp(char *str1, char *str2)
{
	int i;
	//printf("%s",string2);
    for ( i = 0; ; i++)
    {
        if (str1[i] != str2[i])
        {
        	//printf("%c %c",string1[i],string2[i]);
        	//int c=((str1[i] < str2[i]) ? (-1) : (1));
            int c;
			if(str1[i]<str2[i])
            {
            	c=-1;
            	return c;
            }
            else
            {
            	c=1;
            	return c;
            }
            
			return c;
        }

        if (str1[i] == '\0')
        {
            return 0;
        }
    }
}
/*int str_cmp( char *X,  char *Y)
{
	printf("%s %s",X,Y);
    while(*X)
    {
        // if characters differ or end of second string is reached
        if (*X != *Y)
            break;
 
        // move to next pair of characters
        X++;
        Y++;
    }
 printf("%c %c\n",*X,*Y);
    // return the ASCII difference after converting char* to unsigned char*
    return (int)*X - (int)*Y;
}
 */
int strlen(char *str1)
{
	int str1_len = 0;
	while (*(str1 + str1_len) != '\0')
	{
		str1_len++;
	}
	return str1_len;
}
void str_cat(char *str1, char *str2,int str1_len,int str2_len)
{
	int len1 = str1_len;
	int len2 = str2_len;
	realloc(str1, len1+len2);
	int j = len1;
	int i;
	for ( i = 0; i < len2; i++,j++)
	{
	*(str1 + j) = *(str2 + i);
	}
	*(str1 + j) = '\0';
}

void str_reverse(char *string, int index, int size)
{
	char temp;
	temp = string[index];
	string[index] = string[size - index];
	string[size - index] = temp;
	if (index == size / 2)
	{
		return;
	}
	str_reverse(string, index + 1, size);
}
int getString()
{
//	char *string2;
	string2 = (char*)malloc(sizeof(char));
	char Temporary_char2 = ' ';
	int Size_C2 = 2, i2 = 0;
	printf("enter ur string  and keep ~ when u reach end of the string\n");
	while ((Temporary_char2 = getc(stdin)) != '~')
	{
		realloc(string2, sizeof(char)*Size_C2);
		string2[i2] = Temporary_char2;
		Size_C2++;
		i2++;
	}
	string2[i2] = '\0';
	return i2;
}
