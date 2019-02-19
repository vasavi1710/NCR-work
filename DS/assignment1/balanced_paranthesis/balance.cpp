#include<iostream>
#include<stdlib.h>
using namespace std;
class balance
{
	int top;
	char *s;
	int size;
public:
	balance()
	{
		top = -1;
		s = NULL;
		size = 0;
	}
	bool isFull()
	{
		return(top == size - 1);
	}
	void push(char n)
	{
		if (!isFull())
			(s[++top] = n);
		else
			cout << "stack overflow";
	}
	bool isEmpty()
	{
		return(top == -1);
	}
	char pop()
	{
		int x = ' ';
		if (!isEmpty())
			(x = s[top--]);
		else
			cout << "stack underflow";
		return x;
	}
	char peek()
	{
		char x = ' ';
		if (!isEmpty())
			(x = s[top]);
		else
			cout << "stack underflow";
		return x;
	}
	int bal_fun();
	void get_data()
	{
		s = new char[20];
		cout << "enter the expression";
		cin >> s;
		size = strlen(s);
	}
	~balance()
	{
		delete s;
	}
};
int balance::bal_fun()
{
	int i;
	int flag=0;
	char ch;
	 
		for (i = 0; i<size; i++)
		{
			ch = s[i];
			switch (ch)
			{
			case '(':
			case '[':

			case '{':push(ch);
				break;
			case ')':

			case ']':

			case '}':	
				if (!isEmpty())
				{
					char t;
					t = peek();
					if ((t == '(' && ch == ')') || (t == '[' && ch == ']') || (t == '{' && ch == '}'))
					{
						t = pop();
					}
				}	
				else
					flag = 1;
				break;
			default:break;
			}
		
			if (flag == 1 )
				break;
	}
		if (top == -1 && flag == 0)
			flag = 0;
		else
			flag = 1;
		
	return flag;
}
int main()
{
	balance b1;
	cout << "enter the expression whch u want to check for balanced paranthesis";
	b1.get_data();
int f=	b1.bal_fun();
if (f == 1)
cout << "paranthesis are not balanced in the given expression";
else
cout << "given expession has paranthesis balanced";




	system("pause");
	return 0;
}